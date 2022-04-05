#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QFileDialog"
#include "QSettings" //read ini

//App_Path=QDir::currentPath();
//Datapack_Info=App_Path+"/data/config.ini";        废案勿用，懒得删了

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Update_Datapack_Info_clicked()
{
    QSettings *configIni =new QSettings ("./data/core/config.ini",QSettings::IniFormat);
    QString datapack_version=configIni->value("basic/version").toString();
    QString datapack_direction=configIni->value("basic/direction").toString();
    ui->Datapack_Version_Display->setText(datapack_version);
    ui->Datapack_Direction_Display->setText(datapack_direction);
}


void MainWindow::on_Convert_Start_clicked()
{
    execute d;
            d.exec();
}
