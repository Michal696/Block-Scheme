// Autori: Vladimír Užík (xuzikv00), Michal Šajdík (xsajdi00)
// Vytvára okno a popisuje reakcie na tlačítka

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "blockscene.h"

#include "blockscitanie.h"
#include "blockcislo5.h"
#include "blockodcitanie.h"
#include "blocknasobenie.h"
#include "blockdelenie.h"
#include "blockmocnina.h"
#include "blockcislo6.h"
#include "blockcislo7.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new BlockScene(this); // vlastna QGraphicsScene

    fileDialog = new QFileDialog(this); // vytvori okno na vyber suboru
    fileDialog->setNameFilter("BlockSchema (*bs)");
    fileDialog->setDefaultSuffix("bs");

    ui->graphicsView->setScene(scene);

    QActionGroup *actionGroup = new QActionGroup(this); // mody Posun a Spojenie, zaruci ze je aktivne iba 1
    actionGroup->addAction(ui->actionSpojenie);
    actionGroup->addAction(ui->actionPosun);
    connect(actionGroup, SIGNAL(triggered(QAction*)),
                this, SLOT(actionGroupClicked(QAction*)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete fileDialog;
    delete scene;
}

/**
 * @brief MainWindow::on_actionOtvoritSubor_triggered Otvori subor, resetne scenu a vytvori novu z dat suboru
 */
void MainWindow::on_actionOtvoritSubor_triggered()
{
    QString filename;

    fileDialog->setAcceptMode(QFileDialog::AcceptOpen); // Typ okna na otvaranie suborov
    if (fileDialog->exec()) {                                   // Zavola okno a ulozi absolutnu cestu k suboru do filename
        QStringList fileNames = fileDialog->selectedFiles();
        if ( fileNames.count() ) {
            filename = fileNames.at(0);
        }
    }
    if (!filename.isEmpty()) { // ak bola cesta ziskana, vytvori novu scenu z dat

        QFile file(filename);

        if( !file.open( QIODevice::ReadOnly ) )
            return;

        QDataStream stream(&file);
        QVariantList list;
        stream >> list;

        BlockArrow::arrowList.clear(); // najprv vycisti scenu
        scene->clear();
        scene->data2scene(list); // potom vytvori novu

        file.close();
    }
}

/**
 * @brief MainWindow::on_actionUlozitSubor_triggered Spracuje scenu a ulozi ju do suboru
 */
void MainWindow::on_actionUlozitSubor_triggered()
{
    QString filename;

    fileDialog->setAcceptMode(QFileDialog::AcceptSave); // Typ okna na ulozenie suborov
    if (fileDialog->exec()) {                           // Zavola okno a ulozi absolutnu cestu k suboru do filename
        QStringList fileNames = fileDialog->selectedFiles();
        if ( fileNames.count() ) {
            filename = fileNames.at(0);
        }
    }

    if (!filename.isEmpty()) { // ak bola cesta ziskana, spracuje scenu a ulozi ju do suboru

        QFile file(filename);

        if( !file.open( QIODevice::WriteOnly ) )
            return;

        QDataStream stream(&file);
        stream << scene->scene2data();

        file.close();
    }

}

/**
 * @brief MainWindow::actionGroupClicked vybere mod Spojenie / Posun
 * @param action
 */
void MainWindow::actionGroupClicked(QAction* action)
{
    if (action == ui->actionSpojenie) {
         scene->setMode(BlockScene::InsertLine);
    } else if (action == ui->actionPosun){
        scene->setMode(BlockScene::MoveItem);
    }

}

/**
 * @brief MainWindow::on_actionZmazat_triggered Zmaze vybrany objekt
 */
void MainWindow::on_actionZmazat_triggered()
{
    foreach (QGraphicsItem *item, scene->selectedItems()) { // iteruje nad vybranymi objektami zo sceny, ak su medzi nimi sipky, zmaze ich
        // treba v pripade ze je naraz vybrana sipka aj blok ktoremu sipka patri
        if (item->type() == BlockArrow::Type) {
            scene->removeItem(item);
            BlockArrow *arrow = qgraphicsitem_cast<BlockArrow *>(item);
            arrow->detachArrow(); // opravi pointer na sipku v portoch
            delete item;
        }
    }

    foreach (QGraphicsItem *item, scene->selectedItems()) { // iteruje na vybranymi objektami zo scene, teraz vybera bloky
        if (item->type() == Block::Type) {
            Block *block = qgraphicsitem_cast<Block *>(item);
            foreach (Port *port, block->inputPorts) { // najprv zmaze vsetky sipky ktore patria bloku
                if (port->arrow != NULL) {
                    scene->removeItem(port->arrow);
                    port->arrow->detachArrow();
                    delete port->arrow;
                }
            }
            foreach (Port *port, block->outputPorts) {
                if (port->arrow != NULL) {
                    scene->removeItem(port->arrow);
                    port->arrow->detachArrow();
                    delete port->arrow;
                }
            }
            scene->removeItem(item); // potom zmaze blok
            delete item;
        }
    }
}

/**
 * @brief MainWindow::on_actionVypocet_triggered Spravi vypocet schemy
 */
void MainWindow::on_actionVypocet_triggered()
{
    if (!scene->checkInputPortsBlocks()) {
        return;
    }
    bool effectiveRun = true;
   int j = 0;
   BlockArrow * link;

   scene->resetAllBlocks();

   // link setting, ensures that all links will be used
   for (QList<BlockArrow *>::Iterator it = BlockArrow::arrowList.begin(); it != BlockArrow::arrowList.end(); it++){
       link = BlockArrow::arrowList.at(j);
       link->notUsed = true;
   }

   do{//repeat search in list until there is no possible development
       effectiveRun = false;

       j = 0;
       //one search, do one link per iteraction
       for (QList<BlockArrow *>::Iterator it = BlockArrow::arrowList.begin(); it != BlockArrow::arrowList.end(); it++){
           link = BlockArrow::arrowList.at(j);

           //link with no use
           if (link->getOutputPort()->hasValue == false){
               qInfo() << "Link Not used";
           }else
               if(link->notUsed){
                   // set value to correct port + hasValue
                   if (link->getInputBlock()->inputPorts.at(0)->hasValue == false){
                       qInfo() << j << (link->getInputBlock()->inputPorts.at(0)->value = link->getOutputPort()->value);
                       link->getInputBlock()->inputPorts.at(0)->hasValue = true;
                   }
                   else{
                       qInfo() << j << (link->getInputBlock()->inputPorts.at(1)->value = link->getOutputPort()->value);
                       link->getInputBlock()->inputPorts.at(1)->hasValue = true;
                   }
                   //link deactivation
                   link->notUsed = false;
                   // if no link used it is not effective run anymore
                   effectiveRun = true;

                   //block  got 2 input -> doing operation, and setting to used
                   if (link->getInputBlock()->outputPorts.at(0)->hasValue == false)
                       if (link->getInputBlock()->inputPorts.at(0)->hasValue == true && link->getInputBlock()->inputPorts.at(1)->hasValue == true){
                           link->getInputBlock()->doOperation();
                           //link->getInputBlock()->outputPorts.at(0)->value = link->getInputBlock()->inputPorts.at(0)->value + link->getInputBlock()->inputPorts.at(1)->value ;

                           link->getInputBlock()->outputPorts.at(0)->hasValue = true;

                           //debug
                           qInfo() << "result:" <<link->getInputBlock()->outputPorts.at(0)->value;
                           //debug
                       }
               }
               //debug
               else{
                    qInfo() << "Link already used";
               }
               //debug
          j++;
       }
   }while(effectiveRun);



}

/**
 * @brief MainWindow::on_actionNovy_triggered Vycisti scenu
 */
void MainWindow::on_actionNovy_triggered()
{
    BlockArrow::arrowList.clear();
    scene->clear();
}

/**
 * @brief MainWindow::on_actionKrokvypoctu_triggered
 */
void MainWindow::on_actionKrokvypoctu_triggered()
{
    // jeden krok vypoctu
    if (!scene->checkInputPortsBlocks()) {
        return;
    }
   int j = 0;
   static BlockArrow * lastLink = NULL;
   static BlockArrow * link;
   for (QList<BlockArrow *>::Iterator it = BlockArrow::arrowList.begin(); it != BlockArrow::arrowList.end(); it++){
       if (lastLink){
            lastLink->getInputBlock()->toggleHighlight();
            lastLink = NULL;
       }
       link = BlockArrow::arrowList.at(j);

       //link with no use
       if (link->getOutputPort()->hasValue == false){
           qInfo() << "Link Not used";

       }else{


           if(link->notUsed){
               // set value to correct port + hasValue
               if (link->getInputBlock()->inputPorts.at(0)->hasValue == false){
                   qInfo() << j << (link->getInputBlock()->inputPorts.at(0)->value = link->getOutputPort()->value);
                   link->getInputBlock()->inputPorts.at(0)->hasValue = true;
               }
               else{
                   qInfo() << j << (link->getInputBlock()->inputPorts.at(1)->value = link->getOutputPort()->value);
                   link->getInputBlock()->inputPorts.at(1)->hasValue = true;
               }

               //link deactivation
               link->notUsed = false;
               //block  got 2 input -> doing operation, and setting to used
               if (link->getInputBlock()->outputPorts.at(0)->hasValue == false)
                   if (link->getInputBlock()->inputPorts.at(0)->hasValue == true && link->getInputBlock()->inputPorts.at(1)->hasValue == true){
   //                    if(lastLink!=NULL)
   //                        lastLink->getInputBlock()->toggleHighlight();
                       link->getInputBlock()->toggleHighlight();
                       link->getInputBlock()->doOperation();



                       link->getInputBlock()->outputPorts.at(0)->hasValue = true;

                       //debug
                       qInfo() << "result:" <<link->getInputBlock()->outputPorts.at(0)->value;
                       //debug
                       lastLink = link;
                       break;
                   }
           }
           //debug
           else{
                qInfo() << "Link already used";
           }
           //debug
       }
       j++;
   }


}

/**
 * @brief MainWindow::on_actionReset_vypoctu_triggered Uvedie scenu do stavu pred vypoctom
 */
void MainWindow::on_actionReset_vypoctu_triggered()
{
    scene->resetAllBlocks();
}

/**
 * @brief MainWindow::on_actionScitanie_triggered prida blok s operaciou scitanie
 */
void MainWindow::on_actionScitanie_triggered()
{
    scene->addItem(new BlockScitanie());
}

/**
 * @brief MainWindow::on_actionOdcitanie_triggered prida blok s operaciou odcitanie
 */
void MainWindow::on_actionOdcitanie_triggered()
{
    scene->addItem(new BlockOdcitanie());
}

/**
 * @brief MainWindow::on_actionNasobenie_triggered prida blok s operaciou nasobenie
 */
void MainWindow::on_actionNasobenie_triggered()
{
    scene->addItem(new BlockNasobenie());
}

/**
 * @brief MainWindow::on_actionDelenie_triggered prida blok s operaciou delenie
 */
void MainWindow::on_actionDelenie_triggered()
{
    scene->addItem(new BlockDelenie());
}

/**
 * @brief MainWindow::on_actionMocnina_triggered prida blok s operaciou mocnina
 */
void MainWindow::on_actionMocnina_triggered()
{
    scene->addItem(new BlockMocnina());
}

/**
 * @brief MainWindow::on_actionCislo5_triggered prida blok s cislom 5
 */
void MainWindow::on_actionCislo5_triggered()
{
    scene->addItem(new BlockCislo5());
}

/**
 * @brief MainWindow::on_actionCislo6_triggered prida blok s cislom 6
 */
void MainWindow::on_actionCislo6_triggered()
{
    scene->addItem(new BlockCislo6());
}

/**
 * @brief MainWindow::on_actionCislo7_triggered prida blok s cislom 7
 */
void MainWindow::on_actionCislo7_triggered()
{
     scene->addItem(new BlockCislo7());
}
