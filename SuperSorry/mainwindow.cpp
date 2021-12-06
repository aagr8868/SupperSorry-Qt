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

    int start = 25;
    int increment = 30;
    int multiple = 12;
    int mid = start + increment * multiple / 2;
    int end = start + increment * multiple;
    int pItem = 10;
    int pMove = 15;
    Space* s;

    for (int x = start; x <= end; x += increment){
        for (int y = start; y <= end; y += increment){
            if (x == start || x == mid || x == end || y == start || y == mid || y == end)
            {
                if (x == mid && y == mid)
                    s = SpaceFactory::createSpace(0,x,y);
                else if (x == mid && (y > start && y < mid))
                    s = SpaceFactory::createSpace(-1,x,y,1);
                else if ((x < end && x > mid) && y == mid)
                    s = SpaceFactory::createSpace(-1,x,y,2);
                else if (x == mid && (y < end && y > start))
                    s = SpaceFactory::createSpace(-1,x,y,3);
                else if ((x > start && x < mid) && y == mid)
                    s = SpaceFactory::createSpace(-1,x,y,4);
                else{
                    if ((x == start + increment * 3 && y == start) || (x == end && y == start + increment * 3) || (x == start + increment * 9 && y == end) || (x == start && y == start + increment * 9))
                        s = SpaceFactory::createSpace(1,x,y);
                    else{
                        int ranNum = rand() % 100 + 1;
                        if (ranNum <= pItem)
                            s = SpaceFactory::createSpace(2,x,y);
                        else if (ranNum > pItem && ranNum <= pItem + pMove)
                            s = SpaceFactory::createSpace(3,x,y);
                        else
                            s = SpaceFactory::createSpace(1,x,y);
                    }
                }
                board_.push_back(s);
            }
            else if (x == start + increment * 3 && y == start + increment){
                s = SpaceFactory::createSpace(-1,x,y,4);
                board_.push_back(s);
            }
            else if (x == end - increment && y == start + increment * 3){
                s = SpaceFactory::createSpace(-1,x,y,1);
                board_.push_back(s);
            }
            else if (x == start + increment * 9 && y == end - increment){
                s = SpaceFactory::createSpace(-1,x,y,2);
                board_.push_back(s);
            }
            else if (x == start + increment && y == start + increment * 9){
                s = SpaceFactory::createSpace(-1,x,y,3);
                board_.push_back(s);
            }

        }
    }
    for (auto i = board_.begin(); i != board_.end(); i++){
        scene->addItem(*i);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
