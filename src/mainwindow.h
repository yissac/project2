#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtOpenGL/QGLWidget>
#include <string>
#include "dialog.hpp"
#include "search.hpp"
#include "astargraphsearch.hpp"
#include "offlinefeeder.hpp"
#include "simulator.hpp"
#include "heuristic.hpp"
#include "optimize.h"
#include "simulatedannealing.hpp"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Simulator* getSimulatorPointer();

private slots:
    void on_findButton_clicked();
    void on_loadFileButton_clicked();

    void on_rrtButton_clicked();
    void on_optButton_clicked();
    void on_optButton_2_clicked();

private:
    Ui::MainWindow *ui;

    OfflineFeeder <MechanicalNode>* feeder;
    Search* search;
    Heuristic* heur;
};

#endif // MAINWINDOW_H
