#ifndef ADD_SERVICE_PROVIDER_H
#define ADD_SERVICE_PROVIDER_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class add_service_provider;
}

class add_service_provider : public QWidget
{
    Q_OBJECT

public:
    explicit add_service_provider(QWidget *parent = nullptr);
    ~add_service_provider();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_service_provider *ui;
};

#endif // ADD_SERVICE_PROVIDER_H
