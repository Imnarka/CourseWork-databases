#ifndef LOGIN_H
#define LOGIN_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QMessageBox>
#include <QtSql>
#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    QMessageBox *mes;

private slots:
    void on_ConnectDB_clicked();

private:
    Ui::login *ui;
    QSqlDatabase db;
};

#endif // LOGIN_H
