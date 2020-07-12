/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QtCharts::QChartView *graphicsView_2;
    QtCharts::QChartView *graphicsView_3;
    QtCharts::QChartView *graphicsView_4;
    QtCharts::QChartView *graphicsView;
    QPushButton *Clear_button;
    QDoubleSpinBox *length_box;
    QPushButton *Begin_button;
    QPushButton *Stop_button;
    QDoubleSpinBox *doubleSpinBox_2;
    QSpinBox *num_of_gaps;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1800, 1000);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(160, 70, 231, 201));
        graphicsView_2 = new QtCharts::QChartView(centralwidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(900, 0, 800, 481));
        graphicsView_3 = new QtCharts::QChartView(centralwidget);
        graphicsView_3->setObjectName(QString::fromUtf8("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(0, 500, 800, 400));
        graphicsView_4 = new QtCharts::QChartView(centralwidget);
        graphicsView_4->setObjectName(QString::fromUtf8("graphicsView_4"));
        graphicsView_4->setGeometry(QRect(900, 500, 800, 400));
        graphicsView = new QtCharts::QChartView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 800, 481));
        Clear_button = new QPushButton(centralwidget);
        Clear_button->setObjectName(QString::fromUtf8("Clear_button"));
        Clear_button->setGeometry(QRect(600, 920, 80, 30));
        length_box = new QDoubleSpinBox(centralwidget);
        length_box->setObjectName(QString::fromUtf8("length_box"));
        length_box->setGeometry(QRect(770, 920, 81, 31));
        Begin_button = new QPushButton(centralwidget);
        Begin_button->setObjectName(QString::fromUtf8("Begin_button"));
        Begin_button->setGeometry(QRect(400, 920, 80, 30));
        Stop_button = new QPushButton(centralwidget);
        Stop_button->setObjectName(QString::fromUtf8("Stop_button"));
        Stop_button->setGeometry(QRect(500, 920, 80, 30));
        doubleSpinBox_2 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(910, 920, 81, 31));
        num_of_gaps = new QSpinBox(centralwidget);
        num_of_gaps->setObjectName(QString::fromUtf8("num_of_gaps"));
        num_of_gaps->setGeometry(QRect(241, 920, 101, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(143, 930, 91, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(860, 930, 31, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1000, 930, 31, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Clear_button->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
#if QT_CONFIG(tooltip)
        length_box->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\350\275\254\345\212\250\346\203\257\351\207\217</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Begin_button->setText(QCoreApplication::translate("MainWindow", "Begin", nullptr));
        Stop_button->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
#if QT_CONFIG(tooltip)
        doubleSpinBox_2->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\351\225\277\345\272\246</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("MainWindow", "gaps per circle", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "cm", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "mm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
