#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
using namespace std;

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

void MainWindow::on_actionStatistical_Outlier_Removal_triggered()
{
    system("./3D_viewer /home/llg/dataset/91.ply");
}
