/***************************************************************
 * 文件名： decorator_pattern.h
 * 
 * @功能描述:装饰器模式允许向一个现有的对象添加新的功能，同时又不改变其结构，
 * @意图:
      动态地给一个对象添加一些额外的职责，就增加功能来说，装饰器模式相比生
    成子类更灵活
 * @主要解决:
      一般的，我们为了扩展一个类经常使用继承方式实现，由于继承为类引入静态特
    征，并且随着扩展功能的增多，子类会很膨胀
 * @何时使用:
      在不想增加很多子类的情况下扩展类
 * @应用实例
      1.孙悟空有72变，当他变成"庙宇"后，他的根本还是一只猴子，但是他又有了
      庙宇的功能。
      2.不论一幅画有没有画框都可以挂在墙上，但是通常都是有画框的，并且实际
      上是画框被挂在墙上，画可以被蒙上玻璃，装到框子里，这时画，玻璃和画框
      形成了一个物体
 * @优点:
      装饰器和被装饰器类可以独立发展，不会相互耦合，装饰模式是继承的一个替代
      模式，装饰模式可以动态扩展一个实现类的功能
 * @缺点:
       多层装饰比较复杂
 * 
 ***************************************************************/
#ifndef DECORATOR_PATTERN_H
#define DECORATOR_PATTERN_H
#include <iostream>

/*创建一个形状的接口*/
class Shape
{
public:
    Shape() {}
    virtual ~Shape(){}

    virtual void draw() = 0;

};

/*创建圆形circle类继承形状基类接口*/
class Circle : public Shape
{
public:
    Circle() {}
    ~Circle() {}

    void draw();
};

/*创建一个三角形rectangle类继承形状shape基类*/
class Rectangle : public Shape
{
public:
    Rectangle() {}
    ~Rectangle() {}
    
    void draw();
};

/*创建一个形状装饰器shapeDecorator类继承形状shape基类*/
class ShapeDecorator : public Shape
{
public:
    ShapeDecorator(Shape *param);
    virtual ~ShapeDecorator() {}

    void draw();

protected:
    Shape *m_decorated_shape;
};

/*扩展shaped decorator为red shaped decorator*/
class RedShapeDecorator : public ShapeDecorator
{
public:
    RedShapeDecorator(Shape *param);
    ~RedShapeDecorator(){}
    void draw();

private:
    void set_redborder(Shape *param);
};

#endif