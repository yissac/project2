#include "dialog.hpp"
#include "ui_dialog.h"

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
    }

}
