#include <QDebug>
#include <QTime>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsView* view = ui->BoardView;

    scene = new QGraphicsScene;
    view->setScene(scene);
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());

    srand(static_cast<unsigned>(QTime::currentTime().msec()));

    for (int i = 0; i < boardInstance.getSize(); i++){
        for (int j = 0; j < boardInstance.getSize(); j++){
            if (boardInstance.getSpace(i,j) != nullptr){
                scene->addItem(boardInstance.getSpace(i,j));
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
