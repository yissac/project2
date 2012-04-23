/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Apr 21 13:18:05 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
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
    QGroupBox *groupBox;
    QPushButton *loadFileButton;
    QPushButton *findButton;
    QLineEdit *initNodeBox;
    QLineEdit *goalNodeBox;
    QLabel *startNodeLabel;
    QLabel *fileNameLabel;
    QLabel *goalNodeLabel;
    QLineEdit *loadFileBox;
    QPushButton *rrtButton;
    QPushButton *optButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(921, 573);
        MainWindow->setFocusPolicy(Qt::NoFocus);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        simWidget = new Simulator(centralWidget);
        simWidget->setObjectName(QString::fromUtf8("simWidget"));
        simWidget->setGeometry(QRect(20, 40, 681, 441));
        simWidget->setFocusPolicy(Qt::StrongFocus);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(720, 40, 161, 201));
        loadFileButton = new QPushButton(groupBox);
        loadFileButton->setObjectName(QString::fromUtf8("loadFileButton"));
        loadFileButton->setGeometry(QRect(30, 60, 75, 23));
        findButton = new QPushButton(groupBox);
        findButton->setObjectName(QString::fromUtf8("findButton"));
        findButton->setGeometry(QRect(30, 170, 75, 23));
        initNodeBox = new QLineEdit(groupBox);
        initNodeBox->setObjectName(QString::fromUtf8("initNodeBox"));
        initNodeBox->setGeometry(QRect(70, 120, 31, 20));
        goalNodeBox = new QLineEdit(groupBox);
        goalNodeBox->setObjectName(QString::fromUtf8("goalNodeBox"));
        goalNodeBox->setGeometry(QRect(70, 150, 31, 20));
        startNodeLabel = new QLabel(groupBox);
        startNodeLabel->setObjectName(QString::fromUtf8("startNodeLabel"));
        startNodeLabel->setGeometry(QRect(30, 120, 31, 16));
        fileNameLabel = new QLabel(groupBox);
        fileNameLabel->setObjectName(QString::fromUtf8("fileNameLabel"));
        fileNameLabel->setGeometry(QRect(30, 20, 61, 16));
        goalNodeLabel = new QLabel(groupBox);
        goalNodeLabel->setObjectName(QString::fromUtf8("goalNodeLabel"));
        goalNodeLabel->setGeometry(QRect(30, 150, 31, 16));
        loadFileBox = new QLineEdit(groupBox);
        loadFileBox->setObjectName(QString::fromUtf8("loadFileBox"));
        loadFileBox->setGeometry(QRect(30, 40, 113, 20));
        rrtButton = new QPushButton(centralWidget);
        rrtButton->setObjectName(QString::fromUtf8("rrtButton"));
        rrtButton->setGeometry(QRect(760, 310, 75, 23));
        optButton = new QPushButton(centralWidget);
        optButton->setObjectName(QString::fromUtf8("optButton"));
        optButton->setGeometry(QRect(760, 350, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 921, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(simWidget, loadFileBox);
        QWidget::setTabOrder(loadFileBox, loadFileButton);
        QWidget::setTabOrder(loadFileButton, initNodeBox);
        QWidget::setTabOrder(initNodeBox, goalNodeBox);
        QWidget::setTabOrder(goalNodeBox, findButton);
        QWidget::setTabOrder(findButton, rrtButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Network Search", 0, QApplication::UnicodeUTF8));
        loadFileButton->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        findButton->setText(QApplication::translate("MainWindow", "Find", 0, QApplication::UnicodeUTF8));
        startNodeLabel->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        fileNameLabel->setText(QApplication::translate("MainWindow", "File Name", 0, QApplication::UnicodeUTF8));
        goalNodeLabel->setText(QApplication::translate("MainWindow", "Goal", 0, QApplication::UnicodeUTF8));
        loadFileBox->setText(QApplication::translate("MainWindow", "../resources/YP3D2.xml", 0, QApplication::UnicodeUTF8));
        rrtButton->setText(QApplication::translate("MainWindow", "RRT", 0, QApplication::UnicodeUTF8));
        optButton->setText(QApplication::translate("MainWindow", "Optimize", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
