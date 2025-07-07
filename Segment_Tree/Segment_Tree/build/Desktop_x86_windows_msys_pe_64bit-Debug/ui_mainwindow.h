/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *inputArray;
    QHBoxLayout *labelsTop;
    QLabel *labelL;
    QLabel *labelR;
    QLabel *labelIndex;
    QLabel *labelValue;
    QHBoxLayout *layoutInputs;
    QSpinBox *inputL;
    QSpinBox *inputR;
    QSpinBox *inputIndex;
    QSpinBox *inputValue;
    QPushButton *buildButton;
    QPushButton *queryButton;
    QPushButton *updateButton;
    QPushButton *deleteButton;
    QPushButton *updateRangeButton;
    QLabel *result;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        inputArray = new QLineEdit(centralwidget);
        inputArray->setObjectName("inputArray");

        verticalLayout->addWidget(inputArray);

        labelsTop = new QHBoxLayout();
        labelsTop->setObjectName("labelsTop");
        labelL = new QLabel(centralwidget);
        labelL->setObjectName("labelL");

        labelsTop->addWidget(labelL);

        labelR = new QLabel(centralwidget);
        labelR->setObjectName("labelR");

        labelsTop->addWidget(labelR);

        labelIndex = new QLabel(centralwidget);
        labelIndex->setObjectName("labelIndex");

        labelsTop->addWidget(labelIndex);

        labelValue = new QLabel(centralwidget);
        labelValue->setObjectName("labelValue");

        labelsTop->addWidget(labelValue);


        verticalLayout->addLayout(labelsTop);

        layoutInputs = new QHBoxLayout();
        layoutInputs->setObjectName("layoutInputs");
        inputL = new QSpinBox(centralwidget);
        inputL->setObjectName("inputL");

        layoutInputs->addWidget(inputL);

        inputR = new QSpinBox(centralwidget);
        inputR->setObjectName("inputR");

        layoutInputs->addWidget(inputR);

        inputIndex = new QSpinBox(centralwidget);
        inputIndex->setObjectName("inputIndex");

        layoutInputs->addWidget(inputIndex);

        inputValue = new QSpinBox(centralwidget);
        inputValue->setObjectName("inputValue");

        layoutInputs->addWidget(inputValue);


        verticalLayout->addLayout(layoutInputs);

        buildButton = new QPushButton(centralwidget);
        buildButton->setObjectName("buildButton");

        verticalLayout->addWidget(buildButton);

        queryButton = new QPushButton(centralwidget);
        queryButton->setObjectName("queryButton");

        verticalLayout->addWidget(queryButton);

        updateButton = new QPushButton(centralwidget);
        updateButton->setObjectName("updateButton");

        verticalLayout->addWidget(updateButton);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");

        verticalLayout->addWidget(deleteButton);

        updateRangeButton = new QPushButton(centralwidget);
        updateRangeButton->setObjectName("updateRangeButton");

        verticalLayout->addWidget(updateRangeButton);

        result = new QLabel(centralwidget);
        result->setObjectName("result");

        verticalLayout->addWidget(result);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        verticalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        labelL->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        labelR->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        labelIndex->setText(QCoreApplication::translate("MainWindow", "\303\215ndice", nullptr));
        labelValue->setText(QCoreApplication::translate("MainWindow", "Valor", nullptr));
        buildButton->setText(QCoreApplication::translate("MainWindow", "Construir", nullptr));
        queryButton->setText(QCoreApplication::translate("MainWindow", "Consultar", nullptr));
        updateButton->setText(QCoreApplication::translate("MainWindow", "Actualizar Elemento", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Eliminar Elemento", nullptr));
        updateRangeButton->setText(QCoreApplication::translate("MainWindow", "Actualizar Rango", nullptr));
        result->setText(QCoreApplication::translate("MainWindow", "Listo", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
