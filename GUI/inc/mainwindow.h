#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Dev/inc/CrazyCubeSolver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_playButton_clicked();

    void on_solveButton_clicked();


    void on_depthMinInputBox_valueChanged(int val);

    void on_depthMaxInputBox_valueChanged(int val);

    void on_numberOfSolutionsSpinBox_valueChanged(int val);

    void on_LMoveButton_clicked();

    void on_FMoveButton_clicked();

    void on_UMoveButton_clicked();

    void on_UReverseMoveButton_clicked();

    void on_U2MoveButton_clicked();

    void on_MVMoveButton_clicked();

    void on_MHRMoveButton_clicked();

    void on_MHMoveButton_clicked();

    void on_MHLMoveButton_clicked();

    void on_MVFMoveButton_clicked();

    void on_MVBMoveButton_clicked();

    void on_resetButton_clicked();

protected:

private:
    Ui::MainWindow *ui;

//SilnySolver
    CrazyCubeSolver mySolver;
    CrazyCube myCube;

};

#endif // MAINWINDOW_H
