/*****************************************************************************
 * 文件名: chain_responsibility_pattern.h
 * 
 * @功能描述:为请求创建了一个接收者对象的链，这种模式给予请求的类型，对请求的发送者和接收者
 * 进行解耦，在这种模式中，通常每个接收者都包含对另一个接收者的引用。如果一个对象不能处理该
 * 请求，那么它就会把相同的请求传给下一个接收者，依次类推
 * 
 * @意图:避免请求发送者和接收者耦合在一起，让多个对象都有可能接受请求，将这些对象连接成一条
 * 链，并且沿着这条链传递请求，直到有对象处理它为止
 * 
 * @主要解决:职责链上的处理者负责处理请求，客户只需要将请求发送到责任链上即可，无须关心请求
 * 的处理细节和请求的传递，所以责任链将请求的发送者和请求的处理者解耦了
 * 
 * @何时使用:在处理消息的时候以过滤很多道
 * @如何解决:拦截的类都实现统一接口
 * @应用实例:
 * 1.红楼梦中的"击鼓传花"
 * 2.JS中的事件冒泡
 * 
 * @优点:
 * 1.降低耦合度，它将请求的发送者和接收者解耦
 * 2.简化了对象，使得对象不需要知道链的结构
 * 3.增强给对象指派职责的灵活性，通过改变链内的成员或者调动它们的次序，允许动态地新增或者删除责任
 * 4.增加新的请求处理类很方便
 * @缺点:
 * 1.不能保证请求一定被接受
 * 2.系统性能将受到一定影响，而且在进行代码调试时不方便，可能会造成循环调用
 * 3.可能不容易观察运行时的特征，有碍于除错
 * @使用场景:
 * 1.有多个对象可以处理同一个请求，具体那个对象处理该请求由运行时刻自动确定
 * 2.在不明确指定接收者的情况下，向多个对象中的一个提交一个请求
 * *************************************************************************/
#ifndef CHAIN_RESPONSIBILITY_PATTERN_H
#define CHAIN_RESPONSIBILITY_PATTERN_H
#include <string>
#include <iostream>

class IWomen
{
public:
    IWomen() {}
    virtual ~IWomen(){}

    virtual int get_type() = 0;
    virtual std::string get_request() = 0;
};

class CWomen : public IWomen
{
public:
    CWomen(int type, std::string request);
    ~CWomen();

    int get_type();
    std::string get_request();

private:
    int m_type;
    std::string m_request;
};

class CHandler
{
public:
    CHandler(int level);
    virtual ~CHandler();
    void handle_message(IWomen *pwomen);
    void set_next(CHandler *phandler);
    virtual void  response(IWomen *pwomen) = 0;

private:
    int  m_level;
    CHandler *m_pnexthandler;
};

class CFather : public CHandler
{
public:
    CFather();
    ~CFather();
    void response(IWomen *pwomen);

};

class CHusband : public CHandler
{
public:
    CHusband();
    ~CHusband();
    void response(IWomen *pwomen);

};

class CSon: public CHandler
{
public:
    CSon();
    ~CSon();
    void response(IWomen *pwomen);
};


#endif