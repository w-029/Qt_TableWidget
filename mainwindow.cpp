#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* 两种隐藏方式等效 */
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->setShowGrid(false);

    initTableItem(10,4);
    for(int row=0; row<ui->tableWidget->rowCount(); row++) {
        for(int column=0; column<ui->tableWidget->columnCount(); column++) {
            setTableItem(row, column,
                         std::string("itemId: ").append(to_string(row)).append(string("-").append(to_string(column))),
                         "");
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTableItem(int rowCount, int columnCount) {
    /* 必须先设置行、列数，分别不显示内容 */
    ui->tableWidget->setRowCount(rowCount);
    ui->tableWidget->setColumnCount(columnCount);
    for(int row=0; row<rowCount; row++) {
        for(int column=0; column<columnCount; column++) {
            TableItem *tableItem = new TableItem();
            ui->tableWidget->setCellWidget(row, column, tableItem);
            ui->tableWidget->resizeColumnsToContents();
        }
        ui->tableWidget->resizeRowsToContents();
    }
}

void MainWindow::setTableItem(int row, int column, string name, string image) {
   QWidget *widgetItem = ui->tableWidget->cellWidget(row, column);
   TableItem *tableItem = (TableItem*) widgetItem;
   tableItem->setName(name);
   if(image.empty()) {
//       tableItem->setImage("background-image: url(:/default/res/video.png);");
//       tableItem->setImage("border-image: url(:/default/res/video.png);");
       tableItem->setImage("image: url(:/default/res/video.png);");
   }
}
