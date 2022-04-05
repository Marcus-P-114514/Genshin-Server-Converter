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
    QString cmdexe=QCoreApplication::applicationDirPath()+"/data/core/work.txt";
    QFile file(cmdexe);
    ui->Game_Dir->setReadOnly(false);

    file.open(QFile::WriteOnly | QIODevice::Text);
        QTextStream out(&file);
        out<<ui->Game_Dir->text();
        file.close();

    QString installer_directionary = ui->Installer_Dir->text();
    QString game_directionary = ui->Game_Dir->text();
    QSettings settings("./data/core/config.ini", QSettings::IniFormat);
        settings.beginGroup("location");
        settings.setValue("installer", installer_directionary);
        settings.setValue("game", game_directionary);
        settings.endGroup();
    execute d;
            d.exec();
}
