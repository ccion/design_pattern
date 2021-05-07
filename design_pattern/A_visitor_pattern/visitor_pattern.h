/*****************************************************************************
 * 文件名: command_pattern.h
 * 
 * @功能描述:使用一个访问类，它改变了元素类的执行算法，通过这种方式，元素的执行算法可以随着访问
 *   者改变而改变
 * @意图: 主要将数据结构与数据操作分离
 * @主要解决:
 *       稳定的数据结构和易变的操作耦合问题
 *@何时使用：需要对一个对象结构中的对象进行很多不同的并且不相关的操作，而需要避免让这些操作
 *“污染”这些对象的类，使用访问者模式将这些封装到类中
 *@如何解决:在被访问的类里面加一个对外提供接待访问者的接口
 *@关键代码:在数据基础类里面有一个方法接受访问者，将自身引用传入访问者
 * @应用实例:您在朋友家做客，您是访问者，朋友接受您的访问，您通过朋友的描述，然后对朋友的描述
 * 做出一个判断，这就是访问者模式
 * @优点:
 *   1.符合单一职责原则
 *   2.优秀的扩展性
 *   3.灵活性
 * @缺点:
 *   1.具体元素对访问者公布细节，违反了迪米特原则
 *   2.具体元素变更比较困难
 *   3.违反了依赖倒置原则,依赖了具体类，没有依赖抽象
 * 
 * *************************************************************************/
#ifndef VISITOR_PATTERN_H
#define VISITOR_PATTERN_H
#include <iostream>
#include <string>
#include <vector>

class Visitor;

class Element
{
public:
    Element(std::string str)
    {
        m_str = str;
    }
    virtual ~Element() {}

    std::string get_name()
    {
        return m_str;
    }

    virtual void accept(Visitor *visitor) = 0;

protected:
    std::string  m_str;
};

class ConcreteElementA : public Element
{
public:
    ConcreteElementA(std::string str) : Element(str) {}
    ~ConcreteElementA(){}

    void accept(Visitor *visitor);
};

class ConcreteElementB : public Element
{
public:
    ConcreteElementB(std::string str) : Element(str) {}
    ~ConcreteElementB() {}

    void accept(Visitor *visitor);
};

class Visitor
{
public:
    Visitor() {}
    virtual ~Visitor() {}
    virtual void visit_concreteelementa(ConcreteElementA *p) = 0;
    virtual void visit_concreteelementb(ConcreteElementB *p) = 0;
};

class ConcreteVisitorA : public Visitor
{
public:
    ConcreteVisitorA() {}
    ~ConcreteVisitorA() {}

    void visit_concreteelementa(ConcreteElementA *p)
    {
        std::cout << "ConcreteVisitorA 访问了" << p->get_name() << std::endl;
    }

    void visit_concreteelementb(ConcreteElementB *p)
    {
        std::cout << "ConcreteVisitorA 访问了" << p->get_name() << std::endl;
    }
};

class ConcreteVisitorB : public Visitor
{
public:
    ConcreteVisitorB(){}
    ~ConcreteVisitorB() {}

    void visit_concreteelementa(ConcreteElementA *p)
    {
        std::cout << "ConcreteVisitorB 访问了" << p->get_name() << std::endl;
    }

    void visit_concreteelementb(ConcreteElementB *p)
    {
        std::cout << "ConcreteVisitorB 访问了" << p->get_name() << std::endl;
    }
};

//聚集类
class ObjectStructure
{
public:
    ObjectStructure() {}
    ~ObjectStructure()
    {
        for(auto it = m_vec.begin(); it != m_vec.end(); it++)
        {
            delete *it;
        }
        m_vec.clear();
    }

    void add(Element *p)
    {
        m_vec.push_back(p);
    }

    void accept(Visitor *visitor)
    {
        for(auto it = m_vec.cbegin(); it != m_vec.cend(); it++)
        {
            (*it)->accept(visitor);
        }
    }
private:
    std::vector<Element *> m_vec;
};

void ConcreteElementA::accept(Visitor *visitor)
{
    visitor->visit_concreteelementa(this);
}

void ConcreteElementB::accept(Visitor *visitor)
{
    visitor->visit_concreteelementb(this);
}

#endif