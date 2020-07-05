#ifndef CUCKOOWIDGET_H
#define CUCKOOWIDGET_H

#include <QDebug>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>


class CuckooWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CuckooWidget(QWidget *parent = nullptr);
private:
    QLineEdit *keyEdit, *valEdit;
    QPushButton *insertButton, *deleteButton;

signals:

private slots:
    void insertButtonSlot();
    void deleteButtonSlot();
};

#endif // CUCKOOWIDGET_H
