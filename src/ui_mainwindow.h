/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Mar 9 19:58:01 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <simulator.hpp>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    Simulator *simWidget;
    QLineEdit *initNodeBox;
    QLineEdit *goalNodeBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *findButton;
    QLineEdit *loadFileNameBox;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1096, 562);
        MainWindow->setFocusPolicy(Qt::NoFocus);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        simWidget = new Simulator(centralWidget);
        simWidget->setObjectName(QString::fromUtf8("simWidget"));
        simWidget->setGeometry(QRect(20, 20, 711, 471));
        simWidget->setFocusPolicy(Qt::StrongFocus);
        initNodeBox = new QLineEdit(centralWidget);
        initNodeBox->setObjectName(QString::fromUtf8("initNodeBox"));
        initNodeBox->setGeometry(QRect(830, 250, 113, 20));
        goalNodeBox = new QLineEdit(centralWidget);
        goalNodeBox->setObjectName(QString::fromUtf8("goalNodeBox"));
        goalNodeBox->setGeometry(QRect(830, 280, 113, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(790, 250, 31, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(790, 280, 31, 16));
        findButton = new QPushButton(centralWidget);
        findButton->setObjectName(QString::fromUtf8("findButton"));
        findButton->setGeometry(QRect(850, 310, 75, 23));
        loadFileNameBox = new QLineEdit(centralWidget);
        loadFileNameBox->setObjectName(QString::fromUtf8("loadFileNameBox"));
        loadFileNameBox->setGeometry(QRect(820, 40, 113, 27));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(770, 20, 101, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1096, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Goal", 0, QApplication::UnicodeUTF8));
        findButton->setText(QApplication::translate("MainWindow", "Find", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Load Network", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
