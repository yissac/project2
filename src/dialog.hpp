#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>
#include "rrtsearch.h"

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
public slots:
    void on_solve_clicked();
    void on_find100Nodes_clicked();
    void on_findNode_clicked();

private:
    Ui::Dialog *ui;
    RRTSearch *search;
};

#endif // DIALOG_HPP
