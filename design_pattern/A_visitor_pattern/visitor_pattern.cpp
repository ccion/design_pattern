#include "visitor_pattern.h"



int main(int argc,char **argv)
{
    //访问者模式
    ObjectStructure *instance = new ObjectStructure();
    instance->add(new ConcreteElementA("A"));
    instance->add(new ConcreteElementB("B"));

    ConcreteVisitorA *pvisitora = new ConcreteVisitorA();
    ConcreteVisitorB *pvisitorb = new ConcreteVisitorB();

    instance->accept(pvisitora);
    instance->accept(pvisitorb);

    delete pvisitora;
    delete pvisitorb;
    delete instance;

    return 0;
}