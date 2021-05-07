/**********************************************************************
 * 文件名: builder_pattern.h
 * 
 * @功能描述:建造者模式 使用多个简单的对象一步一步构建成一个复杂的对象，它提供了一种
    创建对象的最佳方式
 * @意图：
    将一个复杂的构建与其表示相分离，使得同样的构建过程可以创建不同的表示
 * @主要解决:
    主要解决在软件系统中，有时候面临着”一个复杂对象”的创建工作，其通常由各个部分的子对
    象用一定的算法构成，由于需求的变化，这个复杂对象的各个部分经常面临这剧烈的变化，但
    是将他们组合在一起的算法却相对稳定
 * @应用实例：
    1.区肯德基，汉堡，可乐，薯条，炸鸡翅等是不变的，而其组合是经常变化的，生成出所谓的
    “套餐”
 * @优点：
    1.建造者独立，易扩展
    2.便于控制细节风险
 * @风险：
    1.产品必须有共同点，范围有限制
    2.如内部变化复杂，会有很多的建造类
 * 
 * 
 ********************************************************************/
#ifndef BUILDER_PATTERN_H
#define BUILDER_PATTERN_H
#include <iostream>
#include <vector>
#include <string>

class Product
{
public:
    Product(){}
    ~Product(){}

    void add(std::string str)
    {
        m_vec.push_back(str);
    }

    void show()
    {
        for(auto it = m_vec.cbegin(); it != m_vec.cend(); it++)
        {
            std::cout << *it << std::endl;
        }
    }

private:
    std::vector<std::string> m_vec;
};


class Builder
{
public:
    virtual void build_parta() = 0;
    virtual void build_partb() = 0;
    virtual void build_partc() = 0;
    virtual Product get_result() = 0;

    Builder(){}
    ~Builder(){}
};

class ConcreteBuilder0 : public Builder
{
public:
    ConcreteBuilder0() : m_p(nullptr)
    {
        m_p = new Product();
    }

    virtual ~ConcreteBuilder0()
    {
        if(nullptr != m_p){
            delete m_p;
        }
    }

    virtual void build_parta()
    {
        std::string str = "Builder0 buildparta";
        m_p->add(str);
    }

    virtual void build_partb()
    {
       std::string str = "builder0 buildpartb";
       m_p->add(str); 
    }

    virtual void build_partc()
    {
        std::string str = "builder0 buildpartc";
        m_p->add(str);
    }

    Product get_result()
    {
        return *m_p;  
    }

private:
    Product *m_p;
};

class ConcreteBuilder1 : public Builder
{
public:
    ConcreteBuilder1()
    {
        m_p = new Product();
    }
    ~ConcreteBuilder1()
    {
        if(nullptr != m_p){
            delete m_p;
        }
    }

    virtual void build_parta()
    {
        std::string str = "builder1 buildparta";
        m_p->add(str);
    }

    virtual void build_partb()
    {
        std::string str = "builder1 buildpartb";
        m_p->add(str);
    }

    virtual void build_partc()
    {
        std::string str = "builder1 buildpartc";
        m_p->add(str);
    }

    Product get_result()
    {
        return *m_p;
    }

private:
    Product *m_p;
};

class Director
{
public:
    Director(){}
    ~Director(){}
    void build(Builder *p)
    {
        p->build_parta();
        p->build_partb();
        p->build_partc();
    }
};

#endif