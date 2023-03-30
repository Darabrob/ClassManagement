#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include "addclassdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_classModel = new ClassModel(this);
    ui->tvClasses->setModel(m_classModel);
    ui->tvClasses->setHeaderHidden(true);
    ui->tvClasses->hideColumn(1);
    resetClassModel();

    QObject::connect(ui->pbAddClass, SIGNAL(clicked()),this, SLOT(addClass()));

    connect(ui->tvClasses,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(tvDoubleClicked(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetClassModel()
{
    m_dataHandler.loadClasses();
    m_classModel->setupModelData(m_dataHandler.classes());
    ui->tvClasses->expandAll();
}

void MainWindow::addClass()
{
    AddClassDialog dialog;
    if(dialog.exec()==QDialog::Accepted) {
        QString sDialogYear = dialog.getYear();
        QString sDescription = dialog.getDescription();
        m_dataHandler.addClass(sDialogYear, sDescription);
        resetClassModel();
    }
}

void MainWindow::removeClass()
{

}

void MainWindow::tvDoubleClicked(const QModelIndex &index)
{

}

