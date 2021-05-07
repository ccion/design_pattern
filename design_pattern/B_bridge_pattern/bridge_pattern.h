/*****************************************************************************
 * 文件名: adapter_pattern.h
 * 
 * @功能描述:桥接是用于把抽象化与实现化解耦，使得二者可以独立变化。它通过提供抽象化和实现化之
       间的桥接结构，来实现二者的解耦，这种模式涉及到一个作为桥接的接口，使得实体类的功能独立
       于接口实现类，这两种类型的类可被结构化改变而互不影响
 * @意图：
      将抽象部分与实现部分分离，使它们度可以独立的变化
 * @主要解决:
      在有多种可能会变化的情况下，用继承会造成类爆炸问题，扩展起来不灵活
 * @何时使用:
      实现系统可能有多个角度分类，每一种角度都可能变化
 * @如何解决：
      把这种多角度分类分离出来，让它们独立变化，减少它们之间的耦合
 * @应用实例:
    1.猪八戒从天蓬元帅转世投胎到猪，转世投胎的机制将尘世划分为两个等级，即：灵魂和肉体，前者
    性党羽抽象化，后者相当于实现化，生灵通过功能的委派，调用肉体对象的功能，使得生灵可以动态
    地选择
    2.墙上的开关，可以看到的开关是抽象的，不用管里面具体怎么实现的
 * @优点:
    1.抽象和实现的分离
    2.优秀的扩展能力
    3.实现细节对客户透明
 * @缺点：
    桥接模式的引入会增加系统的理解和设计难度，由于聚合关联关系建立在抽象层，要求开发者针对抽象进行
    设计与编程
 * *************************************************************************/
#ifndef BRIDGE_PATTERN_H
#define BRIDGE_PATTERN_H
#include <iostream>

/*运动接口*/
class ISport
{
public:
    ISport() {}
    virtual ~ISport() {}
    virtual void do_sport(int time) = 0;
};

/*跑步类*/
class Run : public ISport
{
public:
    Run() {}
    ~Run() {}

    void do_sport(int time)
    {
        std::cout << "run " << time << " min " << std::endl;
    }
};

/*游泳类*/
class Swim : public ISport
{
public:
    Swim() {}
    ~Swim() {}

    void do_sport(int time)
    {
        std::cout << "swim " << time << " min " << std::endl;
    }
};

/*飞行类*/
class Fly : public ISport
{
public:
    Fly() {}
    ~Fly() {}

    void do_sport(int time)
    {
        std::cout << "fly " << time << " min " << std::endl;
    }
};

/*桥接接口*/
class IBridge
{
public:
    IBridge() {}
    virtual ~IBridge() {}
    virtual void do_sport() = 0;
};

/*桥接实体类，真实场景中可能存在多个桥接实体类*/
class Client : public IBridge
{
public:
    Client(int time, ISport *sport)
    {
        m_time = time;
        m_sport = sport;
    }

    ~Client()
    {
        if(nullptr != m_sport)
        {
            delete m_sport;
            m_sport = nullptr;
        }
    }

    void do_sport()
    {
        m_sport->do_sport(m_time);
    }

private:
    int  m_time;
    ISport *m_sport = nullptr;
};

#endif
