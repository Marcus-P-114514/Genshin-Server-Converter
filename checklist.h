#ifndef CHECKLIST_H
#define CHECKLIST_H

#include "prep.h"

#include <QDialog>

namespace Ui {
class checklist;
}

class checklist : public QDialog
{
    Q_OBJECT

public:
    explicit checklist(QWidget *parent = nullptr);
    ~checklist();

private slots:
    void on_start_check_clicked();

    void on_start_prog_clicked();

private:
    Ui::checklist *ui;
};

#endif // CHECKLIST_H
