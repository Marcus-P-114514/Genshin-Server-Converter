#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QFile"
#include "QFileDialog"
#include "QSettings" //read ini
#include "execute.h"

#include <QDialog>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class Checklist;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString StrNumConnect (QString Str, int i); //New module: String+Num
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Update_Datapack_Info_clicked();

    void on_Convert_Start_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
