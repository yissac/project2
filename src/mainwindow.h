#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtOpenGL/QGLWidget>
#include <string>
#include "search.hpp"
#include "astargraphsearch.hpp"
#include "offlinefeeder.hpp"
#include "simulator.hpp"
#include "heuristic.hpp"

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

private:
    Ui::MainWindow *ui;

    Heuristic heur;
    OfflineFeeder <MechanicalNode>* feeder;
    Search* search;
};

#endif // MAINWINDOW_H
