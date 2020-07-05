#include "cuckoowidget.h"
#define S 8
CuckooWidget::CuckooWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *keyLabel = new QLabel("Key");
    QLabel *valLabel = new QLabel("Value");

    keyEdit = new QLineEdit(this);
    valEdit = new QLineEdit(this);
    insertButton = new QPushButton("Insert");
    deleteButton = new QPushButton("Delete");
    tableWidget = new QTableWidget(S,3, this);

    QStringList headerList;
    headerList << "Index" << "H1(x) = x % S" << "H2(x) = (x/S) % S";

    tableWidget->setHorizontalHeaderLabels(headerList);
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i=0; i<S; i++)
    {
        QTableWidgetItem *item0 = new QTableWidgetItem(QString::number(i));
        item0->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(i, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem("");
        item1->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(i, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem("");
        item2->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(i, 2, item2);

    }


    connect(insertButton, SIGNAL(clicked()), this, SLOT(insertButtonSlot()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteButtonSlot()));

    QHBoxLayout *hlayout = new QHBoxLayout();
    hlayout->addWidget(keyLabel);
    hlayout->addWidget(keyEdit);
    hlayout->addWidget(valLabel);
    hlayout->addWidget(valEdit);
    hlayout->addWidget(insertButton);
    hlayout->addWidget(deleteButton);

    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->addLayout(hlayout);
    vlayout->addWidget(tableWidget);


    this->setLayout(vlayout);
}

void CuckooWidget::resetTableWidget()
{
    auto h1 = cuckooHashing.getLeftTable();
    auto h2 = cuckooHashing.getRightTable();
    int len = cuckooHashing.getCapacity();
    for (int i = 0; i < len; i++)
    {
        if (h1[i] != nullptr)
            tableWidget->item(i, 1)->setText(QString("(%1, %2)").arg(h1[i]->getKey()).arg(h1[i]->getVal()));
        else
            tableWidget->item(i, 1)->setText("");


        if (h2[i] != nullptr)
            tableWidget->item(i, 2)->setText(QString("(%1, %2)").arg(h2[i]->getKey()).arg(h2[i]->getVal()));
        else
            tableWidget->item(i, 2)->setText("");

    }

}

void CuckooWidget::insertButtonSlot()
{
    const uint32_t key = this->keyEdit->text().toUInt();
    const uint32_t val = this->valEdit->text().toUInt();
    cuckooHashing.set(key, val);
    resetTableWidget();

}

void CuckooWidget::deleteButtonSlot()
{
    qDebug() << "delete button is clicked";
    const uint32_t key = this->keyEdit->text().toUInt();
    cuckooHashing.remove(key);
    resetTableWidget();
}
