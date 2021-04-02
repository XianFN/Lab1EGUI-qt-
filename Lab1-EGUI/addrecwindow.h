#ifndef ADDRECWINDOW_H
#define ADDRECWINDOW_H

#include <QDialog>

namespace Ui {
class addRecWindow;
}

class addRecWindow : public QDialog
{
    Q_OBJECT

public:
    explicit addRecWindow(QWidget *parent = nullptr);
    ~addRecWindow();

private:
    Ui::addRecWindow *ui;
};

#endif // ADDRECWINDOW_H
