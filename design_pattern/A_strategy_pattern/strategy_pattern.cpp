#include <iostream>
#include "strategy_pattern.h"


int main(int argc,char **argv)
{
    Context *pcontext = nullptr;
    pcontext = new Context(new OperationAdd());
    int  tmp = 0;
    tmp = pcontext->Operator(10, 11);
    std::cout << "tmp:" << tmp << std::endl;
    
    pcontext = new Context(new OperationSubstract());
    tmp = pcontext->Operator(10, 11);
    std::cout << "tmp:" << tmp << std::endl;

    pcontext = new Context(new OperationMultiply());
    tmp = pcontext->Operator(10, 11);
    std::cout << "tmp:" << tmp << std::endl;

    return 0;
}