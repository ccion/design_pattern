/*****************************************************************************
 * 文件名: memento_pattern.h
 * 
 * @功能描述:保存一个对象的某个状态，以便在适当的时候恢复对象
 * @意图:
 *    在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态
 * @主要解决:
 *    所谓备忘录模式就是在不破坏封装的前提下，捕获一个对象的内部状态，并在该对象之外
 * 保存这个状态，这样可以在以后将对象恢复到原先保存的状态
 * @何时使用:
 *    很多时候我们总是需要记录一个对象的内部状态，这样做的目的就是为了允许用户取消不确定
 * 或者错误的操作，能够恢复到他原先的状态，使得他有"后悔药"可吃
 * @如何解决:
 *   通过一个备忘录类专门存储对象状态
 * @关键代码:
 *  客户不与备忘录耦合，与备忘录管理类耦合
 * @应用实例:
 *   1.后悔药
 *   2.打游戏时的存档
 * @优点:
 *  1.给用户提供了一种可以恢复状态的机制，可以使用用户能够比较方便地回到某个历史的状态
 *  2.实现了信息的封装，使得用户不需要关心状态的保存细节
 * @缺点:
 *  消耗资源。如果类的成员变量很多，势必会占用比较大的资源，而且每一次保存都会消耗一定的内存
 * @使用场景:
 *  1.需要保存/恢复数据的相关状态场景，
 *  2.提供一个可回滚的操作
 * *************************************************************************/
#ifndef MEMENTO_PATTERN_H
#define MEMENTO_PATTERN_H
#include <iostream>
#include <vector>

class Memento
{
public:
    Memento(std::string state)
    {
        m_state = state;
    }
    ~Memento()
    {

    }

    std::string get_state()
    {
        return m_state;
    }

private:
    std::string m_state;
};

class Originator
{
public:
    Originator() {}
    ~Originator() {}

    void set_state(std::string state)
    {
        m_state = state;
    }

    std::string get_state()
    {
        return m_state;
    }

    Memento* save_state_memento()
    {
        return new Memento(m_state);
    }

    void get_state_from_memento(Memento* memento)
    {
        m_state = memento->get_state();
    }

private:
    std::string m_state;
};

class CareTaker
{
public:
    void add(Memento*  state)
    {
        m_memntovector.push_back(state);
    }

    Memento* get(int index)
    {
        return m_memntovector.at(index);
    }

private:
    std::vector<Memento*>  m_memntovector;
};



#endif