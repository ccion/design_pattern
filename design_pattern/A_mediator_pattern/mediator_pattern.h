/*****************************************************************************
 * 文件名: memento_pattern.h
 * 
 * @功能描述:用来降低多个对象和类之间的通信复杂性。其提供一个中介类，该类通常处理不同
 *         类之间的通信，并支持松耦合，使代码易于维护。
 * @意图：
 *    用一个中介对象来封装一系列的对象交互，中介者使各对象不需要显示地相互引用，从而
 *    使其耦合松散，而且可以独立地改变他们之间的交互
 * @主要解决:
 *    对象与对象之间存在大量的关联关系，这样势必会导致系统的结构变得很复杂，同时若一
 *    个对象发生改变，我们也需要跟踪与之相关联的对象，同时做出相应的处理
 * @何时使用:多个类相互耦合，形成了网状结构
 * @关键代码:对象colleague之间的通信封装到一个类中单独处理
 * @应用实例:
 *   1.中国加入WTO之前是各个国家相互贸易，结构复杂，现在是各个国家通过WTO来互相贸易；
 *   2.机场调度系统
 *   3.MVC框架，其中C(控制器)就是M(模型)和V(视图)的中介者
 * @优点:
 *   1.降低了类的复杂度，将一对多转化成了一对一
 *   2.各个类之间的解耦
 *   3.符合迪米特原则
 * @缺点:
 *   中介者会庞大，变得复杂难以维护
 * 
 * *************************************************************************/
#ifndef MEDIATOR_PATTERN_H
#define MEDIATOR_PATTERN_H
#include <vector>
#include <iostream>

class Colleague;

class Mediator
{
public:
    Mediator(){}
    virtual ~Mediator() {}

    virtual void send(std::string msg, Colleague *p) = 0;
};

class Colleague
{
public:
    Colleague(Mediator *p)
    {
        m_mediator = p;
    }
    virtual ~Colleague() {}
    virtual void send(std::string msg) = 0;
    virtual void notify(std::string msg) = 0;

protected:
    Mediator *m_mediator;
};

class ConcreteColleague0 : public Colleague
{
public:
    ConcreteColleague0(Mediator *p) : Colleague(p) {}
    ~ConcreteColleague0() {}

    void send(std::string msg)
    {
        m_mediator->send(msg, this);
    }

    void notify(std::string msg)
    {
        std::cout << "Colleague0 收到了消息:" << msg << std::endl;
    }
};

class ConcreteColleague1 : public Colleague
{
public:
    ConcreteColleague1(Mediator *p) : Colleague(p) {}
    ~ConcreteColleague1() {}

    void send(std::string msg)
    {
        m_mediator->send(msg, this);
    }

    void notify(std::string msg)
    {
        std::cout << "Colleague1 收到了消息:" << msg << std::endl;
    }
};

class ConcreteMediator : public Mediator
{
public:
    void add_colleague(Colleague *p1, Colleague *p2)
    {
        m_p1 = p1;
        m_p2 = p2;
    }

    void send(std::string msg, Colleague *p)
    {
        //这里接受来自一个同事发过来的消息，具体应该给谁要根据需求来
        //这里是简单举例，比如该类总可以是有两个队列
        //一个队列是客户，一个队列是客服
        if(p == m_p1){
            m_p2->notify(msg);
        }else{
            m_p1->notify(msg);
        }
    }
private:
    //这里也可以是一个列表
    Colleague *m_p1;
    Colleague *m_p2;
};

#endif