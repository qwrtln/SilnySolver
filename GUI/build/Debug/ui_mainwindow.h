/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qopenglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *solveButton;
    QPushButton *playButton;
    QPushButton *moveBackButton;
    QPushButton *moveForwardButton;
    QPushButton *UMoveButton;
    QPushButton *DButton;
    QPushButton *UReverseMoveButton;
    QTextEdit *solutionField;
    QComboBox *solutionComboBox;
    QSpinBox *depthInputBox;
    QLabel *depthInputLabel;
    QOpenGLWidget *VizualizationWidget;
    QPushButton *DReverseButton;
    QPushButton *FButton;
    QPushButton *FReverseButton;
    QPushButton *RandomizeButton;
    QPushButton *pauseButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(724, 471);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        solveButton = new QPushButton(centralWidget);
        solveButton->setObjectName(QStringLiteral("solveButton"));
        solveButton->setGeometry(QRect(330, 370, 75, 23));
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(560, 30, 75, 23));
        moveBackButton = new QPushButton(centralWidget);
        moveBackButton->setObjectName(QStringLiteral("moveBackButton"));
        moveBackButton->setGeometry(QRect(560, 70, 75, 23));
        moveForwardButton = new QPushButton(centralWidget);
        moveForwardButton->setObjectName(QStringLiteral("moveForwardButton"));
        moveForwardButton->setGeometry(QRect(560, 100, 81, 23));
        UMoveButton = new QPushButton(centralWidget);
        UMoveButton->setObjectName(QStringLiteral("UMoveButton"));
        UMoveButton->setGeometry(QRect(560, 150, 75, 23));
        DButton = new QPushButton(centralWidget);
        DButton->setObjectName(QStringLiteral("DButton"));
        DButton->setGeometry(QRect(560, 180, 75, 23));
        UReverseMoveButton = new QPushButton(centralWidget);
        UReverseMoveButton->setObjectName(QStringLiteral("UReverseMoveButton"));
        UReverseMoveButton->setGeometry(QRect(640, 150, 75, 23));
        solutionField = new QTextEdit(centralWidget);
        solutionField->setObjectName(QStringLiteral("solutionField"));
        solutionField->setGeometry(QRect(30, 80, 161, 271));
        solutionComboBox = new QComboBox(centralWidget);
        solutionComboBox->setObjectName(QStringLiteral("solutionComboBox"));
        solutionComboBox->setGeometry(QRect(28, 30, 161, 22));
        depthInputBox = new QSpinBox(centralWidget);
        depthInputBox->setObjectName(QStringLiteral("depthInputBox"));
        depthInputBox->setGeometry(QRect(260, 320, 42, 22));
        depthInputBox->setMaximum(50);
        depthInputLabel = new QLabel(centralWidget);
        depthInputLabel->setObjectName(QStringLiteral("depthInputLabel"));
        depthInputLabel->setGeometry(QRect(220, 330, 47, 13));
        VizualizationWidget = new QOpenGLWidget(centralWidget);
        VizualizationWidget->setObjectName(QStringLiteral("VizualizationWidget"));
        VizualizationWidget->setGeometry(QRect(230, 30, 300, 200));
        DReverseButton = new QPushButton(centralWidget);
        DReverseButton->setObjectName(QStringLiteral("DReverseButton"));
        DReverseButton->setGeometry(QRect(640, 180, 75, 23));
        FButton = new QPushButton(centralWidget);
        FButton->setObjectName(QStringLiteral("FButton"));
        FButton->setGeometry(QRect(560, 210, 75, 23));
        FReverseButton = new QPushButton(centralWidget);
        FReverseButton->setObjectName(QStringLiteral("FReverseButton"));
        FReverseButton->setGeometry(QRect(640, 210, 75, 23));
        RandomizeButton = new QPushButton(centralWidget);
        RandomizeButton->setObjectName(QStringLiteral("RandomizeButton"));
        RandomizeButton->setGeometry(QRect(560, 280, 75, 23));
        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setGeometry(QRect(640, 30, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 724, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        solveButton->setText(QApplication::translate("MainWindow", "Solve", 0));
        playButton->setText(QApplication::translate("MainWindow", "Play", 0));
        moveBackButton->setText(QApplication::translate("MainWindow", "Move Back", 0));
        moveForwardButton->setText(QApplication::translate("MainWindow", "Move Forward", 0));
        UMoveButton->setText(QApplication::translate("MainWindow", "U", 0));
        DButton->setText(QApplication::translate("MainWindow", "D", 0));
        UReverseMoveButton->setText(QApplication::translate("MainWindow", "U'", 0));
        solutionComboBox->clear();
        solutionComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "2", 0)
         << QApplication::translate("MainWindow", "3", 0)
        );
        depthInputLabel->setText(QApplication::translate("MainWindow", "Depth", 0));
        DReverseButton->setText(QApplication::translate("MainWindow", "D'", 0));
        FButton->setText(QApplication::translate("MainWindow", "F", 0));
        FReverseButton->setText(QApplication::translate("MainWindow", "F'", 0));
        RandomizeButton->setText(QApplication::translate("MainWindow", "Randomize", 0));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
