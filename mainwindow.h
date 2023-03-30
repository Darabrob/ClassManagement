#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "classmodel.h"
#include "datahandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    void resetClassModel();

    Ui::MainWindow *ui;
    ClassModel* m_classModel;
    DataHandler m_dataHandler;



   private slots:
    void addClass();
    void removeClass();

    void tvDoubleClicked(const QModelIndex& index);

};
#endif // MAINWINDOW_H
