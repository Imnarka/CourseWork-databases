#ifndef ADD_OWNER_H
#define ADD_OWNER_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class add_owner;
}

class add_owner : public QWidget
{
    Q_OBJECT

public:
    explicit add_owner(QWidget *parent = nullptr);
    ~add_owner();

private slots:
    void on_insert_data_owner_clicked();

signals:
    void  refresh_owner();

private:
    Ui::add_owner *ui;
};

#endif // ADD_OWNER_H
