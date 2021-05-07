/******************************************************************
 * 文件名: factory_pattern.h
 * 
 * @功能描述:工厂模式，提供了一种创建对象的最佳方式，在工厂模式中，我们在创建
    对象时不会对客户端暴露创建逻辑，并且是通过使用一个共同的接口来指向新创建的
    对象
 * @意图
    定义一个创建对象的接口，让其子类自己决定实例化哪一个工厂类，工厂模式使其创建
    过程延迟到子类进行
 * @主要解决:
     主要解决接口选择的问题
 * @应用实例:
    1.您需要一辆汽车，可以直接从工厂里面提货，而不用去管这辆汽车式怎么做出来的，
    以及这个汽车里面的具体实现
 * @优点：
    1.一个调用者想创建一个对象，只要知道其名称就可以了
    2.扩展性高，如果想增加一个产品，只要扩展一个工厂类就可以
    3.屏蔽产品的具体实现，调用者只关心产品的接口
 * @缺点：
    1.每次增加一个产品时，都需要增加一个具体类和对象实现工厂，使得系统中类的个数
    成倍增加，在一定程度上增加了系统的复杂度，同时也增加了系统具体类的依赖
 * 
 *****************************************************************/
#ifndef FACTORY_PATTERN_H
#define FACTORY_PATTERN_H
#include <iostream>

class Car
{
public:
    Car() {}
    virtual ~Car() {}

    virtual void created_car() = 0;
};

class BenzCar : public  Car
{
public:
    BenzCar()
    {
       std::cout << "benz car constructors" << std::endl;
    }
    ~BenzCar() {}

    virtual void created_car()
    {
        std::cout << "benz car created car" << std::endl;
    }
};

class BmwCar : public Car
{
public:
    BmwCar()
    {
        std::cout << "bmw car constructors" << std::endl;
    }
    ~BmwCar(){}

    virtual void created_car()
    {
        std::cout << "bmw car created car" << std::endl;
    }
};

class Factory
{
public:
    Factory(){}
    virtual ~Factory() {}
    virtual Car* create_specific_car() = 0;
};

class BenzFactory : public Factory
{
public:
    BenzFactory(){}
    ~BenzFactory() {}

    virtual Car* create_specific_car()
    {
        return (new BenzCar());
    }
};

class BmwFactory : public Factory
{
public:
    BmwFactory() {}
    ~BmwFactory() {}

    virtual Car* create_specific_car()
    {
        return (new BmwCar());
    }
};

#endif