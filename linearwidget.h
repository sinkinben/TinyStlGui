#ifndef LINEARWIDGET_H
#define LINEARWIDGET_H

#include <QDebug>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QStringList>
#include <QHeaderView>

#include "LinearHashing.hpp"

class LinearWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LinearWidget(QWidget *parent = nullptr);
    ~LinearWidget();

private:
    const int initRow = 8, initCol = 2;
    QLineEdit *keyEdit, *valEdit;
    QPushButton *insertButton, *deleteButton;
    QTableWidget *tableWidget;
    LinearHashing<uint32_t, uint32_t> linearHashing;

    void clearTableWidget();
    void resetTableWidget();

signals:

private slots:
    void insertButtonSlot();
    void deleteButtonSlot();

};

#endif // LINEARWIDGET_H
