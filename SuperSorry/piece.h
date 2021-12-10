# ifndef piece_h
# define piece_h

# include "spaceFactory.h" // possible issue, check back later

class Piece : public QObject, public QGraphicsItem{
    Q_OBJECT // needed to emit signals

    public:
    // constructor
    Piece(const int player, const QPointF location, const int x, const int y);
    Piece(const int player, const int location_x, const int location_y, const int square_x, const int square_y);

    // functions needed to display space on board
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    // getter
    QColor getPlayer() const { return player_;}
    QPointF getLocation() const { return location_;}
    int getX() { return squareX;}
    int getY() { return squareY;}

    // setter
    void move(const int numSpaces);
    Space* readSpace();
    void setLocation(const QPointF location);
    void setLocation(const int x, int y);
    void setSquare(const int x, const int y);

    private:
    QColor player_;
    QPointF location_;
    int squareX;
    int squareY;
    const int size_ =10;

};

#endif // piece_h
