#ifndef ADDCLASSDIALOG_H
#define ADDCLASSDIALOG_H

#include <QDialog>

namespace Ui {
class AddClassDialog;
}

class AddClassDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddClassDialog(QWidget *parent = nullptr);
    ~AddClassDialog();

    QString getYear();
    QString getDescription();

private:
    Ui::AddClassDialog *ui;
    void initYears();
};

#endif // ADDCLASSDIALOG_H
