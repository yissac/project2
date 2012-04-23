/********************************************************************************
** Form generated from reading UI file 'optimize.ui'
**
** Created: Sun Apr 22 16:26:47 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIMIZE_H
#define UI_OPTIMIZE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_optimize
{
public:
    QPushButton *pushMax;
    QPushButton *pushMin;
    QTableWidget *table;
    QPushButton *pushShowMax;
    QPushButton *pushShowMin;
    QSpinBox *spinTol;
    QLabel *label;
    QCheckBox *checkRead;
    QLabel *label_2;
    QDoubleSpinBox *spinPrec;
    QDoubleSpinBox *spinMin;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *spinMax;
    QLabel *label_6;
    QSpinBox *spinVar;

    void setupUi(QWidget *optimize)
    {
        if (optimize->objectName().isEmpty())
            optimize->setObjectName(QString::fromUtf8("optimize"));
        optimize->resize(723, 442);
        pushMax = new QPushButton(optimize);
        pushMax->setObjectName(QString::fromUtf8("pushMax"));
        pushMax->setGeometry(QRect(30, 8, 75, 23));
        pushMin = new QPushButton(optimize);
        pushMin->setObjectName(QString::fromUtf8("pushMin"));
        pushMin->setGeometry(QRect(120, 8, 75, 23));
        table = new QTableWidget(optimize);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(10, 60, 701, 371));
        pushShowMax = new QPushButton(optimize);
        pushShowMax->setObjectName(QString::fromUtf8("pushShowMax"));
        pushShowMax->setGeometry(QRect(30, 33, 75, 23));
        pushShowMin = new QPushButton(optimize);
        pushShowMin->setObjectName(QString::fromUtf8("pushShowMin"));
        pushShowMin->setGeometry(QRect(120, 33, 75, 23));
        spinTol = new QSpinBox(optimize);
        spinTol->setObjectName(QString::fromUtf8("spinTol"));
        spinTol->setGeometry(QRect(300, 30, 51, 22));
        spinTol->setValue(6);
        label = new QLabel(optimize);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 10, 71, 16));
        checkRead = new QCheckBox(optimize);
        checkRead->setObjectName(QString::fromUtf8("checkRead"));
        checkRead->setGeometry(QRect(620, 10, 91, 17));
        checkRead->setChecked(true);
        label_2 = new QLabel(optimize);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(390, 10, 71, 16));
        spinPrec = new QDoubleSpinBox(optimize);
        spinPrec->setObjectName(QString::fromUtf8("spinPrec"));
        spinPrec->setGeometry(QRect(390, 30, 62, 22));
        spinPrec->setDecimals(4);
        spinPrec->setMaximum(10);
        spinPrec->setSingleStep(0.01);
        spinPrec->setValue(0.01);
        spinMin = new QDoubleSpinBox(optimize);
        spinMin->setObjectName(QString::fromUtf8("spinMin"));
        spinMin->setGeometry(QRect(470, 30, 62, 22));
        spinMin->setDecimals(2);
        spinMin->setMinimum(-1e+09);
        spinMin->setMaximum(1e+09);
        spinMin->setSingleStep(10);
        spinMin->setValue(0);
        label_3 = new QLabel(optimize);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(510, 0, 71, 16));
        label_4 = new QLabel(optimize);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(470, 15, 71, 16));
        label_5 = new QLabel(optimize);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(540, 15, 71, 16));
        spinMax = new QDoubleSpinBox(optimize);
        spinMax->setObjectName(QString::fromUtf8("spinMax"));
        spinMax->setGeometry(QRect(540, 30, 62, 22));
        spinMax->setDecimals(2);
        spinMax->setMinimum(-1e+09);
        spinMax->setMaximum(1e+09);
        spinMax->setSingleStep(10);
        spinMax->setValue(100);
        label_6 = new QLabel(optimize);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(217, 10, 71, 16));
        spinVar = new QSpinBox(optimize);
        spinVar->setObjectName(QString::fromUtf8("spinVar"));
        spinVar->setGeometry(QRect(217, 30, 51, 22));
        spinVar->setValue(2);

        retranslateUi(optimize);

        QMetaObject::connectSlotsByName(optimize);
    } // setupUi

    void retranslateUi(QWidget *optimize)
    {
        optimize->setWindowTitle(QApplication::translate("optimize", "Form", 0, QApplication::UnicodeUTF8));
        pushMax->setText(QApplication::translate("optimize", "Maximize", 0, QApplication::UnicodeUTF8));
        pushMin->setText(QApplication::translate("optimize", "Minimize", 0, QApplication::UnicodeUTF8));
        pushShowMax->setText(QApplication::translate("optimize", "Show Maxima", 0, QApplication::UnicodeUTF8));
        pushShowMin->setText(QApplication::translate("optimize", "Show Minima", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("optimize", "Cost Tolerance", 0, QApplication::UnicodeUTF8));
        checkRead->setText(QApplication::translate("optimize", "Live Read Out", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("optimize", "Precision", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("optimize", "Domain:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("optimize", "Min", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("optimize", "Max", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("optimize", "Variables", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class optimize: public Ui_optimize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIMIZE_H
