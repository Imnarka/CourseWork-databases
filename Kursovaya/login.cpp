#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    ui->lineEdit->setText("127.0.0.1");
    ui->lineEdit_2->setText("Kursovaya");
    ui->lineEdit_3->setText("postgres");

    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
   mes = new QMessageBox();
}

login::~login()
{
    delete ui;
}

void login::on_ConnectDB_clicked()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(ui->lineEdit->text());
    db.setDatabaseName(ui->lineEdit_2->text());
    db.setUserName(ui->lineEdit_3->text());
    db.setPassword(ui->lineEdit_4->text());

    if (db.open()){
        mes->setText("Соединено");
    }
    else{
        mes->setText("Соединение не установлено");
    }
    mes->show();
}

