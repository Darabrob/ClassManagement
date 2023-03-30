#include "addclassdialog.h"
#include "ui_addclassdialog.h"

AddClassDialog::AddClassDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClassDialog)
{
    ui->setupUi(this);
    initYears();
}

AddClassDialog::~AddClassDialog()
{
    delete ui;
}

QString AddClassDialog::getYear()
{
    return ui->cbYears->currentText();
}

QString AddClassDialog::getDescription()
{
    return ui->leClassName->text();
}

void AddClassDialog::initYears()
{
    ui->cbYears->addItem("2021/2022");
    ui->cbYears->addItem("2022/2023");
    ui->cbYears->addItem("2023/2024");
    ui->cbYears->addItem("2024/2025");
}
