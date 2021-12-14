 #include <QtWidgets>
# include "piece.h"

Piece::Piece(){
    player_ = black;
    location_.setX(0);
    location_.setY(0);
    squareX = 0;
    squareY = 0;
}

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

void Piece::move(const int numSpaces, const int size_square, const int size_board){

    const int MIN = 0;
    const int MAX = size_board - 1;
    const int MID = size_board / 2;

    for (int i = 0; i < numSpaces; i++)
    {
        // check to see if start moving piece toward center
        if (player_ == blue && squareX == MID && squareY == MIN){
            squareY++;
            location_.setY(location_.y() + size_square);
        }
        else if (player_ == purple && squareX == MAX && squareY == MID){
            squareX--;
            location_.setX(location_.x() - size_square);
        }
        else if (player_ == pink && squareX == MID && squareY == MAX){
            squareY--;
            location_.setY(location_.y() - size_square);
        }
        else if (player_ == red && squareX == MIN && squareY == MID){
            squareX++;
            location_.setX(location_.x() + size_square);
        }
        // moving the piece somewhere in the safe spaces
        else if (MIN < squareX && squareX < MAX && MIN < squareY && squareY < MAX){
            // moving the piece along the center lines
            if (squareX == MID && squareY < MID){
                squareY++;
                location_.setY(location_.y() + size_square);
            }
            else if (squareX == MID && squareY > MID){
                squareY--;
                location_.setY(location_.y() - size_square);
            }
            else if (squareX < MID && squareY == MID){
                squareX++;
                location_.setX(location_.x() + size_square);
            }
            else if (squareX > MID && squareY == MID){
                squareX--;
                location_.setX(location_.x() - size_square);
            }
            else if (squareX == MID && squareY == MID){
                qDebug() << "Piece is at center, I am not moving it";
            }
            // moving the piece from the starting location
            else if (squareX == MID / 2 && squareY == MIN + 1){
                squareY--;
                location_.setY(location_.y() - size_square);
            }
            else if (squareX == MAX - 1 && squareY == MID  / 2){
                squareX++;
                location_.setX(location_.x() + size_square);
            }
            else if (squareX == MAX * 3/4 && squareY == MAX - 1){
                squareY++;
                location_.setY(location_.y() + size_square);
            }
            else if (squareX == MIN + 1 && squareY == MAX * 3/4){
                squareX--;
                location_.setX(location_.x() - size_square);
            }
        }
        // top left corner
        else if (squareX == MIN && squareY == MIN){
            squareX++;
            location_.setX(location_.x() + size_square);
        }
        // top row
        else if (MIN < squareX && squareX < MAX && squareY == MIN){
            squareX++;
            location_.setX(location_.x() + size_square);
        }
        // top right corner
        else if (squareX == MAX && squareY == MIN){
            squareY++;
            location_.setY(location_.y() + size_square);
        }
        // left column
        else if (squareX == MAX && MIN < squareY && squareY < MAX){
            squareY++;
            location_.setY(location_.y() + size_square);
        }
        // bottom right corner
        else if (squareX == MAX && squareY == MAX){
            squareX--;
            location_.setX(location_.x() - size_square);
        }
        // bottom row
        else if (MIN < squareX && squareX < MAX && squareY == MAX){
            squareX--;
            location_.setX(location_.x() - size_square);
        }
        // bottom left corner
        else if (squareX == MIN && squareY == MAX){
            squareY--;
            location_.setY(location_.y() - size_square);
        }
        // left column
        else if (squareX == MIN & MIN < squareY && squareY < MAX){
            squareY--;
            location_.setY(location_.y() - size_square);
        }
        else {
            qDebug() << "Oops, I dropped a piece";
        }
    }
}

bool Piece::checkCollision(Piece p){
    return p.getLocation() == location_;
}

void Piece::setLocation(const QPointF location){
    location_ = location;
}

void Piece::setLocation(const int x, int y){
    location_.setX(x);
    location_.setY(y);
}

void Piece::setSquare(const int x, const int y){
    squareX = x;
    squareY = y;
}
void Piece::setPlayer(const QColor player){
    player_ = player;
}

void Piece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Point clicked";
}
