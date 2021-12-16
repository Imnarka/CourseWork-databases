#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//подключаем классы для работы с БД
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlRelationalTableModel>
#include <QMessageBox>
#include <login.h>
#include <ui_login.h>
#include <add_record.h>
#include "ui_add_record.h"
#include "print.h"
#include "ui_print.h"
#include "add_owner.h"
#include "ui_add_record.h"
#include "add_apartment.h"
#include "ui_add_apartment.h"
//#include "add_service_provider.h"
//#include "ui_add_service_provider.h"
//#include "add_service.h"
//#include "ui_add_service.h"
#include "report.h"
#include "ui_report.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    login* logwin;
    add_record* addRow;
    add_owner* addOwner;
    add_apartment* addApartment;
//    add_service_provider* addServiceProvider;
//    add_service* addService;
    Print* printDOC;
    report* gen_report;
//    total_sum

//private slots:
//    void on_pushButton_clicked();

private slots:
    void on_action_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void obr_ref_table();

    void obr_ref_owner();

//    void on_tableView_clicked(const QModelIndex &index);

//    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

//    void on_select_table_currentIndexChanged(int index);

    void on_show_owner_clicked();

    void on_show_apartment_clicked();

    void on_show_serv_prov_clicked();

    void on_show_serv_clicked();

    void on_pushButton_6_clicked();

    void on_insert_owner_clicked();

    void on_pushButton_7_clicked();

//    void on_add_serv_provider_clicked();

//    void on_add_services_data_clicked();

//    void on_submit_clicked();

    void on_pushButton_8_clicked();

//    void on_pushButton_9_clicked();

    void on_filter_owner_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:

    Ui::MainWindow *ui;

    //объявляем объект класса QSqlDatabase (обёртка подключения)
    QSqlDatabase db;
    QSqlTableModel* model;
    QSqlTableModel* model_owner;
    QSqlTableModel* model_apartment;
    QSqlTableModel* model_serv_prov;
    QSqlTableModel* model_serv;
    QSqlQueryModel* model_owner_filter;
    QSqlQueryModel* model_apartment_filter;
    QSqlQueryModel* model_owner_filter2;
    QSqlQueryModel* function1;
//    QSqlQuery* query_total;
//    QSqlQueryModel* query_total_model;
};
#endif // MAINWINDOW_H
