#include "vectorwidget.h"
#include <QDebug>
VectorWidget::VectorWidget(QWidget *parent) : QWidget(parent)
{
    QPushButton *button = new QPushButton("vector");
    QVBoxLayout *vlayout = new QVBoxLayout();
    connect(button, SIGNAL(clicked(bool)), this, SLOT(testSlot()));
    vlayout->addWidget(button);
    this->setLayout(vlayout);
}

void VectorWidget::testSlot()
{
    qDebug() << "vector";
}
