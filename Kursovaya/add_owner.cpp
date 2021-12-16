#include "add_owner.h"
#include "ui_add_owner.h"

add_owner::add_owner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_owner)
{
    ui->setupUi(this);
}

add_owner::~add_owner()
{
    delete ui;
}

void add_owner::on_insert_data_owner_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("INSERT INTO owner(personal_account, name, fio_payers, legal_status, bank_account)"
                   "VALUES (:pa, :name, :fio_p, :l_s, :b_a)");
    query->bindValue(":pa", ui->personal_account->text());
    query->bindValue(":name", ui->name->text());
    query->bindValue(":fio_p", ui->fio_payers->text());
    query->bindValue(":l_s", ui->legal_status->text());
    query->bindValue(":b_a", ui->bank_account->text());

    QMessageBox* messagee = new QMessageBox();

    if (!query->exec()){
        messagee->setText("Ошибка вставки данных");
        messagee->show();
    }
    else{
        messagee->setText("Данные успешно внесены!");
        messagee->show();
    }
    emit refresh_owner();
}

