/*****************************************************************************
 * 文件名: observer_pattern.h
 * 
 * @功能描述:当对象间存在一对多关系时，则使用观察者模式(observer pattern).比如，当一个
 * 对象被修改时，则会自动通知依赖它的对象
 * 
 * @意图:定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象
 * 都得到通知并自动更新
 * @主要解决:一个对象状态改变给其他对象通知的问题，而且要考虑到易用和低耦合，保证高度的协作
 * @何时使用：一个对象(目标对象)的状态发生改变，所有的依赖对象(观察者对象)都将得到通知，进行
 * 广播通知
 * @如何解决:使用面向对象技术，可以将这种依赖关系弱化
 * @应用实例:
 * 1.拍卖的时候，拍卖师观察最高标价，然后通知给其他竞价者竞价;
 * 2.西游记里面悟空请求菩萨降服红孩儿，菩萨洒了一地水招来一个老乌龟，这个乌龟就是观察者，他观察菩萨
 *  洒水这个动作
 * @优点:
 * 1.观察者和被观察者是抽象耦合的
 * 2.建立一套触发机制
 * @缺点:
 * 1.如果一个被观察者对象有很多的直接和间接的观察者的话，将所有的观察者都通知到会花费很多时间;
 * 2.如果在观察者和观察目标之间有循环依赖的话，观察目标会触发它们之间进行循环调用，可能导致系统
 * 奔溃
 * 3.观察者模式没有相应的机制让观察者知道所观察的目标对象是怎么发生变化的，而仅仅只是知道观察目标
 * 发生了变化
 * *************************************************************************/
#ifndef OBSERVER_PATTERN_H
#define OBSERVER_PATTERN_H
#include <vector>
#include <iostream>


class IObserver;

class ISubject
{
public:
    ISubject() {}
    virtual ~ISubject() {}

    virtual void add_observer(IObserver *observer) = 0;
    virtual void delete_observer(IObserver *observer) = 0;
    virtual void notify_observers(std::string context) = 0;
};

class InstanceSubject : public ISubject
{
public:
    InstanceSubject(){}
    ~InstanceSubject(){}

    void add_observer(IObserver *observer);
    void delete_observer(IObserver *observer);
    void notify_observers(std::string context);


    void send_message();

private:
    std::vector<IObserver*> m_observers;
    typedef std::vector<IObserver*>::const_iterator m_iterator;
};

class IObserver
{
public:
    IObserver(std::string name)
    {
        m_name = name;
    }
    virtual ~IObserver(){}

    virtual void update(std::string  context) = 0;
    virtual std::string get_name() = 0;

protected:
    std::string m_name;

};

class BinaryObserver : public IObserver
{
public:
    BinaryObserver();
    ~BinaryObserver();
    void update(std::string context);
    std::string get_name();

private:
    void report_observer(std::string report);

};

class HexObserver : public IObserver
{
public:
    HexObserver();
    ~HexObserver();

    void update(std::string context);
    std::string get_name();

private:
    void report_observer(std::string report);

};

#endif