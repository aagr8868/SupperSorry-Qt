# include "spaceFactory.h"

Space* SpaceFactory::createSpace(const int type, const QPointF center, const int player){
    Space* space = nullptr;
    QColor playerColor;

    switch (player){
        case 1:
            playerColor = red;
            break;
        case 2:
            playerColor = blue;
            break;
        case 3:
            playerColor = purple;
            break;
        case 4:
            playerColor = pink;
            break;
        default:
            playerColor = black;
    }

    switch (type){
        case -1:
            space = new Space(center, playerColor);
            break;
        case 0:
            space = new Space(center,green);
            break;
        case 1:
            space = new Space(center,white);
            break;
        case 2:
            space = new Space(center,yellow);
            break;
        case 3:
            space = new Space(center,orange);
            break;
        default:
            qDebug() << "Invalid Space type";
            return nullptr;
    }
    return space;
}

Space* SpaceFactory::createSpace(const int type, const int x, const int y, const int player){
    Space* space = nullptr;
    QColor playerColor;

    switch (player){
        case 1:
            playerColor = red;
            break;
        case 2:
            playerColor = blue;
            break;
        case 3:
            playerColor = purple;
            break;
        case 4:
            playerColor = pink;
            break;
        default:
            playerColor = black;
    }

    switch (type){
        case -1: // start or safespace
            space = new Space(x, y, playerColor);
            break;
        case -2: // end
            space = new Space(x,y,green);
            break;
        case 1: // empty
            space = new Space(x,y,white);
            break;
        case 2: // item
            space = new Space(x,y,yellow);
            break;
        case 3: // move forward
            space = new Space(x,y,orange);
            break;
        default:
            qDebug() << "Invalid Space type";
            return nullptr;
    }
    return space;
}
