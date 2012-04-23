/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Fri Apr 20 14:05:22 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *searchTreeView;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *feedback;
    QPushButton *findNode;
    QPushButton *find100Nodes;
    QPushButton *solve;
    QPushButton *run;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(768, 592);
        horizontalLayout = new QHBoxLayout(Dialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        searchTreeView = new QGraphicsView(Dialog);
        searchTreeView->setObjectName(QString::fromUtf8("searchTreeView"));

        verticalLayout_2->addWidget(searchTreeView);

        graphicsView = new QGraphicsView(Dialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout_2->addWidget(graphicsView);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        feedback = new QPlainTextEdit(Dialog);
        feedback->setObjectName(QString::fromUtf8("feedback"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(feedback->sizePolicy().hasHeightForWidth());
        feedback->setSizePolicy(sizePolicy);
        feedback->setMaximumSize(QSize(100, 16777215));

        verticalLayout->addWidget(feedback);

        findNode = new QPushButton(Dialog);
        findNode->setObjectName(QString::fromUtf8("findNode"));

        verticalLayout->addWidget(findNode);

        find100Nodes = new QPushButton(Dialog);
        find100Nodes->setObjectName(QString::fromUtf8("find100Nodes"));

        verticalLayout->addWidget(find100Nodes);

        solve = new QPushButton(Dialog);
        solve->setObjectName(QString::fromUtf8("solve"));

        verticalLayout->addWidget(solve);

        run = new QPushButton(Dialog);
        run->setObjectName(QString::fromUtf8("run"));

        verticalLayout->addWidget(run);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        findNode->setText(QApplication::translate("Dialog", "Find Node", 0, QApplication::UnicodeUTF8));
        find100Nodes->setText(QApplication::translate("Dialog", "Find 100 Nodes", 0, QApplication::UnicodeUTF8));
        solve->setText(QApplication::translate("Dialog", "Solve", 0, QApplication::UnicodeUTF8));
        run->setText(QApplication::translate("Dialog", "Run Solution", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
