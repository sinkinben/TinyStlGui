#ifndef VECTORWIDGET_H
#define VECTORWIDGET_H

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

class VectorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VectorWidget(QWidget *parent = nullptr);

signals:

private slots:
    void testSlot();

};

#endif // VECTORWIDGET_H
