#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include "stdafx.h"

//线段由两点来构成
template<typename DT>
class point2d
{
    DT _x;
    DT _y;
public:
    //ctor
    //point2d():_x(0),_y(0){}
    point2d(DT x,DT y):_x(x),_y(y){}
    //copy ctor
    point2d(const point2d & obj):_x(obj._x),_y(obj._y){ }

    //member of function
public:
    DT getx()const {return _x;}

    DT gety()const {return _y;}

    void setx(DT x){_x = x;}
    void sety(DT x){_y = x;}
};

using point2df = point2d<float>;

#endif // POINT_H_INCLUDED
