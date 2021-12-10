# ifndef board_h
# define board_h

# include "piece.h"

class Board{
public:
    static Board& getInstance(){
        static Board instance;
        return instance;
    }
    Board(Board const&) = delete;
    void operator=(Board const&) = delete;

    Space* getSpace(int i, int j) {return board_[i][j];}
    int getSize() {return size;}

private:
    const Space space_template; // used to get the size function of each space
    const int increment = space_template.getSize();
    static const int size = 13;

    const int start = 25;
    const int mid = start + increment * size / 2;
    const int end = start + increment * size;

    Space* board_ [size][size];
    int typeboard_[size][size];

    void initalize_typeboard_ ();

    static Piece pieces[12];

    Board(){
        initalize_typeboard_();

//        for (int i = 0; i < 12; i++){
//            if (i <= 2)
//        }

        int x = start;
        int y = start;
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                if (typeboard_[i][j] == 100){
                    board_[i][j] = nullptr;
                }
                else{
                    if (typeboard_[i][j] == -1){ // player squares
                        // start squares
                        if (i == size / 4 && j == 1){
                            board_[i][j] = SpaceFactory::createSpace(typeboard_[i][j],x,y,1);
                        }
                        else if (i == size - 1 - 1 && j == size / 4){
                            board_[i][j] = SpaceFactory::createSpace(typeboard_[i][j],x,y,2);
                        }
                        else if  (i == size * 3/4 && j == size - 1 - 1){
                            board_[i][j] = SpaceFactory::createSpace(typeboard_[i][j],x,y,3);
                        }
                        else if (i == 1 && j == size * 3/4){
                            board_[i][j] = SpaceFactory::createSpace(typeboard_[i][j],x,y,4);
                        }

                        // safe to end squares
                        else if (i == size / 2 && (0 < j && j < size / 2)){
                            board_[i][j] = SpaceFactory::createSpace(typeboard_[i][j],x,y,2);
                        }
                        else if ((0 < i && i < size / 2) && j == size / 2){
                            board_[i][j] = SpaceFactory::createSpace(typeboard_[i][j],x,y,1);
                        }
                        else if (i == size / 2 && (size / 2 < j && j < size - 1)){
                            board_[i][j] = SpaceFactory::createSpace(typeboard_[i][j],x,y,4);
                        }
                        else if ((size < 2 < i && i < size - 1) && j == size / 2){
                            board_[i][j] = SpaceFactory::createSpace(typeboard_[i][j],x,y,3);
                        }
                    }
                    else // every other square
                        board_[i][j] = SpaceFactory::createSpace(typeboard_[i][j],x,y);
                }
                y += increment;
            }
            x += increment;
            y = start;
        }
    } // end constructor
};

#endif // board_h
