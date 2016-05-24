#include "inc/mainwindow.h"
#include "ui_mainwindow.h"
#include "../Dev/inc/CrazyCubeSolver.h"
#include "../Dev/inc/CrazyCubeImproved.h"
#include "../Dev/inc/CrazyCubeMapper.h"


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

void MainWindow::on_playButton_clicked()
{

}

//void MainWindow::on_solveButton_clicked()
//{
////    CrazyCubeImproved impCube;

////     CrazyCubeSolver solver;
////         solver.setCrazyCube(&impCube);

////     const int movesToDo = 12;
////     CrazyCubeImproved::rotation movesMap[movesToDo] = {CrazyCubeImproved::rotation::MIDDLE_VERTICAL_BACK_ROTATION, CrazyCubeImproved::rotation::LEFT, CrazyCubeImproved::rotation::FRONT, CrazyCubeImproved::rotation::MIDDLE_HORIZONTAL_RIGHT_ROTATION, CrazyCubeImproved::rotation::MIDDLE_VERTICAL, CrazyCubeImproved::rotation::MIDDLE_VERTICAL, CrazyCubeImproved::rotation::UP_2, CrazyCubeImproved::rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION, CrazyCubeImproved::rotation::MIDDLE_VERTICAL, CrazyCubeImproved::rotation::UP_INVERTED, CrazyCubeImproved::rotation::MIDDLE_VERTICAL_FRONT_ROTATION, CrazyCubeImproved::rotation::LEFT};
////     for (int i = 0; i < movesToDo; ++i)
////          {
////              impCube.move(movesMap[i]);
////          }

////              solver.setMinDepth(movesToDo-1);
////              solver.setMaxDepth(movesToDo+1);
////              solver.setNumberOfSolutions(3);


////              solver.solve();

//}
