#include "add_service.h"
#include "ui_add_service.h"

add_service::add_service(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_service)
{
    ui->setupUi(this);
}

add_service::~add_service()
{
    delete ui;
}

void add_service::on_add_data_service_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("INSERT INTO services(id_services, type, measure_unit, counter_or_no, tariff, fk_service_provider)"
                   "VALUES (:id_services, :type, :m_u, :countOrNo, :tariff, :fk_service_provider)");
    query->bindValue(":id_services", ui->id_service->text());
    query->bindValue(":type", ui->type->text());
    query->bindValue(":m_u", ui->unit->text());
    query->bindValue(":countOrNo", ui->counter->text());
    query->bindValue(":tariff", ui->tariff->text());
    query->bindValue(":fk_service_provider", ui->fk_service_provider->text());

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

