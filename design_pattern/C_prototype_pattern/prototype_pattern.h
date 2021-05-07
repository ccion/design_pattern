/******************************************************************
 * 文件名: prototype_pattern.h
 * 
 * @功能描述:原型模式用于创建重复的对象，同时又能保证性能，它提供了一种创建对象
    的最佳方式
 * @意图：用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象
 * @主要解决：
    在运行期建立和删除原型
 * @何时使用：
   1.当一个系统应该独立与它的产品创建，构成和表示时
   2.当要实例化的类是在运行时刻指定时，例如，通过动态装载
   3.为了避免创建一个与产品类层次平行的工厂类层次时
   4.当一个类的实例只有几个不同状态组合中的一种时，建立相应数目的原型并克隆它们
   可能比每次用合适的状态手工实例化该类更方便一些
 * @应用实例：
    1.细胞分裂
 * @优点：
    1.性能提高
    2.逃避构造函数的约束
 * @缺点：
   1.配备克隆方法需要对类的功能进行通盘考虑，这对于全新的类不是很难，但对于已有
   的类不一定很容易，特别当一个类引用不支持串行化的间接对象，或者引用含有循环结构
   的时候
   2.必须实现Clonealbe接口
 * 
 *****************************************************************/
#ifndef PROTOTYPE_PATTERN_H
#define PROTOTYPE_PATTERN_H
#include <iostream>
class CPrototype
{
public:
    CPrototype(){}
    virtual ~CPrototype(){}
    virtual CPrototype* clone() = 0;
};

class CConcretePrototype : public CPrototype
{
public:
    CConcretePrototype() : m_counter(0) {std::cout << "cconcreteprotype" << std::endl;}
    virtual ~CConcretePrototype(){}

    CConcretePrototype(const CConcretePrototype& rhs)
    {
        std::cout << "cconcreteprototype 拷贝构造" << std::endl;
        m_counter = rhs.m_counter;
    }

    virtual CPrototype* clone()
    {
        return new CConcretePrototype(*this);
    }

private:
    int m_counter;
};

#endif