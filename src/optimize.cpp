#include "optimize.h"
#include "ui_optimize.h"
#include <QTextStream>
#include <QStringList>

optimize::optimize(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::optimize)
{
    ui->setupUi(this);



    optimizer = new Surfex(ui->spinVar->value(),ui->spinMin->value(),ui->spinMax->value(),4);




    optimizer->setCostTolerance(ui->spinTol->value());
    optimizer->setLiveFeed(ui->checkRead->isChecked());
    optimizer->setPrecision(ui->spinTol->value());

    ui->table->setColumnCount(optimizer->getVariableNumber()+1);
    QStringList headers;
    for(int i=0; i<optimizer->getVariableNumber(); i++)
    {
        QString temp;
        QTextStream(&temp) << "Variable " << i+1;
        headers << temp;
    }
    headers << "f(x)";

    ui->table->setHorizontalHeaderLabels(headers);

}

optimize::~optimize()
{
    delete ui;
}

void optimize::on_spinVar_valueChanged()
{
    optimizer->setVariableNumber(ui->spinVar->value());
    ui->table->setColumnCount(optimizer->getVariableNumber()+1);
    QStringList headers;
    for(int i=0; i<optimizer->getVariableNumber(); i++)
    {
        QString temp;
        QTextStream(&temp) << "Variable " << i+1;
        headers << temp;
    }
    headers << "f(x)";

    ui->table->setHorizontalHeaderLabels(headers);
}

void optimize::on_pushShowMax_clicked(){ showMax(); }
void optimize::on_pushShowMin_clicked(){ showMin(); }

void optimize::showMax()
{
    ui->table->clearContents();
    ui->table->setRowCount(optimizer->maxima.size());

    for(int i=0; i<optimizer->maxima.size(); i++)
    {
        if(ui->table->rowCount()<i+1)
            ui->table->insertRow(i);
        for(int j=0; j<optimizer->maxima[i].size(); j++)
        {
            QTableWidgetItem tempItem(0);
            QString tempStr;
            QTextStream(&tempStr) << optimizer->maxima[i][j];
            tempItem.setText(tempStr);
            tableContents.append(tempItem);

            ui->table->setItem(i,j,&tableContents.last());
        }
    }

}

void optimize::showMin()
{
    ui->table->clearContents();
    ui->table->setRowCount(optimizer->minima.size());

    for(int i=0; i<optimizer->minima.size(); i++)
    {
        if(ui->table->rowCount()<i+1)
            ui->table->insertRow(i);
        for(int j=0; j<optimizer->minima[i].size(); j++)
        {
            QTableWidgetItem tempItem(0);
            QString tempStr;
            QTextStream(&tempStr) << optimizer->minima[i][j];
            tempItem.setText(tempStr);
            tableContents.append(tempItem);

            ui->table->setItem(i,j,&tableContents.last());
        }
    }

}

void optimize::on_pushMax_clicked()
{
    optimizer->setCostTolerance(ui->spinTol->value());
    optimizer->setLiveFeed(ui->checkRead->isChecked());
    optimizer->setPrecision(ui->spinTol->value());
    optimizer->setVariableNumber(ui->spinVar->value());
    optimizer->setDefaultDomain(ui->spinMin->value(),ui->spinMax->value(),0);

    optimizer->maximize();

    showMax();
}

void optimize::on_pushMin_clicked()
{
    optimizer->setCostTolerance(ui->spinTol->value());
    optimizer->setLiveFeed(ui->checkRead->isChecked());
    optimizer->setPrecision(ui->spinTol->value());
    optimizer->setVariableNumber(ui->spinVar->value());
    optimizer->setDefaultDomain(ui->spinMin->value(),ui->spinMax->value(),0);

    optimizer->minimize();

    showMin();
}








