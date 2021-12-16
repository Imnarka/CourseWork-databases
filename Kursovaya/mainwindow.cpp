#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <login.h>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    login *login_window = new login();
    login_window ->show();
}


void MainWindow::on_pushButton_clicked()
{
    model = new QSqlTableModel(this, db);
    model->setEditStrategy((QSqlTableModel::OnFieldChange));
    model->setTable("pay");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void MainWindow::on_show_owner_clicked()
{
    model_owner = new QSqlTableModel(this, db);
    model_owner->setEditStrategy((QSqlTableModel::OnFieldChange));
    model_owner->setTable("owner");
    model_owner->select();

    ui->tableView->setModel(model_owner);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


void MainWindow::on_show_apartment_clicked()
{
    model_apartment = new QSqlTableModel(this, db);
    model_apartment->setEditStrategy((QSqlTableModel::OnFieldChange));
    model_apartment ->setTable("apartment");
    model_apartment->select();

    ui->tableView->setModel(model_apartment);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


void MainWindow::on_show_serv_prov_clicked()
{
    model_serv_prov = new QSqlTableModel(this, db);
    model_serv_prov->setEditStrategy((QSqlTableModel::OnFieldChange));
    model_serv_prov ->setTable("service_provider");
    model_serv_prov->select();

    ui->tableView->setModel(model_serv_prov);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


void MainWindow::on_show_serv_clicked()
{
    model_serv = new QSqlTableModel(this, db);
    model_serv->setEditStrategy((QSqlTableModel::OnFieldChange));
    model_serv ->setTable("services");
    model_serv->select();

    ui->tableView->setModel(model_serv);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    addRow = new add_record();
    connect(addRow, SIGNAL(refresh_table()), this, SLOT(obr_ref_table()));
    addRow->show();
}

void MainWindow::obr_ref_table(){
    on_pushButton_clicked();
}

void MainWindow::on_pushButton_3_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();
    if (selectedRow >= 0){
        model->removeRow(selectedRow);
    }
//    QSqlQuery*
}


void MainWindow::on_pushButton_5_clicked()
{
    gen_report = new report();
    gen_report->show();
}


void MainWindow::on_insert_owner_clicked()
{
    addOwner = new add_owner();
    connect(addOwner, SIGNAL(refresh_owner()), this, SLOT(obr_ref_owner()));
    addOwner->show();
}

void MainWindow::obr_ref_owner(){
    on_insert_owner_clicked();
}


void MainWindow::on_pushButton_7_clicked()
{
    addApartment = new add_apartment();
    addApartment->show();
}


//void MainWindow::on_add_serv_provider_clicked()
//{
//    addServiceProvider = new add_service_provider();
//    addServiceProvider->show();
//}


//void MainWindow::on_add_services_data_clicked()
//{
//    addService = new add_service();
//    addService->show();
//}


//void MainWindow::on_submit_clicked()
//{
//    model->submitAll();
//    model_owner->submitAll();
//    model_apartment->submitAll();
//    model_serv_prov->submitAll();
//    model_serv->submitAll();
//}

void MainWindow::on_pushButton_6_clicked()
{
    model_owner_filter = new QSqlQueryModel();
//    QSqlQuery* query = new QSqlQuery();
    QString zapros = "SELECT owner.name, owner.fio_payers, pay.summa FROM owner JOIN apartment ON apartment.fk_owner_id=owner.personal_account JOIN pay ON apartment.id_appartment=pay.fk_id_appartment WHERE pay.pay_date is NULL";
    model_owner_filter->setQuery(zapros);
    ui->tableView->setModel(model_owner_filter);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


void MainWindow::on_pushButton_8_clicked()
{
    model_apartment_filter = new QSqlQueryModel();
//    QSqlQuery* query = new QSqlQuery();
    QString zapros = "SELECT apartment.street, apartment.house, apartment.flat, apartment.square, owner.name, owner.legal_status FROM apartment JOIN owner ON apartment.fk_owner_id=owner.personal_account WHERE residental_or_no=False";
    model_apartment_filter->setQuery(zapros);
    ui->tableView->setModel(model_apartment_filter);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


//void MainWindow::on_pushButton_9_clicked()
//{
//    total_sum* total = new total_sum();
//    total->show();
//}


void MainWindow::on_filter_owner_clicked()
{
    model_owner_filter2 = new QSqlQueryModel();
    QString zapros = "SELECT apartment.street, apartment.house, apartment.flat, owner.name, owner.fio_payers, pay.pay_deadline, pay.pay_date,services.type, pay.actual_expence FROM apartment JOIN owner ON apartment.fk_owner_id=owner.personal_account JOIN pay ON apartment.id_appartment=pay.fk_id_appartment JOIN services ON pay.fk_id_service=services.id_services WHERE owner.name ='%1'";
    QString n = ui->fio_or_organization->text();
    zapros = zapros.arg(n);
    model_owner_filter2->setQuery(zapros.toUtf8());
    ui->tableView->setModel(model_owner_filter2);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


void MainWindow::on_pushButton_9_clicked()
{
    function1 = new QSqlQueryModel();
//    total_sum
    QString zapros = "SELECT total_sum(%1)";
    QString n = ui->apart_id->text();
    zapros = zapros.arg(n);
    function1->setQuery(zapros.toUtf8());
    ui->tableView->setModel(function1);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


void MainWindow::on_pushButton_10_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    QString zapros = "CALL update_tariff(%1, %2)";
    QString n = ui->type_serv->text();
    QString m = ui->value_tarif->text();
    zapros = zapros.arg(n).arg(m);
    query->prepare(zapros.toUtf8());
    query->exec();
}

