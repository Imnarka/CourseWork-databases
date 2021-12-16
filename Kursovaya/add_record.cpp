#include "add_record.h"
#include "ui_add_record.h"

add_record::add_record(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_record)
{
    ui->setupUi(this);
}

add_record::~add_record()
{
    delete ui;
}

void add_record::on_pushButton_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("INSERT INTO pay(id_pay, actual_expence, pay_deadline, pay_date, delay, fk_id_appartment, fk_id_service, summa, fine) "
                   "VALUES (:ipay, :ae, :pdeadline, :pdate, :delay, :fk_id_appartment, :fk_id_service, :sum, :fine)");
    query->bindValue(":ipay", ui->id_pay->text());
    query->bindValue(":ae", ui->actual_expence->text());
    query->bindValue(":pdeadline", ui->pay_deadline->text());
    query->bindValue(":delay", ui->delay->text());
    query->bindValue(":fk_id_appartment", ui->fk_apartment_id->text());
    query->bindValue(":fk_id_service", ui->fk_id_service->text());
    query->bindValue(":sum", ui->sum->text());
    query->bindValue(":fine", ui->fine->text());

    QMessageBox* messagee = new QMessageBox();

    if (!query->exec()){
        messagee->setText("Ошибка вставки данных");
        messagee->show();
        qDebug() << query->lastError();
    }
    else{
        messagee->setText("Данные успешно внесены!");
        messagee->show();
    }
    emit refresh_table();
}

