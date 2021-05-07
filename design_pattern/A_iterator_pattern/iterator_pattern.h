/*****************************************************************************
 * 文件名: iterator_pattern.h
 * 
 * @功能描述:用于顺序访问集合对象的元素，不需要知道集合对象的底层表示
 * @意图:提供一种方法顺序访问一个聚合对象中各个元素，而又无须暴露该对象的内部表示
 * @主要解决:不同的方式来遍历整个整合对象
 * @何时使用:遍历一个聚合对象
 * ＠如何解决:
 *      把在元素之间游走的责任交给迭代器，而不是聚合对象
 * @优点:
 * 1.它支持以不同的方式遍历一个聚合对象;
 * 2.迭代器简化了聚合类;
 * 3.在同一个聚合上可以有多个遍历;
 * 4.在迭代器模式中，增加新的聚合类和迭代器都很方便，无须修改原有代码
 * @缺点：
 *  由于迭代器模式将存储数据b遍历数据的职责分离，增加新的聚合类需要对象增加新的迭代器类，类的个数成对
 * 增加，这在一定程度上增加了系统的复杂性
 * @使用场景:
 * 1.访问一个聚合对象的内容而无须暴露它的内部表示
 * 2.需要为聚合对象提供多种遍历方式;
 * 3.为遍历不同的聚合结构提供一个统一的接口
 * *************************************************************************/
#ifndef ITERATOR_PATTERN_H
#define ITERATOR_PATTERN_H
#include <iostream>
#include <vector>

template <typename Item>
class Iterator
{
public:
    Iterator() {}
    virtual ~Iterator() {}

    virtual void first() = 0;
    virtual void next() = 0;
    virtual Item *cur_item() = 0;
    virtual bool  is_done() = 0;
};

template<typename Item>
class Aggregate;

template<typename Item>
class ConcreteIterator : public Iterator<Item>
{
public:
    ConcreteIterator(Aggregate<Item> *arg) : m_arg(arg), m_cur(0) {}
    virtual ~ConcreteIterator() {}

    virtual void first(){  m_cur = 0;}
    virtual void next()
    {
        if(m_cur < m_arg->get_size()){
            m_cur++;
        } 
    }
    virtual Item* cur_item()
    {
        if(m_cur < m_arg->get_size())
        {
            return &(*m_arg)[m_cur];
        }else{
            return nullptr;
        }    
    }
    virtual bool is_done()
    {
        return (m_cur >= m_arg->get_size());
    }
private:
    Aggregate<Item> *m_arg;
    int  m_cur;
};

template<typename Item>
class Aggregate
{
public:
    Aggregate() {}
    virtual ~Aggregate() {}

    virtual void push_data(Item item) = 0;
    virtual Iterator<Item>* create_iterator() = 0;
    virtual Item& operator[](int index) = 0;
    virtual int get_size() = 0;

};

template<typename Item>
class ConcreteAggregate : public Aggregate<Item>
{
public:
    ConcreteAggregate() {}
   ~ConcreteAggregate() {}

    void push_data(Item item)
    {
       m_data.push_back(item); 
    }
    Iterator<Item>* create_iterator()
    {
       return new ConcreteIterator<Item>(this); 
    }
    Item& operator[](int index)
    {
       return m_data[index]; 
    }
    int get_size()
    {
       return m_data.size(); 
    }

private:
    std::vector<Item> m_data;

};

#endif