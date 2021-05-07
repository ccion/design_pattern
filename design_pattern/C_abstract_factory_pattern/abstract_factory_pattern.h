/**********************************************************************
 * 文件名: abstract_factory_pattern.h
 * 
 * @功能描述:抽象工厂模式是围绕一个超级工厂创建其他工厂，在抽象工厂模式中，接口是负责
    创建一个相关对象的工厂，不需要显示指定它们的类，每个生成的工厂都能按照工厂模式提供
    对象
 * @意图：
    提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类
 * @主要解决:
    主要解决接口选择的问题
 * @应用实例：
    工作了，为了参加一些聚会，肯定有两套或多套衣服，比如说有商务装(成套，一系列具体产品)
    时尚装(成套，一系列具体产品)，甚至对于一个家庭来说，可能有商务女装，商务男装，时尚
    女装，时尚男装，这些也都是成套的，即一系列具体产品
 * @优点：
    1.当一个产品族中的多个对象被设计成一起工作时，它能保证客户端始终只使用同一个产品族
    中的对象
 * @缺点：
    1.产品族扩展非常困难，要增加一个系列的某一产品，既要在抽象的creator里面加代码，
    又要在具体的里面加代码
 * 
 ********************************************************************/
#ifndef ABSTRACT_FACTORY_PATTERN_H
#define ABSTRACT_FACTORY_PATTERN_H
#include <iostream>
enum SOAPTYPE{SFJ, XSL, NAS};
enum TOOTHTYPE{HR, ZH};

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

class NASSoap : public SoapBase
{
public:
    NASSoap() {}
    ~NASSoap() {}

    void show()
    {
        std::cout << "NAS Soap!" << std::endl;
    }
};

class ToothBase
{
public:
    ToothBase(){}
    virtual ~ToothBase(){}
    virtual void show() = 0;
};

class HRTooth : public ToothBase
{
public:
    HRTooth(){}
    ~HRTooth(){}

    void show()
    {
        std::cout << "Hei ren Toothpaste!" << std::endl;
    }
};

class ChinaTooth : public ToothBase
{
public:
    ChinaTooth(){}
    ~ChinaTooth(){}

    void show()
    {
        std::cout << "China Toothpaste!" << std::endl;
    }
};

class FactoryBase
{
public:
    FactoryBase(){}
    virtual ~FactoryBase(){}

    virtual SoapBase* create_soap() = 0;
    virtual ToothBase* create_toothpaste() = 0;
};

class FactoryA : public FactoryBase
{
public:
    FactoryA(){}
    ~FactoryA(){}
    SoapBase* create_soap()
    {
        return new SFJSoap();
    }

    ToothBase* create_toothpaste()
    {
        return new HRTooth();
    }
};

class FactoryB : public FactoryBase
{
public:
    FactoryB(){}
    ~FactoryB(){}
    SoapBase* create_soap()
    {
        return new NASSoap();
    }

    ToothBase* create_toothpaste()
    {
        return new ChinaTooth();
    }

};

#endif