#include "report.h"
#include "ui_report.h"

report::report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::report)
{
    ui->setupUi(this);
}

report::~report()
{
    delete ui;
}

void report::on_pushButton_clicked()
{
    QFile* file = new QFile();
    file->setFileName(ui->files->text());
    file->open(QIODevice::WriteOnly);
    QSqlQuery* gen_report = new QSqlQuery();
    QTextStream in(file);
    in << "<html><head></head><body><center>"+QString("Отчёт");
    in << "<table border=1><tr>";
    in << "<td>"+QString("Улица")+"</td>";
    in << "<td>"+QString("Дом")+"</td>";
    in << "<td>"+QString("Квартира")+"</td>";
    in << "<td>"+QString("Дата оплаты")+"</td>";
    in << "<td>"+QString("Крайний срок оплаты")+"</td>";
    in << "<td>"+QString("Пени")+"</td>";
    in << "<td>"+QString("Начислено")+"</td>";
    in << "<td>"+QString("Плательщик")+"</td>";
    in << "<td>"+QString("Тип услуги")+"</td>";
    in << "<td>"+QString("Итого")+"</td></tr>";
    QString query_str = "SELECT apartment.street, apartment.house, apartment.flat, pay.pay_date, pay.pay_deadline, pay.fine, pay.summa, owner.name, services.type, pay.fine + pay.summa AS total FROM apartment JOIN pay ON pay.fk_id_appartment=apartment.id_appartment JOIN owner ON apartment.fk_owner_id=owner.personal_account JOIN services ON services.id_services=pay.fk_id_service WHERE pay.pay_date >= :before AND pay.pay_date <= :after";
    gen_report->prepare(query_str.toUtf8());
    gen_report->bindValue(":before", ui->pay_date_for_report->text());
    gen_report->bindValue(":after", ui->pay_date_for_report_before->text());

    gen_report->exec();
    while (gen_report->next()) {
        in << "<tr><td>";
        in << gen_report->value(0).toString();
        in << "</td><td>";
        in << gen_report->value(1).toString();
        in << "</td><td>";
        in << gen_report->value(2).toString();
        in << "</td><td>";
        in << gen_report->value(3).toString();
        in << "</td><td>";
        in << gen_report->value(4).toString();
        in << "</td><td>";
        in << gen_report->value(5).toString();
        in << "</td><td>";
        in << gen_report->value(6).toString();
        in << "</td><td>";
        in << gen_report->value(7).toString();
        in << "</td><td>";
        in << gen_report->value(8).toString();
        in << "</td><td>";
        in << gen_report->value(9).toString();
        in << "</td></td>";

    }
    in << "</table></center></body></html>";
    file->close();
    QAxObject* wordDocument = new QAxObject("Word.Application", this);
    wordDocument->setProperty("DisplayAlerts", false);
    wordDocument->setProperty("Visible", true);
    QAxObject* document = wordDocument->querySubObject("Documents");
    document->dynamicCall("Open(QVariant)", ui->files->text());
}


void report::on_obzor_clicked()
{
    ui->files->setText(QFileDialog::getOpenFileName(0, "Выберите файл", "./", "*.html"));
}

