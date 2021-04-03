#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "maincontroler.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_btn1_clicked();
    void fillQlist();
    int getSelectedIndex(string stringSelected);

    void on_actionShopping_List_triggered();

    void on_btnRemove_clicked();

    void on_btnModify_clicked();
signals:
       void editIndexSignal(int i);


private:
    Ui::MainWindow *ui;
    int editIndex =-1;
};
#endif // MAINWINDOW_H
