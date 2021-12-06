# ifndef SPACEFACTORY_H
# define SPACEFACTORY_H

# include "space.h"

class SpaceFactory
{
public:
    static Space* createSpace(const int type, const QPointF center, const int player = -1);
    static Space* createSpace(const int type, const int x, const int y, const int player = -1);
};

#endif // SPACEFACTORY_H
