#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QActionGroup>
#include <QDebug> // netreba
#include "blockscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QFileDialog *fileDialog;

    ~MainWindow();


private slots:
    void on_actionOtvoritSubor_triggered();

    void on_actionUlozitSubor_triggered();

    void actionGroupClicked(QAction*action);

    void on_actionZmazat_triggered();

    void on_actionVypocet_triggered();

    void on_actionNovy_triggered();

    void on_actionKrokvypoctu_triggered();

    void on_actionReset_vypoctu_triggered();

    void on_actionScitanie_triggered();

    void on_actionCislo5_triggered();

    void on_actionOdcitanie_triggered();

    void on_actionNasobenie_triggered();

    void on_actionDelenie_triggered();

    void on_actionMocnina_triggered();

    void on_actionCislo6_triggered();

    void on_actionCislo7_triggered();

private:
    Ui::MainWindow *ui;
    BlockScene *scene;
    QGraphicsRectItem *rect;
};

#endif // MAINWINDOW_H
