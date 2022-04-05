#include "checklist.h"
#include "ui_checklist.h"

#include "QFile"
#include "QFileDialog"
#include "QSettings" //read ini

checklist::checklist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checklist)
{
    ui->setupUi(this);
}

checklist::~checklist()
{
    delete ui;
}

//兼容性测试
void checklist::on_start_check_clicked()
{
    QSettings *configIni =new QSettings ("./data/core/config.ini",QSettings::IniFormat);
    QString lowest_version=configIni->value("version/lowest").toString();
    if(lowest_version<="2.0.1"){
        ui->checklist_info->setText("兼容性检查通过");;
    }
    else{
        ui->checklist_info->setText("抱歉，您的程序版本不受支持，请考虑更新程序。");
    }

}

