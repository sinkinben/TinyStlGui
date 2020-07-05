#include "cuckoowidget.h"

CuckooWidget::CuckooWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *keyLabel = new QLabel("Key");
    QLabel *valLabel = new QLabel("Value");

    keyEdit = new QLineEdit(this);
    valEdit = new QLineEdit(this);
    insertButton = new QPushButton("Insert");
    deleteButton = new QPushButton("Delete");

    connect(insertButton, SIGNAL(clicked()), this, SLOT(insertButtonSlot()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteButtonSlot()));

    QHBoxLayout *hlayout = new QHBoxLayout();
    hlayout->addWidget(keyLabel);
    hlayout->addWidget(keyEdit);
    hlayout->addWidget(valLabel);
    hlayout->addWidget(valEdit);
    hlayout->addWidget(insertButton);
    hlayout->addWidget(deleteButton);
    this->setLayout(hlayout);
}

void CuckooWidget::insertButtonSlot()
{
    const int key = this->keyEdit->text().toInt();
    const int val = this->valEdit->text().toInt();
    qDebug() << "key = " << key << ", " << "val = " << val;
    qDebug() << "Insert Button is clicked";
}

void CuckooWidget::deleteButtonSlot()
{
    qDebug() << "Delete Button is clicked";
}
