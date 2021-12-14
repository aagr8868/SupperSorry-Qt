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

    redItem = 0;
    ui->RedItem->setFontPointSize(25);
    ui->RedItem->setFontWeight(20);

    blueItem = 0;
    ui->BlueItem->setFontPointSize(25);
    ui->BlueItem->setFontWeight(20);

    pinkItem = 0;
    ui->PinkItem->setFontPointSize(25);
    ui->PinkItem->setFontWeight(20);

    purpleItem = 0;
    ui->PurpleItem->setFontPointSize(25);
    ui->PurpleItem->setFontWeight(20);

    currentPlayer = 1;
    ui->CurrentPlayer->setFontPointSize(15);
    ui->CurrentPlayer->setFontWeight(20);
    updateCurrentPlayer();

    for (int i = 0; i < 4; i++){
        scene->addItem(boardInstance.getPiece(i));
    }

    ui->RollDisplay->setFontPointSize(25);
    ui->RollDisplay->setFontWeight(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCurrentPlayer(){
    switch (currentPlayer) {
    case 1:
        ui->CurrentPlayer->setText("Red");
        break;
    case 2:
        ui->CurrentPlayer->setText("Blue");
        break;
    case 3:
        ui->CurrentPlayer->setText("Purple");
        break;
    case 4:
        ui->CurrentPlayer->setText("Pink");
        break;
    default:
        qDebug() << "Error 84: updateCurrentPlayer()";
    }
}

void MainWindow::on_RollButton_clicked()
{
    roll = rand() % 6 + 1;
    ui->RollDisplay->setText(QString::number(roll));
}


void MainWindow::on_MoveButton_clicked()
{
    scene->update();
    boardInstance.getPiece(0)->move(roll,boardInstance.getSpace(0,0)->getSize(),boardInstance.getSize());
    boardInstance.getPiece(0)->update();
    currentPlayer = nextPlayer();
    updateCurrentPlayer();
    checkColision(1);
    if (boardInstance.getSpace(boardInstance.getPiece(0)->getX(),boardInstance.getPiece(0)->getY())->getColor() == orange){
        boardInstance.getPiece(0)->move(4,boardInstance.getSpace(0,0)->getSize(),boardInstance.getSize());
    }
    else if (boardInstance.getSpace(boardInstance.getPiece(0)->getX(),boardInstance.getPiece(0)->getY())->getColor() == yellow){
        int item = rand() % 6 + 1;
        ui->RedItem->setText(QString::number(item));
        redItem = item;
    }
    scene->update();
}


void MainWindow::on_MoveButton_2_clicked()
{
    scene->update();
    boardInstance.getPiece(1)->move(roll,boardInstance.getSpace(0,0)->getSize(),boardInstance.getSize());
    boardInstance.getPiece(1)->update();
    currentPlayer = nextPlayer();
    updateCurrentPlayer();
    checkColision(2);
    if (boardInstance.getSpace(boardInstance.getPiece(1)->getX(),boardInstance.getPiece(1)->getY())->getColor() == orange){
        boardInstance.getPiece(1)->move(4,boardInstance.getSpace(0,0)->getSize(),boardInstance.getSize());
    }
    else if (boardInstance.getSpace(boardInstance.getPiece(1)->getX(),boardInstance.getPiece(1)->getY())->getColor() == yellow){
        int item = rand() % 6 + 1;
        ui->BlueItem->setText(QString::number(item));
        blueItem = item;
    }
    scene->update();
}


void MainWindow::on_MoveButton_3_clicked()
{
    scene->update();
    boardInstance.getPiece(2)->move(roll,boardInstance.getSpace(0,0)->getSize(),boardInstance.getSize());
    boardInstance.getPiece(2)->update();
    currentPlayer = nextPlayer();
    updateCurrentPlayer();
    checkColision(3);
    if (boardInstance.getSpace(boardInstance.getPiece(2)->getX(),boardInstance.getPiece(2)->getY())->getColor() == orange){
        boardInstance.getPiece(2)->move(4,boardInstance.getSpace(0,0)->getSize(),boardInstance.getSize());
    }
    else if (boardInstance.getSpace(boardInstance.getPiece(2)->getX(),boardInstance.getPiece(2)->getY())->getColor() == yellow){
        int item = rand() % 6 + 1;
        ui->PurpleItem->setText(QString::number(item));
        purpleItem = item;
    }
    scene->update();
}


void MainWindow::on_MoveButton_4_clicked()
{
    scene->update();
    boardInstance.getPiece(3)->move(roll,boardInstance.getSpace(0,0)->getSize(),boardInstance.getSize());
    boardInstance.getPiece(3)->update();
    currentPlayer = nextPlayer();
    updateCurrentPlayer();
    checkColision(4);
    if (boardInstance.getSpace(boardInstance.getPiece(3)->getX(),boardInstance.getPiece(3)->getY())->getColor() == orange){
        boardInstance.getPiece(3)->move(4,boardInstance.getSpace(0,0)->getSize(),boardInstance.getSize());
    }
    else if (boardInstance.getSpace(boardInstance.getPiece(3)->getX(),boardInstance.getPiece(3)->getY())->getColor() == yellow){
        int item = rand() % 6 + 1;
        ui->PinkItem->setText(QString::number(item));
        pinkItem = item;
    }
    scene->update();
}

int MainWindow::getNumPlayers(){
    if (ui->PinkItem->isHidden()){
        return 2;
    }
    else if (ui->PurpleItem->isHidden()){
        return 3;
    }
    else{
        return 4;
    }
}

int MainWindow::nextPlayer(){
    if (currentPlayer == 1){
        return 2;
    }
    else if (currentPlayer == 2){
        if (getNumPlayers() > 2){
            return 3;
        }
        else {
            return 1;
        }
    }
    else if (currentPlayer == 3){
        if (getNumPlayers() == 3){
            return 1;
        }
        else{
            return 4;
        }
    }
    else if (currentPlayer == 4){
        return 1;
    }
    else {
        qDebug() << "Error 135: MainWindow::nextPlayer()";
        return -1;
    }
}

void MainWindow::checkColision(int player){
    for (int i = 0; i < getNumPlayers(); i++){
        if (boardInstance.getPiece(player - 1)->getLocation() == boardInstance.getPiece(i)->getLocation() && boardInstance.getPiece(player - 1)->getPlayer() != boardInstance.getPiece(i)->getPlayer()){
            qDebug() << "Collision Detected";
            boardInstance.getPiece(i)->move(1,boardInstance.getSpace(0,0)->getSize(),boardInstance.getInstance().getSize());
        }
        else{
            if (i == getNumPlayers() - 1){
                qDebug() << "No collision deteected";
            }
        }
    }
}

void MainWindow::on_RedButton_clicked()
{
    scene->update();
    if (redItem > 0){
        boardInstance.getPiece(0)->move(redItem,boardInstance.getSpace(0,0)->getSize(),boardInstance.getSize());
        redItem = 0;
    }
    else if (redItem == 0){
        qDebug() << "Moving an extra 0 spaces";
    }
    else{
        qDebug() << "Error 230: RedItem is Negitive";
    }
    scene->update();
}


void MainWindow::on_BlueButton_clicked()
{
    scene->update();
    if (blueItem > 0){
        boardInstance.getPiece(1)->move(blueItem,boardInstance.getSpace(0,0)->getSize(),boardInstance.getSize());
        blueItem = 0;
    }
    else if (redItem == 0){
        qDebug() << "Moving an extra 0 spaces";
    }
    else{
        qDebug() << "Error 230: BlueItem is Negitive";
    }
    scene->update();
}


void MainWindow::on_GreenButton_clicked()
{
    scene->update();
    if (purpleItem > 0){
        boardInstance.getPiece(2)->move(purpleItem,boardInstance.getSpace(0,0)->getSize(),boardInstance.getSize());
        purpleItem = 0;
    }
    else if (redItem == 0){
        qDebug() << "Moving an extra 0 spaces";
    }
    else{
        qDebug() << "Error 230: PurpleItem is Negitive";
    }
    scene->update();
}


void MainWindow::on_PurpleButton_clicked()
{
    scene->update();
    if (pinkItem > 0){
        boardInstance.getPiece(3)->move(pinkItem,boardInstance.getSpace(0,0)->getSize(),boardInstance.getSize());
        pinkItem = 0;
    }
    else if (redItem == 0){
        qDebug() << "Moving an extra 0 spaces";
    }
    else{
        qDebug() << "Error 230: PinkItem is Negitive";
    }
    scene->update();
}

