#include <iostream>
#include "shapeManage.h"
using namespace std;



int main()
{

    shapeManage objClient;
    shape * ptri = new triangle;
    point2df pt;
    ptri->setAllPt();
//error: 'class shape' has no member named 'setpt'|
    objClient.addShape(ptri);

    shape * ptemp = objClient.findShape(1);
    SHAPENAME type = ptemp->getShapeName();
    switch(type)
    {
        case SHAPE_TRIANGLE:{break;}
    }
    return 0;
}
