#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->simWidget->qAppPtr = qApp;
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
    search->newSearch();

    int initNode = ui->initNodeBox->text().toInt();
    int goalNode = ui->goalNodeBox->text().toInt();

    search->initInitNode(initNode);
    search->initGoalNode(goalNode);
    search->initHeuristic(&heur);

    // Run the algorithm
    Node* solution = search->runSearch();
    if (solution != NULL)
    {
        ui->simWidget->drawSolutionPath(solution);
        std::cout << "Solution Found" << std::endl;
    }
    else
        std::cout << "No Solution Exists" << std::endl;
}

void MainWindow::on_loadFileButton_clicked()
{
    std::string filename = ui->loadFileBox->text().toStdString();

    if (!feeder)
        delete feeder;
    if (!search)
        delete search;

    feeder = new OfflineFeeder <MechanicalNode>;
    search = new AStarGraphSearch;

    feeder->initializeFeederWithFileName(filename.c_str());
    search->registerObserver(ui->simWidget);
    search->initializeSearchWithFeeder(feeder);
    ui->simWidget->initializeNetwork(feeder->getMapping());
}

void MainWindow::on_rrtButton_clicked()
{
    static Dialog diag;
    diag.show();
}
