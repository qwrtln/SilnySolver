#include "inc/mainwindow.h"
#include "ui_mainwindow.h"

#include "../Dev/inc/CrazyCube.h"
#include "../Dev/inc/CrazyCubeImproved.h"
#include "../Dev/inc/CrazyCubeSolver.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
      }
        return "";
 }



void MainWindow::on_solveButton_clicked()
{

    CrazyCubeSolver solver;
    CrazyCube myCube;

    myCube.move(CrazyCube::rotation::MIDDLE_VERTICAL_BACK_ROTATION);
    myCube.move(CrazyCube::rotation::LEFT);

    solver.setCrazyCube(&myCube);

    solver.setMinDepth(1);
    solver.setMaxDepth(3);
    solver.setNumberOfSolutions(1);

    solver.solve();

    vector<vector<unsigned short int> > rozwiazania;
    rozwiazania = solver.getSolutions();

    QString solutionText;

    solutionText = "Number of solutions: " + QString::number(rozwiazania.size());

    for (unsigned short int i = 0; i < rozwiazania.size(); ++i)
         {
             for (unsigned short int j = 0; j < rozwiazania[i].size(); ++j)
             {
                 solutionText = solutionText + "\n" + translateMove(rozwiazania[i][j]);
             }
             //cout << endl;
         }


    ui->solutionField->setText(solutionText);
}

void MainWindow::on_playButton_clicked()
{

}
