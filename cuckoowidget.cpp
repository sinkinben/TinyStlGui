#include "cuckoowidget.h"

CuckooWidget::CuckooWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *keyLabel = new QLabel("Key", this);
    QLabel *valLabel = new QLabel("Value", this);

    keyEdit = new QLineEdit(this);
    valEdit = new QLineEdit(this);
    insertButton = new QPushButton("Insert");
    deleteButton = new QPushButton("Delete");
    tableWidget = new QTableWidget(initRow, initCol, this);

    QStringList headerList;
    headerList << "Index" << "H1(x) = x % S" << "H2(x) = (x/S) % S";


    // set tableWidget style
    tableWidget->setHorizontalHeaderLabels(headerList);
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    // init the table
    clearTableWidget();


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

CuckooWidget::~CuckooWidget()
{
    if (keyEdit != nullptr)
        delete keyEdit;
    if (valEdit != nullptr)
        delete valEdit;
    if (insertButton != nullptr)
        delete insertButton;
    if (deleteButton != nullptr)
        delete deleteButton;
    if (tableWidget != nullptr)
        delete tableWidget;
}

// set the table cells' content as ""
void CuckooWidget::clearTableWidget()
{
    int r = tableWidget->rowCount();
    int c = tableWidget->columnCount();
    for (int i=0; i<r; i++)
    {
        auto item = tableWidget->item(i, 0);
        if (item == nullptr)
        {
            item = new QTableWidgetItem(QString::number(i));
            item->setTextAlignment(Qt::AlignCenter);
            tableWidget->setItem(i, 0, item);
        }
    }
    for (int i=0; i<r; i++)
    {
        for (int j=1; j<c; j++)
        {
            auto item = tableWidget->item(i, j);
            if (item == nullptr)
            {
                item = new QTableWidgetItem("");
                item->setTextAlignment(Qt::AlignCenter);
                tableWidget->setItem(i, j, item);
            }
            else
            {
                item->setText("");
            }
        }
    }
}

void CuckooWidget::resetTableWidget()
{
    auto h1 = cuckooHashing.getLeftTable();
    auto h2 = cuckooHashing.getRightTable();
    int len = cuckooHashing.getCapacity();

    if (len != tableWidget->rowCount())
    {
        tableWidget->setRowCount(len);
        clearTableWidget();
    }
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
    const uint32_t key = this->keyEdit->text().toUInt();
    cuckooHashing.remove(key);
    resetTableWidget();
}
