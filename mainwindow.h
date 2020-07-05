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

#include "vectorwidget.h"
#include "stackwidget.h"
#include "cuckoowidget.h"


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

    void initVectorWidget();
    void initStackWidget();
    void initCuckooWidget();


    void activateWidget(QWidget *);

private slots:
    void testSlot();
    void clickTreeItemSlot(QTreeWidgetItem *item, int type);

private:
    enum treeItemType {TreeTopItem = 10001, TreeGruopItem, TreeNodeItem};
    enum stlIypeIndex {VectorIndex = 0, StackIndex, LinearHashingIndex,CuckooHasingIndex, StlTypesNumber};
    const char* stlTypes[StlTypesNumber] = {"Vector", "Stack", "LinearHasing", "CuckooHashing"};

    QHBoxLayout *mainHLayout;       // the main window split into left and right two parts
    QMenuBar *menuBar;              // the top menu bar
    QDockWidget *leftDockWidget;    // left part container
    QTreeWidget *leftTreeWidget;    // left part navigation


    QMap<QString, QWidget*> widgetSwitcher;
    QWidget *selectedWidget = nullptr;  // always points to the selected widget
    VectorWidget *vectorWidget;
    StackWidget *stackWidget;
    CuckooWidget *cuckooWidget;


};
#endif // MAINWINDOW_H
