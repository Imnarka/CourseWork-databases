#ifndef REPORT_H
#define REPORT_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <QtAxContainer/QAxObject>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class report;
}

class report : public QWidget
{
    Q_OBJECT

public:
    explicit report(QWidget *parent = nullptr);
    ~report();

private slots:
    void on_pushButton_clicked();

    void on_obzor_clicked();

private:
    Ui::report *ui;
    QSqlDatabase db;
};

#endif // REPORT_H
