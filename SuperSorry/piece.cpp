#include <QtWidgets>
# include "piece.h"

Piece::Piece(const int player, const QPointF location, const int square_x, const int square_y){
    switch (player) {
    case 1:
        player_ = red;
        break;
    case 2:
        player_ = blue;
        break;
    case 3:
        player_ = purple;
        break;
    case 4:
        player_ = pink;
        break;
    default:
        player_ = black;
    }

    location_ = location;
    squareX = square_x;
    squareY = square_y;
}

Piece::Piece(const int player, const int location_x, const int location_y, const int square_x, const int square_y){
    switch (player) {
    case 1:
        player_ = red;
        break;
    case 2:
        player_ = blue;
        break;
    case 3:
        player_ = purple;
        break;
    case 4:
        player_ = pink;
        break;
    default:
        player_ = black;
    }

    location_.setX(location_x);
    location_.setY(location_y);
    squareX = square_x;
    squareY = square_y;
}

// where is this object located
// always a rectangle, Qt uses this to know "where" the user
// would be interacting with this object
QRectF Piece::boundingRect() const
{
    QPointF top;
    QPointF bottom;

    top.setX(location_.x()-size_/2);
    top.setY(location_.y()-size_/2);
    bottom.setX(location_.x()+size_/2);
    bottom.setY(location_.y()+size_/2);

    return QRectF(top,bottom);
}

// define the actual shape of the object
QPainterPath Piece::shape() const
{
    QPainterPath path;
    path.addEllipse(location_,size_,size_);
    return path;
}

// called by Qt to actually display the point
void Piece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    QBrush b = painter->brush();
    // update the line for setBrush to be this
    painter->setBrush(QBrush(player_));
    painter->drawEllipse(location_,size_,size_);
    painter->setBrush(b);
}
