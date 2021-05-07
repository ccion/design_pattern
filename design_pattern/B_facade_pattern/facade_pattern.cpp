#include "facade_pattern.h"

int main(int argc,char **argv)
{
    ShapeMaker *shape_maker = new ShapeMaker();
    shape_maker->drawcircle();
    shape_maker->drawrectangle();
    shape_maker->drawsquare();

    if(nullptr != shape_maker)
    {
        delete shape_maker;
        shape_maker = nullptr;
    }

    return 0;
}