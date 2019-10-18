#include "TableItem.h"
#include "ui_TableItem.h"

TableItem::TableItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableItem)
{
    ui->setupUi(this);
}

TableItem::~TableItem()
{
    delete ui;
}

void TableItem::setImage(string image) {
    ui->lb_image->setStyleSheet(QString::fromStdString(image));
}

void TableItem::setName(string name) {
    ui->lb_name->setText(QString::fromStdString(name));
}
