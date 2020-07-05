#ifndef STACKWIDGET_H
#define STACKWIDGET_H

#include <QObject>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class StackWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StackWidget(QWidget *parent = nullptr);

signals:

private slots:
    void testSlot();

};

#endif // STACKWIDGET_H
