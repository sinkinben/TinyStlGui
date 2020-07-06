#include "linearwidget.h"

LinearWidget::LinearWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *keyLabel = new QLabel("Key", this);
    QLabel *valLabel = new QLabel("Value", this);

    keyEdit = new QLineEdit(this);
    valEdit = new QLineEdit(this);
    insertButton = new QPushButton("Insert");
    deleteButton = new QPushButton("Delete");
    tableWidget = new QTableWidget(initRow, initCol, this);

    connect(insertButton, SIGNAL(clicked(bool)), this, SLOT(insertButtonSlot()));
    connect(deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteButtonSlot()));

    QStringList header;
    header << "Index" << "H(x) = x % S";

    tableWidget->setHorizontalHeaderLabels(header);
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    clearTableWidget();

    QVBoxLayout *vlayout = new QVBoxLayout();
    QHBoxLayout *hlayout = new QHBoxLayout();
    hlayout->addWidget(keyLabel);
    hlayout->addWidget(keyEdit);
    hlayout->addWidget(valLabel);
    hlayout->addWidget(valEdit);
    hlayout->addWidget(insertButton);
    hlayout->addWidget(deleteButton);


    vlayout->addLayout(hlayout);
    vlayout->addWidget(tableWidget);

    this->setLayout(vlayout);
}

LinearWidget::~LinearWidget()
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

void LinearWidget::insertButtonSlot()
{
    const uint32_t key = keyEdit->text().toUInt();
    const uint32_t val = valEdit->text().toUInt();
    linearHashing.set(key, val);
    resetTableWidget();
}

void LinearWidget::deleteButtonSlot()
{
    const uint32_t key = keyEdit->text().toUInt();
    linearHashing.remove(key);
    resetTableWidget();
}

// set the table cells' content as ""
void LinearWidget::clearTableWidget()
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

void LinearWidget::resetTableWidget()
{
    int len = linearHashing.getCapacity();
    auto const table = linearHashing.getTable();
    if (len != tableWidget->rowCount())
    {
        tableWidget->setRowCount(len);
        clearTableWidget();
    }

    for (int i=0; i<len; i++)
    {
        if (table[i] != nullptr)
        {
            tableWidget->item(i, 1)->setText(QString("(%1, %2)").arg(table[i]->getKey()).arg(table[i]->getVal()));
        }
        else
        {
            tableWidget->item(i, 1)->setText("");
        }
    }
}
