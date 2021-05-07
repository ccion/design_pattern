/*****************************************************************************
 * 文件名: strategy_pattern.h
 * 
 * @功能描述:策略模式，一个类的行为或其算法可以在运行时更改。这种类型的设计模型属于行为型
 *         模式。
 * @意图:定义一系列的算法，把他们一个个封装起来，并且是它们可以相互替换
 * @主要解决:在有多种算法相似的情况下,使用if..else所带来的复杂和难以维护
 * @关键代码：实现同一个接口
 * @应用实例：
 *   (1)诸葛亮的锦囊妙计，每一个锦囊就是一个策略；
 *  （2)旅行的出游方式，选择骑自行车，坐汽车，每一种旅行方式都是一个策略;
 * @优点:
 *   (1)算法可以自由切换；
 *   (2)避免使用多重条件判断；
 *   (3)扩展性良好；
 * @缺点:
 *   (1)策略类会增多；
 *   (2)所有策略类都需要对外暴露；
 * 
 * *************************************************************************/
#ifndef STRATEGY_PATTERN_H
#define STRATEGY_PATTERN_H

/*strategy interface*/
class  IStrategy
{
public:
    IStrategy(){}
    virtual ~IStrategy(){}
    virtual int Operator(int num1, int num2) = 0;
};

/*strategy operation add*/
class OperationAdd : public IStrategy
{
public:
    OperationAdd() {}
    ~OperationAdd() {}

    int Operator(int num1, int num2)
    {
        return (num1 + num2);
    }
};

/*strategy operation substract*/
class OperationSubstract : public IStrategy
{
public:
    OperationSubstract() {}
    ~OperationSubstract() {}

    int Operator(int num1, int num2)
    {
        return (num1 - num2);
    }
};

/*strategy operation multiply*/
class OperationMultiply : public IStrategy
{
public:
    OperationMultiply() {}
    ~OperationMultiply() {}

    int Operator(int num1, int num2)
    {
        return (num1 * num2);
    }
};

class Context
{
public:
    Context(IStrategy *strategy)
    {
        m_strategy = strategy;
    }
    ~Context(){}

    int Operator(int num1, int num2)
    {
        return m_strategy->Operator(num1,num2);
    }

private:
    IStrategy *m_strategy;
};
#endif