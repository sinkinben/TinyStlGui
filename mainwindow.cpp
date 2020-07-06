#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initWindow();
//    test();
}

MainWindow::~MainWindow()
{
    if (menuBar != nullptr)
        delete menuBar;
    if (leftDockWidget != nullptr)
    {
        if (leftTreeWidget != nullptr)
            delete leftTreeWidget;
        delete leftDockWidget;
    }
}
void MainWindow::testSlot()
{
    qDebug() << "slot got";
}

void MainWindow::clickTreeItemSlot(QTreeWidgetItem *item, int type)
{
    qDebug() << "click tree item slot";
    qDebug() << item->text(0);
    qDebug() << type;

    if (type == MainWindow::TreeTopItem)
        return;
    activateWidget(this->widgetSwitcher[item->text(0)]);


}

void MainWindow::test()
{


}

void MainWindow::initWindow()
{
    this->initMenuBar();
    this->initLeftNavigationDock();
    this->initVectorWidget();
    this->initStackWidget();
    this->initLinearWidget();
    this->initCuckooWidget();

    this->mainHLayout = new QHBoxLayout();
    this->mainHLayout->addWidget(this->leftTreeWidget);
    this->mainHLayout->addWidget(this->vectorWidget);
    this->mainHLayout->addWidget(this->stackWidget);
    this->mainHLayout->addWidget(this->linearWidget);
    this->mainHLayout->addWidget(this->cuckooWidget);


    this->widgetSwitcher[this->stlTypes[VectorIndex]] = this->vectorWidget;
    this->widgetSwitcher[this->stlTypes[StackIndex]] = this->stackWidget;
    this->widgetSwitcher[this->stlTypes[LinearHashingIndex]] = this->linearWidget;
    this->widgetSwitcher[this->stlTypes[CuckooHasingIndex]] = this->cuckooWidget;


    QWidget *mainWidget = new QWidget();
    mainWidget->setLayout(mainHLayout);
    this->setCentralWidget(mainWidget);
}

void MainWindow::initVectorWidget()
{
    this->vectorWidget = new VectorWidget();
    this->vectorWidget->setVisible(false);
}

void MainWindow::initStackWidget()
{
    this->stackWidget = new StackWidget();
    this->stackWidget->setVisible(false);
}

void MainWindow::initCuckooWidget()
{
    this->cuckooWidget = new CuckooWidget();
    this->cuckooWidget->setVisible(false);
}

void MainWindow::initLinearWidget()
{
    this->linearWidget = new LinearWidget();
    this->linearWidget->setVisible(false);
}

void MainWindow::initLeftNavigationDock()
{
    this->leftDockWidget = new QDockWidget();
    this->leftTreeWidget = new QTreeWidget();

    // init the navigation tree
    QTreeWidgetItem *rootItem = new QTreeWidgetItem(MainWindow::TreeTopItem);
    rootItem->setText(0, "Data Structure Type");

    for (int i = 0; i < MainWindow::StlTypesNumber; i++)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(MainWindow::TreeNodeItem);
        item->setText(0, stlTypes[i]);
        rootItem->addChild(item);

    }
    connect(this->leftTreeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(clickTreeItemSlot(QTreeWidgetItem*, int)));

    this->leftTreeWidget->addTopLevelItem(rootItem);
    this->leftTreeWidget->setHeaderHidden(true);
    this->leftTreeWidget->expandAll();

    this->leftDockWidget->setFeatures(QDockWidget::DockWidgetVerticalTitleBar);
    this->leftDockWidget->setWidget(this->leftTreeWidget);

}

void MainWindow::initMenuBar()
{
    // Just a demo
    this->menuBar = new QMenuBar();
    QMenu *menuFile = this->menuBar->addMenu("File");
    QAction *exitAction = menuFile->addAction("Exit");
    connect(exitAction, &QAction::triggered, [=](){ close(); });
    this->setMenuBar(this->menuBar);

}

void MainWindow::initSignalSlots()
{

}

void MainWindow::activateWidget(QWidget *widget)
{
    if (widget == nullptr)
        return;
    if (this->selectedWidget != nullptr)
        this->selectedWidget->setVisible(false);    // hide current widget
    this->selectedWidget = widget;                  // select the widget
    this->selectedWidget->setVisible(true);         // show the selected widget
}

