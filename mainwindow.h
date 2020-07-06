#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <c++/string>
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QAction>
#include <QDockWidget>
#include <QTreeWidget>
#include <QString>
#include <QMap>

#include "cuckoowidget.h"
#include "linearwidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void test();
    void initWindow();
    void initMenuBar();
    void initLeftNavigationDock();
    void initSignalSlots();

    void initCuckooWidget();
    void initLinearWidget();


    void activateWidget(QWidget *);

private slots:
    void testSlot();
    void clickTreeItemSlot(QTreeWidgetItem *item, int type);

private:
    enum treeItemType {TreeTopItem = 10001, TreeGruopItem, TreeNodeItem};
    enum stlIypeIndex {LinearHashingIndex = 0, CuckooHasingIndex, StlTypesNumber};
    const char* stlTypes[StlTypesNumber] = {"LinearHasing", "CuckooHashing"};

    QHBoxLayout *mainHLayout;       // the main window split into left and right two parts
    QMenuBar *menuBar;              // the top menu bar
    QDockWidget *leftDockWidget;    // left part container
    QTreeWidget *leftTreeWidget;    // left part navigation


    QMap<QString, QWidget*> widgetSwitcher;
    QWidget *selectedWidget = nullptr;  // always points to the selected widget
    CuckooWidget *cuckooWidget;
    LinearWidget *linearWidget;


};
#endif // MAINWINDOW_H
