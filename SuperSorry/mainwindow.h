#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "board.hpp"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_RollButton_clicked();
    void on_MoveButton_clicked();
    void on_MoveButton_2_clicked();
    void on_MoveButton_3_clicked();
    void on_MoveButton_4_clicked();

    void on_RedButton_clicked();

    void on_BlueButton_clicked();

    void on_GreenButton_clicked();

    void on_PurpleButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Board& boardInstance = Board::getInstance();

    int getNumPlayers();
    int nextPlayer();
    void updateCurrentPlayer();
    void checkColision(int player);

    int roll;
    int redItem;
    int blueItem;
    int purpleItem;
    int pinkItem;

    int currentPlayer;
};
#endif // MAINWINDOW_H
