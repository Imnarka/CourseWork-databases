#include "add_service_provider.h"
#include "ui_add_service_provider.h"

add_service_provider::add_service_provider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_service_provider)
{
    ui->setupUi(this);
}

add_service_provider::~add_service_provider()
{
    delete ui;
}

void add_service_provider::on_pushButton_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("INSERT INTO service_provider(id_provider, bank_account, name)"
                   "VALUES (:id_p, :bank_ac, :name)");
    query->bindValue(":id_p", ui->id_provider->text());
    query->bindValue(":bank_acc", ui->bank_account->text());
    query->bindValue(":name", ui->name->text());

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

