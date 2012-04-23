#ifndef OPTIMIZE_H
#define OPTIMIZE_H

#include <QWidget>
#include "surfex.hpp"
#include <QList>
#include <QTableWidgetItem>

namespace Ui {
class optimize;
}

class optimize : public QWidget
{
    Q_OBJECT
    
public:
    explicit optimize(QWidget *parent = 0);
    ~optimize();

public slots:
    void on_pushMax_clicked();
    void on_pushMin_clicked();
    void on_pushShowMax_clicked();
    void on_pushShowMin_clicked();
    void on_spinVar_valueChanged();

private:
    Ui::optimize *ui;
    Surfex *optimizer;
    QList<QTableWidgetItem> tableContents;
    void showMax();
    void showMin();

};

#endif // OPTIMIZE_H
