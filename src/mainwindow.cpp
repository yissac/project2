#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    feeder.initializeFeederWithFileName("mechgraph2.xml");
    search.initializeSearchWithFeeder(&feeder);
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
    int initNode = ui->initNodeBox->text().toInt();
    int goalNode = ui->goalNodeBox->text().toInt();

    // Initialize Uninitialized Variables
    ui->simWidget->initializeNetwork(feeder.getMapping());
    search.registerObserver(ui->simWidget);

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
