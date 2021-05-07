/*****************************************************************************
 * 文件名: command_pattern.h
 * 
 * @功能描述:是一种数据驱动的设计模式，它属于行为模式，请求以命令的形式包裹在对象中，并传给调用
 *   对象。调用对象寻找可以处理该命令的合适对象，并把该命令传给相应的对象，该对象执行命令
 * 
 * @意图:将一个请求封装成一个对象，从而使你可以用不同的请求对客户进行参数化
 * @主要解决:在软件系统中，行为请求者与行为实现者通常是一种紧耦合的关系，但某些场合，比如需要
 * 对行为进行记录，撤销或重做，事务等处理时，这种无法抵御变化的紧耦合的设计就不太合适
 * @优点：
 *   1.降低了系统耦合度;
 *   2.新的命令可以很容易添加到系统中去
 *@缺点:
 *  1.使用命令模式可能会导致某些系统有过多的具体命令类
 * 
 * 
 * *************************************************************************/
#ifndef COMMAND_PATTERN_H
#define COMMAND_PATTERN_H
#include <iostream>

class ICommand;

class CInvoker
{
public:
    CInvoker();
    ~CInvoker();
    void set_command(ICommand *pcommand);
    void action();

private:
    ICommand *m_pcommand;

};

class IGroup
{
public:
    IGroup()
    {

    }
    virtual ~IGroup()
    {

    }

    virtual void find() = 0;
    virtual void add() = 0;
    virtual void erase() = 0;
    virtual void change() = 0;
    virtual void plan() = 0;
};

class CRequirementGroup : public IGroup
{
public:
    CRequirementGroup();
    ~CRequirementGroup();

    void find();
    void add();
    void erase();
    void change();
    void plan();
};

class CPageGroup : public IGroup
{
public:
    CPageGroup();
    ~CPageGroup();

    void find();
    void add();
    void erase();
    void change();
    void plan();
};

class CCodeGroup : public IGroup
{
public:
    CCodeGroup();
    ~CCodeGroup();

    void find();
    void add();
    void erase();
    void change();
    void plan();
};

class ICommand
{
public:
    ICommand();
    virtual ~ICommand();

    virtual void execute() = 0;

protected:
    CRequirementGroup *m_prg;
    CPageGroup        *m_ppg;
    CCodeGroup        *m_pcg;
};

class CAddRequirementCommand : public ICommand
{
public:
    CAddRequirementCommand();
    ~CAddRequirementCommand();
    void execute();
};

class CDeletePageCommand : public ICommand
{
public:
    CDeletePageCommand();
    ~CDeletePageCommand();
    void execute();
};

#endif