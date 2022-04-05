#include "execute.h"
#include "ui_execute.h"
#include "QFile"
#include "QFileDialog"
#include "QSettings" //read ini

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
        ui->StepNum->display(2);
        QSettings *configIni =new QSettings ("./data/core/config.ini",QSettings::IniFormat);
        QString datapack_temp=configIni->value("extra/empty").toString();
        if(datapack_temp=="y"){
            ui->status_exec->setText("错误：数据包是测试时使用的空白数据包，请先更换数据包。您的文件没有被更改 #1");
        }
        else{

        }
    }
    else{
        ui->status_exec->setText("错误：转换包不兼容，请考虑更新异梦。 #0");
    }
}

