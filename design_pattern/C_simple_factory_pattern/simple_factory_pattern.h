/******************************************************************
 * 文件名: simple_factory_pattern.h
 * 
 * @功能描述:
 * 1)工厂类角色：这是本模式的核心，含有一定的商业逻辑和判断逻辑
 * 2）抽象产品角色：它一般是具体产品继承的父类或者实现的接口
 * 3）具体产品角色：工厂类所创建的对象就是此角色的实例
 * 
 * @缺点:
    1.对修改不封闭，新增加产品您要修改工厂，违反了鼎鼎大名的开闭法则(OCP)
 * 
 *****************************************************************/
#ifndef SIMPLE_FACTORY_PATTERN_H
#define SIMPLE_FACTORY_PATTERN_H
#include <iostream>
enum PRODUCTTYPE {SFJ, XSL, NAS};

class SoapBase
{
public:
    SoapBase(){}
    virtual ~SoapBase(){}

    virtual void show() = 0;
};

class SFJSoap : public SoapBase
{
public:
    SFJSoap() {}
    ~SFJSoap() {}

    void show()
    {
        std::cout << "SFJ Soap!" << std::endl;
    }
};

class XSLSoap : public SoapBase
{
public:
    XSLSoap(){}
    ~XSLSoap(){}

    void show()
    {
        std::cout << "XSL Soap!" << std::endl;
    }
};

class NASSoap : public SoapBase
{
public:
    NASSoap(){}
    ~NASSoap(){}

    void show()
    {
        std::cout << "NAS Soap!" << std::endl;
    }
};

class Factory
{
public:
    Factory() {}
    ~Factory() {}
    SoapBase* create_soap(PRODUCTTYPE type)
    {
        switch (type)
        {
        case SFJ:
            return new SFJSoap();
            break;
        case XSL:
            return new XSLSoap();
            break;
        case NAS:
            return new NASSoap();
            break;
        default:
            break;
        }
        return nullptr;
    }
};



#endif