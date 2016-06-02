#include "inc/mainwindow.h"
#include "ui_mainwindow.h"


#include "../Dev/inc/CrazyCubeImproved.h"
#include "../Dev/inc/CrazyCubeSolver.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //prepare solver
    mySolver.setCrazyCube(&myCube);

    mySolver.setMinDepth(0);
    mySolver.setMaxDepth(0);

    mySolver.setNumberOfSolutions(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString translateMove(unsigned short move)
{
    switch(move)
    {
        case 0: return "LEFT ";
        case 1: return "FRONT ";
        case 2: return "UP ";
        case 3: return "UP_INVERTED ";
        case 4: return "UP_2 ";
        case 5: return "MIDDLE_VERTICAL ";
        case 6: return "MIDDLE_HORIZONTAL ";
        case 7: return "MIDDLE_HORIZONTAL_RIGHT_ROTATION ";
        case 8: return "MIDDLE_HORIZONTAL_LEFT_ROTATION ";
        case 9: return "MIDDLE_VERTICAL_FRONT_ROTATION ";
        case 10: return "MIDDLE_VERTICAL_BACK_ROTATION ";
        default: return "";
    }
}



void MainWindow::on_solveButton_clicked()
{



    //myCube.move(CrazyCube::rotation::MIDDLE_VERTICAL_BACK_ROTATION);
    //myCube.move(CrazyCube::rotation::LEFT);


    mySolver.solve();

    vector<vector<unsigned short int> > rozwiazania;
    rozwiazania = mySolver.getSolutions();

    QString solutionText;

    solutionText = "Number of solutions: " + QString::number(rozwiazania.size());

    for (unsigned short int i = 0; i < rozwiazania.size(); ++i)
         {
             for (unsigned short int j = 0; j < rozwiazania[i].size(); ++j)
             {
                 solutionText = solutionText + "\n" + translateMove(rozwiazania[i][j]);
             }

         }


    ui->solutionField->setText(solutionText);
}

void MainWindow::on_playButton_clicked()
{

}




void MainWindow::on_depthMinInputBox_valueChanged(int val)
{
    mySolver.setMinDepth(val);
}

void MainWindow::on_depthMaxInputBox_valueChanged(int val)
{
    mySolver.setMaxDepth(val);
}

void MainWindow::on_numberOfSolutionsSpinBox_valueChanged(int val)
{
    mySolver.setNumberOfSolutions(val);
}

void MainWindow::on_LMoveButton_clicked()
{
    myCube.move(CrazyCube::rotation::LEFT);
}

void MainWindow::on_FMoveButton_clicked()
{
    myCube.move(CrazyCube::rotation::FRONT);
}

void MainWindow::on_UMoveButton_clicked()
{
    myCube.move(CrazyCube::rotation::UP);
}

void MainWindow::on_UReverseMoveButton_clicked()
{
    myCube.move(CrazyCube::rotation::UP_INVERTED);
}

void MainWindow::on_U2MoveButton_clicked()
{
    myCube.move(CrazyCube::rotation::UP_2);
}

void MainWindow::on_MVMoveButton_clicked()
{
    myCube.move(CrazyCube::rotation::MIDDLE_VERTICAL);
}

void MainWindow::on_MHRMoveButton_clicked()
{
    myCube.move(CrazyCube::rotation::MIDDLE_HORIZONTAL_RIGHT_ROTATION);
}

void MainWindow::on_MHMoveButton_clicked()
{
    myCube.move(CrazyCube::rotation::MIDDLE_HORIZONTAL);
}

void MainWindow::on_MHLMoveButton_clicked()
{
    myCube.move(CrazyCube::rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION);
}

void MainWindow::on_MVFMoveButton_clicked()
{
    myCube.move(CrazyCube::rotation::MIDDLE_VERTICAL_FRONT_ROTATION);
}

void MainWindow::on_MVBMoveButton_clicked()
{
    myCube.move(CrazyCube::rotation::MIDDLE_VERTICAL_BACK_ROTATION);
}
