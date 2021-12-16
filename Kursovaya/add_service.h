#ifndef ADD_SERVICE_H
#define ADD_SERVICE_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class add_service;
}

class add_service : public QWidget
{
    Q_OBJECT

public:
    explicit add_service(QWidget *parent = nullptr);
    ~add_service();

private slots:
    void on_add_data_service_clicked();

private:
    Ui::add_service *ui;
};

#endif // ADD_SERVICE_H
