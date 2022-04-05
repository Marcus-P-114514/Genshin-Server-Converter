#include "prep.h"
#include "ui_prep.h"

prep::prep(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::prep)
{
    ui->setupUi(this);
}

prep::~prep()
{
    delete ui;
}
