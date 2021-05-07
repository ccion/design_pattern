/**************************************************************
 * 文件名: proxy_pattern.h
 * 
 * @功能描述:在代理模式中，一个类代表另一个类的功能，在代理模式中，我们创建
       具有对象的对象，以便向外界提供接口
 * @意图:
      为其他对象提供一种代理以控制这个对象的访问
 * @主要解决:
      在直接访问对象时带来的问题，比如说:要访问的对象在远程的机器上，在面向
    对象系统中，有些对象由于某些原因(比如对象创建开销很大,或者某些操作需要安全
    控制，或者需要进程外的访问)，直接访问会给使用者或者系统结构带来很多麻烦，
    我们可以在访问此对象时加上一个对此对象的访问层
 * @何时使用:
       想在访问一个类时做一些控制
 * @应用实例:
      1.windows里面的快捷方式
      2.买火车票不一定在火车站买，也可以去代售点
      3.一张支票或银行存单是账户中资金的代理，支票在市场交易中用来代替现金，
      并提供对签发人账号上资金的控制
 * @优点:
      1.职责清晰
      2.高扩展性
      3.智能化
 * @缺点:
      1.由于在客户端和真实主题之间增加了代理对象，因此有些类型的代理模式可能
      会造成请求的处理速度变慢
      2.实现代理模式需要额外的工作，有些代理模式的实现非常复杂
 **************************************************************/
#ifndef PROXY_PATTERN_H
#define PROXY_PATTERN_H
#include <iostream>

class Image
{
public:
    Image(std::string name) : m_name(name) {}
    virtual ~Image() {}

    /*显示文档的函数*/
    virtual void show() = 0;

protected:
    /*文档名*/
    std::string m_name;
};

/*大型实体类*/
class BigImage : public Image
{
public:
    BigImage(std::string name) : Image(name) {}
    virtual ~BigImage() {}

    void show()
    {
        std::cout << "This is Big Image..." << std::endl;
        std::cout << "Image name:" << m_name << std::endl;
    }
};

/*大型图片代理器*/
class BigImageProxy : public Image
{
public:
    BigImageProxy(std::string name) : Image(name), m_bigimage(nullptr){}
    virtual ~BigImageProxy()
    {
        if(nullptr != m_bigimage)
        {
            delete m_bigimage;
        }
    }

    void show()
    {
        if(this->m_bigimage == nullptr)
        {
            m_bigimage = new BigImage(this->m_name);
        }
        m_bigimage->show();
    }

private:
    BigImage *m_bigimage;
};

#endif