# ifndef piece_h
# define piece_h

# include "mainwindow.h" // possible issue, check back later

class piece{
    public:
    // constructor
    piece(const int player);

    // getter
    int getPlayer() const { return player;}
    QColor getColor() const { return color_;}
    QPointF getLocation() const { return location_;}

    // setter
    void move(const int numSpaces);
    Space* readSpace();

    private:
    QColor color_;
    QPointF location_;
    static int player;
};

#endif // piece_h
