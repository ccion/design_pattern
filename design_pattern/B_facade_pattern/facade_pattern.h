/***************************************************************
 * 文件名： facade_pattern.h
 * 
 * @功能描述:外观模式，隐藏系统的复杂性，并向客户端提供了一个客户端可以访问
    系统的接口
 * @意图:
    为子系统中的一组接口提供一个一致的界面，外观模式定义了一个高层接口，这个
    接口使得这一子系统更加容易使用
 * @主要解决:
    降低访问复杂系统的内部子系统时的复杂度，简化客户端与之的接口
 * @何时使用:
    1.客户端不需要知道系统内部的复杂联系，整个系统只需提供一个‘接待员’即可
    2.定义系统的入口
 * @如何解决:
     客户端不与系统耦合，外观类与系统耦合
 * @应用实例:
    1.去医院看病，可能要去挂号，门诊，划价，取药，让患者或患者家属觉得很复杂，
    如果有提供接待人员，只让接待人员来处理，就很方便
 * @优点:
    1.减少系统相互依赖
    2.提高灵活性
    3.提高了安全性
 * @缺点:
    不符合开闭原则，如果改东西很麻烦，继承重写都不合适
 ***************************************************************/
#ifndef FACADE_PATTERN_H
#define FACADE_PATTERN_H
#include <iostream>

/*创建一个形状的抽象接口shape*/
class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}
    virtual void draw() = 0;
};

/*创建实现形状抽象接口的实体类rectangle*/
class Rectangle : public Shape
{
public:
    Rectangle() {}
    ~Rectangle() {}

    void draw()
    {
        std::cout << "Rectangle draw function..." << std::endl;
    }
};

/*创建实现形状抽象接口的实体类square*/
class Square : public Shape
{
public:
    Square() {}
    ~Square() {}

    void draw()
    {
        std::cout << "Square draw function..." << std::endl;
    }
};

/*创建实现形状抽象接口的实体类circle*/
class Circle : public Shape
{
public:
    Circle() {}
    ~Circle() {}

    void draw()
    {
        std::cout << "Circle draw function..." << std::endl;
    }
};

/*创建一个外观类，隐藏系统的复杂性，提供访问系统的接口*/
class ShapeMaker
{
public:
    ShapeMaker()
    {
        m_circle = (Shape*)new Circle();
        m_rectangle = (Shape*)new Rectangle();
        m_square = (Shape*)new Square();
    }

    ~ShapeMaker()
    {
        if(nullptr != m_circle)
        {
            delete m_circle;
            m_circle = nullptr;
        }

        if(nullptr != m_rectangle)
        {
            delete m_rectangle;
            m_rectangle = nullptr;
        }

        if(nullptr != m_square)
        {
            delete m_square;
            m_square = nullptr;
        }
    }

    void drawcircle()
    {
        m_circle->draw();
    }

    void drawrectangle()
    {
        m_rectangle->draw();
    }

    void drawsquare()
    {
        m_square->draw();
    }

private:
    Shape *m_circle;
    Shape *m_rectangle;
    Shape *m_square;
};


#endif