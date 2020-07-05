#ifndef CUCKOOWIDGET_H
#define CUCKOOWIDGET_H

#include <QDebug>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QStringList>
#include <stddef.h>

#include "CuckooHashing.hpp"

class CuckooWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CuckooWidget(QWidget *parent = nullptr);
private:
    QLineEdit *keyEdit, *valEdit;
    QPushButton *insertButton, *deleteButton;
    QTableWidget *tableWidget;
    CuckooHashing<uint32_t, uint32_t> cuckooHashing;

    void resetTableWidget();


signals:

private slots:
    void insertButtonSlot();
    void deleteButtonSlot();
};

#endif // CUCKOOWIDGET_H
