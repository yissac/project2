#include "dialog.hpp"
#include "ui_dialog.h"
#include <ctime>
#include "searchnode.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    search = new RRTSearch(-400,0,45,
                            400,0,90);
    ui->graphicsView->setScene(search->getScene());
    ui->searchTreeView->setScene(search->getTreeScene());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_findNode_clicked()
{
    if(search->expandTree())
    {
        ui->feedback->setPlainText(QString("Found!\nnumber nodes searched:")+QString::number(search->numNodes()));
    }
    else
    {
        ui->feedback->setPlainText(QString("number nodes searched:")+QString::number(search->numNodes()));
    }

}
void Dialog::on_find100Nodes_clicked()
{

    std::clock_t startTime;
    for(int i = 0; i < 100; i++)
    {
        if(search->expandTree())
        {
            ui->feedback->setPlainText(QString("Found!\nnumber nodes searched:")+QString::number(search->numNodes()));
            break;
        }
        else
        {
            ui->feedback->setPlainText(QString("number nodes searched:")+QString::number(search->numNodes()));
        }
        ui->searchTreeView->scene()->update();
        qApp->processEvents();
        startTime = std::clock();
        while(std::clock() -startTime < 0.5*(double)CLOCKS_PER_SEC);
    }

}
void Dialog::on_solve_clicked()
{
    std::clock_t startTime;
    startTime = std::clock();
    search->solve();
    double diff = ( std::clock() - startTime ) / (double)CLOCKS_PER_SEC;
    double pathDistance = 0;
    SearchNode* node = search->showPredicessor();
    while(node->parent != NULL)
    {
        pathDistance += node->parent->distanceTo(node);
        node = node->parent;
    }
    ui->feedback->setPlainText(QString("Found!\nnumber nodes searched:")
                               +QString::number(search->numNodes())
                               +QString("\nTime(s):")
                               +QString::number(diff)
                               +QString("\nRand Nodes Generated:")
                               +QString::number(search->getNumRandNodes())
                               +QString("\nPath Distance:")
                               +QString::number(pathDistance));
}
void Dialog::on_run_clicked()
{
    clock_t startTime;
    while(NULL != search->showPredicessor())
    {
        ui->searchTreeView->scene()->update();
        qApp->processEvents();
        startTime = std::clock();
        while(std::clock() -startTime < 0.5*(double)CLOCKS_PER_SEC);
    }
}
