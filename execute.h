#ifndef EXECUTE_H
#define EXECUTE_H
#include "QFile"
#include "QFileDialog"
#include "QSettings" //read ini

#include <QDialog>

namespace Ui {
class execute;
}

class execute : public QDialog
{
    Q_OBJECT

public:
    explicit execute(QWidget *parent = nullptr);
    ~execute();

private slots:
    void on_Start_exec_clicked();

private:
    Ui::execute *ui;
};

#endif // EXECUTE_H
