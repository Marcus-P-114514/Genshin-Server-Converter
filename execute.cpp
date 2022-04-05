#include "execute.h"
#include "ui_execute.h"
#include "QFile"
#include "QFileDialog"
#include "QSettings" //read ini
#include "QProcess"
#include <QDir>
#include <QList>
#include <QFileInfoList>
#include <QDebug>

execute::execute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::execute)
{
    ui->setupUi(this);
}

execute::~execute()
{
    delete ui;
}

void execute::on_Start_exec_clicked()
{
    //兼容性检查
    ui->StepNum->display(1);
    QSettings *configIni =new QSettings ("./data/core/config.ini",QSettings::IniFormat);
    QString datapack_lowest=configIni->value("version/lowest").toString();
    if(datapack_lowest<="2.0.1"){
        //空包检查
        ui->progress_convert->setValue(25);
        ui->status_exec->setText("完成：空兼容性检查。数据包报告最低异梦版本："+datapack_lowest+"，当前异梦版本2.0.1，通过。");
        ui->StepNum->display(2);
        QSettings *configIni =new QSettings ("./data/core/config.ini",QSettings::IniFormat);
        QString datapack_temp=configIni->value("extra/empty").toString();
        if(datapack_temp=="y"){
            ui->status_exec->setText("错误：数据包是测试时使用的空白数据包，请先更换数据包。您的文件没有被更改 #1");
        }
        else{
            //重命名
            ui->progress_convert->setValue(50);
            ui->status_exec->setText("完成：空包检查；config返回值：n。");
            ui->StepNum->display(3);
            QSettings *configIni =new QSettings ("./data/core/config.ini",QSettings::IniFormat);
            QString datapack_name_default=configIni->value("extra/name_default").toString();
            QString datapack_name_after=configIni->value("extra/name_after").toString();
            QString target_installer=configIni->value("location/installer").toString();
            QString target_game=configIni->value("location/game").toString();


            QDir d1 (target_game);
            d1.rename(datapack_name_default, datapack_name_after);
            ui->status_exec->setText("完成：重命名目录"+datapack_name_default+"，重命名为："+datapack_name_after+"。");

            ui->progress_convert->setValue(75);
            QProcess p(NULL);
            p.setWorkingDirectory("./data/core/");
            QString copyer = "./data/core/copy.cmd";
            p.start(copyer);
            p.waitForFinished();
            ui->progress_convert->setValue(100);
            ui->status_exec->setText("完成");

        }
    }
    else{
        ui->status_exec->setText("错误：转换包不兼容，请考虑更新异梦。 #0");
    }
}

