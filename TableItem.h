#ifndef TABLEITEM_H
#define TABLEITEM_H

#include <QWidget>

using namespace std;
namespace Ui {
class TableItem;
}

class TableItem : public QWidget
{
    Q_OBJECT

public:
    explicit TableItem(QWidget *parent = nullptr);
    ~TableItem();

private:
    Ui::TableItem *ui;

public:
    void setImage(string image);
    void setName(string name);
};

#endif // TABLEITEM_H
