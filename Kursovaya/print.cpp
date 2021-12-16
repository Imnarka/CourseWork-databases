#include "print.h"
#include "ui_print.h"

Print::Print(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Print)
{
    ui->setupUi(this);
}

Print::~Print()
{
    delete ui;
}
