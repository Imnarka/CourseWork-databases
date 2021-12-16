#ifndef ADD_RECORD_H
#define ADD_RECORD_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class add_record;
}

class add_record : public QWidget
{
    Q_OBJECT

public:
    explicit add_record(QWidget *parent = nullptr);
    ~add_record();

private slots:
    void on_pushButton_clicked();

signals:
    void refresh_table();

private:
    Ui::add_record *ui;
};

#endif // ADD_RECORD_H
