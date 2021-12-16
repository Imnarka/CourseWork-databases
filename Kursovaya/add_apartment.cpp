#include "add_apartment.h"
#include "ui_add_apartment.h"

add_apartment::add_apartment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_apartment)
{
    ui->setupUi(this);
}

add_apartment::~add_apartment()
{
    delete ui;
}

void add_apartment::on_add_apartment_button_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("INSERT INTO apartment(id_appartment, street, house, corpus, flat, residental_or_no, square, fk_owner_id, residents)"
                   "VALUES (:id_ap, :str, :house, :corpus, :flat, :resOrNo, :squ, :fk_ow_id, :resid)");
    query->bindValue(":id_ap", ui->id_appartment->text());
    query->bindValue(":str", ui->street->text());
    query->bindValue(":house", ui->house->text());
    query->bindValue(":corpus", ui->corpus->text());
    query->bindValue(":flat", ui->flat->text());
    query->bindValue(":resOrNo", ui->residental_or_no->text());
    query->bindValue(":squ", ui->square->text());
    query->bindValue(":fk_ow_id", ui->fk_owner_id->text());
    query->bindValue(":resid", ui->residents->text());

    QMessageBox* messagee = new QMessageBox();

    if (!query->exec()){
        messagee->setText("Ошибка вставки данных");
        messagee->show();
    }
    else{
        messagee->setText("Данные успешно внесены!");
        messagee->show();
    }
}

