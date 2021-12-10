#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>
# include "space.h"

StartSpace::StartSpace(const QPointF center, const QColor color){
    center_ = center;
    color_ = color;

    int adj = size_ / 2;
    top_.setX(center.x() - adj);
    top_.setY(center.y() - adj);
    bottom_.setX(center.x() + adj);
    bottom_.setY(center.y() + adj);

    rec_ = QRectF(top_,bottom_);
}
StartSpace::StartSpace(const int x, const int y, const QColor color){
    center_.setX(x);
    center_.setY(y);
    color_ = color;

    int adj = size_ / 2;
    top_.setX(x - adj);
    top_.setY(y - adj);
    bottom_.setX(x + adj);
    bottom_.setY(y + adj);

    rec_ = QRectF(top_,bottom_);
}
void StartSpace::MakeSpace(const QPointF center, const QColor color){
    center_ = center;
    color_ = color;

    int adj = size_ / 2;
    top_.setX(center.x() - adj);
    top_.setY(center.y() - adj);
    bottom_.setX(center_.x() + adj);
    bottom_.setY(center_.y() + adj);

    rec_ = QRectF(top_,bottom_);
}
void StartSpace::MakeSpace(const int x, const int y, const QColor color){
    center_.setX(x);
    center_.setY(y);
    color_ = color;

    int adj = size_ / 2;

    top_.setX(x - adj);
    top_.setY(y - adj);
    bottom_.setX(x + adj);
    bottom_.setY(y + adj);

    rec_ = QRectF(top_,bottom_);
}

// where is this object located
// always a rectangle, Qt uses this to know "where" the user
// would be interacting with this object
QRectF StartSpace::boundingRect() const
{
    return rec_;
}

// define the actual shape of the object
QPainterPath StartSpace::shape() const
{
    QPainterPath path;
    path.addRect(rec_);
    return path;
}

// called by Qt to actually display the point
void StartSpace::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    // update the line for setBrush to be this
    painter->setBrush(QBrush(color_));
    painter->drawRect(rec_);
    painter->setBrush(b);
}
