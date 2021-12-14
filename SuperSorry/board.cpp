# include "board.hpp"

void Board::initalize_typeboard_(){
    int pItem = 10; // probability of an item
    int pMove = pItem + 15; // probability of a move space
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            typeboard_[i][j] = 100; // first set flag to 100, if flag stays 100 board_[i][j] will be set to nullptr
            // set outersquare to 50 flag to be randomly assigned in this function
            if (i == 0)
                typeboard_[i][j] = 50;
            if (i == size - 1)
                typeboard_[i][j] = 50;
            if (j == 0)
                typeboard_[i][j] = 50;
            if (j == size - 1)
                typeboard_[i][j] = 50;

            // specific squares
            // home squares
            if (i == size / 4 && j == 1)
                typeboard_[i][j] = -1;
            else if (i == size - 1 - 1 && j == size / 4)
                typeboard_[i][j] = -1;
            else if  (i == size * 3/4 && j == size - 1 - 1)
                typeboard_[i][j] = -1;
            else if (i == 1 && j == size * 3/4)
                typeboard_[i][j] = -1;

            // set the space outside of home to empty space
            else if (i == size / 4 && j == 0)
                typeboard_[i][j] = 1;
            else if (i == size - 1 && j == size / 4)
                typeboard_[i][j] = 1;
            else if  (i == size * 3/4 && j == size - 1)
                typeboard_[i][j] = 1;
            else if (i == 0 && j == size * 3/4)
                typeboard_[i][j] = 1;

            // set the stripes to player colors
            else if (i == size / 2 && (j > 0 && j < size / 2))
                typeboard_[i][j] = -1;
            else if (j == size / 2 && (i > 0 && i < size / 2))
                typeboard_[i][j] = -1;
            else if (i == size / 2 && (j > size / 2 && j < size - 1))
                typeboard_[i][j] = -1;
            else if (j == size / 2 && (i > size / 2 && i < size - 1))
                typeboard_[i][j] = -1;

            // set the end square
            else if (i == size / 2 && j == size / 2)
                typeboard_[i][j] = -2;

            if (typeboard_[i][j] == 50){
                int randNum = rand() % 100 + 1;
                if (randNum <= pItem)
                    typeboard_[i][j] = 2;
                else if (randNum > pItem && randNum <= pMove)
                    typeboard_[i][j] = 3;
                else
                    typeboard_[i][j] = 1;
            }
        } // end for j
    } // end for i
} // end function

void Board::setpiece(const int index, const int player, const int x, const int y){
    switch (player){
    case 1:
        pieces[index].setPlayer(red);
        break;
    case 2:
        pieces[index].setPlayer(blue);
        break;
    case 3:
        pieces[index].setPlayer(purple);
        break;
    case 4:
        pieces[index].setPlayer(pink);
        break;
    default:
        qDebug() << "sorry but there is no player " << player;
    }

    pieces[index].setX(x);
    pieces[index].setY(y);
    pieces[index].getLocation().setX(start + increment * x);
    pieces[index].getLocation().setY(start + increment * y);
}
