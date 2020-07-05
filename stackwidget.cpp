#include "stackwidget.h"
#include <QDebug>
StackWidget::StackWidget(QWidget *parent) : QWidget(parent)
{
    QPushButton *button = new QPushButton("stack");
    QVBoxLayout *vlayout = new QVBoxLayout();
    connect(button, SIGNAL(clicked()), this, SLOT(testSlot()));
    vlayout->addWidget(button);
    this->setLayout(vlayout);
}

void StackWidget::testSlot()
{
    qDebug() << "stack";
}
