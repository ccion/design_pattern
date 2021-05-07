#include "decorator_pattern.h"

void Circle::draw()
{
    std::cout << "draw circle..." << std::endl;
}


void Rectangle::draw()
{
    std::cout << "draw rectangle..." << std::endl;
}

ShapeDecorator::ShapeDecorator(Shape *param)
{
    m_decorated_shape = param;
}

void ShapeDecorator::draw()
{
    m_decorated_shape->draw();
}

RedShapeDecorator::RedShapeDecorator(Shape *param) : ShapeDecorator(param)
{

}

void RedShapeDecorator::draw()
{
    m_decorated_shape->draw();
    set_redborder(m_decorated_shape);
}

/*设置边框颜色*/
void RedShapeDecorator::set_redborder(Shape *param)
{
    std::cout << "Border Color:Red" << std::endl;
}