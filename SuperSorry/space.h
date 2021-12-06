#ifndef SPACE_H
#define SPACE_H

#include <QGraphicsItem>
#include <vector>
#include "colors.cpp"

// any object that inherits from QObject can emit signals
// things that inherit from QGraphicsItem can be added to QGraphicScenes
class Space : public QObject, public QGraphicsItem {

    // this makes it so that we can emit signals
    Q_OBJECT

public:
    Space(const QPointF center, const QColor color);
    Space(const int x, const int y, const QColor color);
    Space();

    // functions needed to display space on board
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    // getters
    QPointF getTop() const { return top_;}
    QPointF getBot() const { return bottom_;}
    QPointF getCenter() const { return center_;}
    QColor getColor() const { return color_;}
    int getSize() const { return size_;}

    //setters
    void setTop(const int x, const int y);
    void setTop(const QPointF c);
    void setBot(const int x, const int y);
    void setBot(const QPointF c);
    void setCenter(const int x, const int y);
    void setCenter(const QPointF c);
    void setColor(const int r, const int g, const int b);
    void setColor(const QColor color);

    //factory functions
    virtual void makeSpace(const QPointF c, const QColor color);
    virtual void makeSpace(const int x, const int y, QColor color);

protected:
  QPointF top_;
  QPointF bottom_;
  QPointF center_;

  QRectF rec_;

  QColor color_;

  // all our Spaces will be 30 wide and tall (they are squares)
  static const int size_ = 30;

};  // class Point

//class EmptySpace : public Space, public QObject, public QGraphicsItem {
//public:
//    // factory functions
//    EmptySpace(const QPointF center, const QColor color);
//    EmptySpace(const int x, const int y, const QColor color);
//    void MakeSpace(const QPointF center, const QColor color);
//    void MakeSpace(const int x, const int y, const QColor color);

//    // functions needed to display space on board
//    QRectF boundingRect() const override;
//    QPainterPath shape() const override;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
//};

#endif // SPACE_H
