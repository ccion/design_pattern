#include "decorator_pattern.h"

int main(int argv,char **argc)
{
    Shape *red_circle = (Shape*)new RedShapeDecorator(new Circle());
    Shape *red_rectangle = (Shape*)new RedShapeDecorator(new Rectangle());

    red_circle->draw();
    red_rectangle->draw();

    delete red_circle;
    delete red_rectangle;

    return 0;
}