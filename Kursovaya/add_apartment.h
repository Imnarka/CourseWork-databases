#ifndef ADD_APARTMENT_H
#define ADD_APARTMENT_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class add_apartment;
}

class add_apartment : public QWidget
{
    Q_OBJECT

public:
    explicit add_apartment(QWidget *parent = nullptr);
    ~add_apartment();

private slots:
    void on_add_apartment_button_clicked();

private:
    Ui::add_apartment *ui;
};

#endif // ADD_APARTMENT_H
