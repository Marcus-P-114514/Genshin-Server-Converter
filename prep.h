#ifndef PREP_H
#define PREP_H

#include <QWidget>

namespace Ui {
class prep;
}

class prep : public QWidget
{
    Q_OBJECT

public:
    explicit prep(QWidget *parent = nullptr);
    ~prep();

private:
    Ui::prep *ui;
};

#endif // PREP_H
