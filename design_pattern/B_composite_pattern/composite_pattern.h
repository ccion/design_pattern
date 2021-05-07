/*****************************************************************************
 * 文件名: composite_pattern.h
 * 
 * @功能描述:组合模式，又叫整体模式，是用于把一组相似的对象当做一个单一的对象，组合模式依据
     树形结构来组合，用来表示部分以及整体层次
 *
 * @意图：
     将对象组合合成树形结构以表示"部分-整体"的层次结构，组合模式使得用户对单个对象和组合对象
    的使用具有一致性
 * @主要解决：
      它在我们树型结构的问题中，模糊了简单元素和复杂元素的概念，客户程序可以像处理简单元素一样
    来处理复杂元素，从而使得客户程序与复杂元素的内部结构解耦
 * @何时使用：
      1.您想表示对象的部分-整体层次结构(树形结构)
      2.您希望用户忽略组合对象与单个对象的不同，用户将统一地使用组合结构中的所有对象
 * @如何解决:
    树枝和叶子实现统一接口，树枝内部组合该接口
 * @应用实例：
    1.算术表达式包括操作数，操作符和另一个操作数，其中，另一个操作符也可以是操作数，操作符
    和另一个操作数
 *  @优点：
    1.高层模块调用简单
    2.节点自由增加
 *  @缺点：
    在使用组合模式时，其叶子和树枝的声明都是实现类，而不是接口，违反了依赖倒置原则
 * 
 * *************************************************************************/
#ifndef COMPOSITE_PATTERN_H
#define COMPOSITE_PATTERN_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class Component
{
public:
    Component(std::string str)
    {
        m_str = str;
    }
    virtual ~Component(){}

    virtual void add(Component *param) = 0;
    virtual void remove(Component *param) = 0;
    virtual void display() = 0;

protected:
    std::string m_str;
};

class Leaf : public Component
{
public:
    Leaf(std::string str) : Component(str) {}

    ~Leaf() {}

    void add(Component *param)
    {
        std::cout << "Leaf cannot add" << std::endl;
    }

    void remove(Component *param)
    {
        std::cout << "Leaf cannot remove" << std::endl;
    }

    void display()
    {
        std::cout << m_str << std::endl;
    }

};

class Composite : public Component
{
public:
    Composite(std::string str) : Component(str) {}
    ~Composite()
    {
        if(!m_vec.empty())
        {
            m_vec.clear();
        }
    }

    void add(Component *param)
    {
        auto it = find_if(m_vec.begin(), m_vec.end(),
            [param](std::shared_ptr<Component> ptr){return param == ptr.get();});
        
        if(it == m_vec.end())
        {
            m_vec.push_back(std::shared_ptr<Component>(param));
        }
    }

    void remove(Component *param)
    {
        auto it = find_if(m_vec.begin(), m_vec.end(),
             [param](std::shared_ptr<Component> ptr){return param == ptr.get();});
        if(it == m_vec.end())
        {
            return;
        }

        m_vec.erase(it);
    }

    void display()
    {
        for(auto it = m_vec.cbegin(); it != m_vec.cend(); it++){
            (*it)->display();
        }
    }

private:
    std::vector<std::shared_ptr<Component>> m_vec;
};

#endif
