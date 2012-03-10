#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    search.registerObserver(ui->simWidget);
}

Simulator* MainWindow::getSimulatorPointer()
{
    return (Simulator*)ui->simWidget;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_findButton_clicked()
{
    ui->simWidget->resetForSearch();
    search.newSearch();

    int initNode = ui->initNodeBox->text().toInt();
    int goalNode = ui->goalNodeBox->text().toInt();

    search.initInitNode(initNode);
    search.initGoalNode(goalNode);
    search.initHeuristic(&heur);

    // Run the algorithm
    Node* solution = search.runSearch();
    if (solution != NULL)
    {
        ui->simWidget->drawSolutionPath(solution);
    }
}

void MainWindow::on_loadFileButton_clicked()
{
    std::string filename = ui->loadFileBox->text().toStdString();

    feeder.initializeFeederWithFileName(filename.c_str());
    search.initializeSearchWithFeeder(&feeder);
    ui->simWidget->initializeNetwork(feeder.getMapping());
}
