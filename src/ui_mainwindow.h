/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNovy;
    QAction *actionOtvoritSubor;
    QAction *actionUlozitSubor;
    QAction *actionUkoncit;
    QAction *actionPosun;
    QAction *actionSpojenie;
    QAction *actionVypocet;
    QAction *actionKrokvypoctu;
    QAction *actionCislo5;
    QAction *actionScitanie;
    QAction *actionOdcitanie;
    QAction *actionNasobenie;
    QAction *actionDelenie;
    QAction *actionMocnina;
    QAction *actionZmazat;
    QAction *actionReset_vypoctu;
    QAction *actionCislo6;
    QAction *actionCislo7;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuS_bor;
    QMenu *menuBlok;
    QMenu *menuPrida;
    QMenu *menuD_ta;
    QMenu *menuOper_cie;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1312, 858);
        actionNovy = new QAction(MainWindow);
        actionNovy->setObjectName(QStringLiteral("actionNovy"));
        actionNovy->setCheckable(false);
        actionOtvoritSubor = new QAction(MainWindow);
        actionOtvoritSubor->setObjectName(QStringLiteral("actionOtvoritSubor"));
        actionUlozitSubor = new QAction(MainWindow);
        actionUlozitSubor->setObjectName(QStringLiteral("actionUlozitSubor"));
        actionUkoncit = new QAction(MainWindow);
        actionUkoncit->setObjectName(QStringLiteral("actionUkoncit"));
        actionPosun = new QAction(MainWindow);
        actionPosun->setObjectName(QStringLiteral("actionPosun"));
        actionPosun->setCheckable(true);
        actionPosun->setChecked(true);
        actionSpojenie = new QAction(MainWindow);
        actionSpojenie->setObjectName(QStringLiteral("actionSpojenie"));
        actionSpojenie->setCheckable(true);
        actionVypocet = new QAction(MainWindow);
        actionVypocet->setObjectName(QStringLiteral("actionVypocet"));
        actionKrokvypoctu = new QAction(MainWindow);
        actionKrokvypoctu->setObjectName(QStringLiteral("actionKrokvypoctu"));
        actionCislo5 = new QAction(MainWindow);
        actionCislo5->setObjectName(QStringLiteral("actionCislo5"));
        actionScitanie = new QAction(MainWindow);
        actionScitanie->setObjectName(QStringLiteral("actionScitanie"));
        actionOdcitanie = new QAction(MainWindow);
        actionOdcitanie->setObjectName(QStringLiteral("actionOdcitanie"));
        actionNasobenie = new QAction(MainWindow);
        actionNasobenie->setObjectName(QStringLiteral("actionNasobenie"));
        actionDelenie = new QAction(MainWindow);
        actionDelenie->setObjectName(QStringLiteral("actionDelenie"));
        actionMocnina = new QAction(MainWindow);
        actionMocnina->setObjectName(QStringLiteral("actionMocnina"));
        actionZmazat = new QAction(MainWindow);
        actionZmazat->setObjectName(QStringLiteral("actionZmazat"));
        actionReset_vypoctu = new QAction(MainWindow);
        actionReset_vypoctu->setObjectName(QStringLiteral("actionReset_vypoctu"));
        actionCislo6 = new QAction(MainWindow);
        actionCislo6->setObjectName(QStringLiteral("actionCislo6"));
        actionCislo7 = new QAction(MainWindow);
        actionCislo7->setObjectName(QStringLiteral("actionCislo7"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1312, 18));
        menuS_bor = new QMenu(menuBar);
        menuS_bor->setObjectName(QStringLiteral("menuS_bor"));
        menuBlok = new QMenu(menuBar);
        menuBlok->setObjectName(QStringLiteral("menuBlok"));
        menuPrida = new QMenu(menuBlok);
        menuPrida->setObjectName(QStringLiteral("menuPrida"));
        menuD_ta = new QMenu(menuPrida);
        menuD_ta->setObjectName(QStringLiteral("menuD_ta"));
        menuOper_cie = new QMenu(menuPrida);
        menuOper_cie->setObjectName(QStringLiteral("menuOper_cie"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuS_bor->menuAction());
        menuBar->addAction(menuBlok->menuAction());
        menuS_bor->addAction(actionNovy);
        menuS_bor->addSeparator();
        menuS_bor->addAction(actionOtvoritSubor);
        menuS_bor->addAction(actionUlozitSubor);
        menuS_bor->addSeparator();
        menuS_bor->addAction(actionUkoncit);
        menuBlok->addSeparator();
        menuBlok->addAction(menuPrida->menuAction());
        menuBlok->addAction(actionZmazat);
        menuPrida->addAction(menuD_ta->menuAction());
        menuPrida->addAction(menuOper_cie->menuAction());
        menuD_ta->addAction(actionCislo5);
        menuD_ta->addAction(actionCislo6);
        menuD_ta->addAction(actionCislo7);
        menuOper_cie->addAction(actionScitanie);
        menuOper_cie->addAction(actionOdcitanie);
        menuOper_cie->addAction(actionNasobenie);
        menuOper_cie->addAction(actionDelenie);
        menuOper_cie->addAction(actionMocnina);
        mainToolBar->addAction(actionVypocet);
        mainToolBar->addAction(actionKrokvypoctu);
        mainToolBar->addAction(actionReset_vypoctu);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPosun);
        mainToolBar->addAction(actionSpojenie);

        retranslateUi(MainWindow);
        QObject::connect(actionUkoncit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNovy->setText(QApplication::translate("MainWindow", "Nov\303\275", nullptr));
        actionOtvoritSubor->setText(QApplication::translate("MainWindow", "Otvori\305\245", nullptr));
        actionUlozitSubor->setText(QApplication::translate("MainWindow", "Ulo\305\276i\305\245", nullptr));
        actionUkoncit->setText(QApplication::translate("MainWindow", "Ukon\304\215i\305\245", nullptr));
        actionPosun->setText(QApplication::translate("MainWindow", "Posun", nullptr));
        actionSpojenie->setText(QApplication::translate("MainWindow", "Spojenie", nullptr));
        actionVypocet->setText(QApplication::translate("MainWindow", "V\303\275po\304\215et", nullptr));
#ifndef QT_NO_SHORTCUT
        actionVypocet->setShortcut(QApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_NO_SHORTCUT
        actionKrokvypoctu->setText(QApplication::translate("MainWindow", "Krok v\303\275po\304\215tu", nullptr));
        actionCislo5->setText(QApplication::translate("MainWindow", "\304\214\303\255slo 5", nullptr));
        actionScitanie->setText(QApplication::translate("MainWindow", "S\304\215\303\255tanie", nullptr));
        actionOdcitanie->setText(QApplication::translate("MainWindow", "Od\304\215\303\255tanie", nullptr));
        actionNasobenie->setText(QApplication::translate("MainWindow", "N\303\241sobenie", nullptr));
        actionDelenie->setText(QApplication::translate("MainWindow", "Delenie", nullptr));
        actionMocnina->setText(QApplication::translate("MainWindow", "Mocnina", nullptr));
        actionZmazat->setText(QApplication::translate("MainWindow", "Zmaza\305\245", nullptr));
#ifndef QT_NO_SHORTCUT
        actionZmazat->setShortcut(QApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_NO_SHORTCUT
        actionReset_vypoctu->setText(QApplication::translate("MainWindow", "Reset v\303\275po\304\215tu", nullptr));
        actionCislo6->setText(QApplication::translate("MainWindow", "\304\214\303\255slo 6", nullptr));
        actionCislo7->setText(QApplication::translate("MainWindow", "\304\214\303\255slo 7", nullptr));
        menuS_bor->setTitle(QApplication::translate("MainWindow", "S\303\272bor", nullptr));
        menuBlok->setTitle(QApplication::translate("MainWindow", "Bloky", nullptr));
        menuPrida->setTitle(QApplication::translate("MainWindow", "Prida\305\245", nullptr));
        menuD_ta->setTitle(QApplication::translate("MainWindow", "D\303\241ta", nullptr));
        menuOper_cie->setTitle(QApplication::translate("MainWindow", "Oper\303\241cie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
