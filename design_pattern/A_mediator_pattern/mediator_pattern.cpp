#include "mediator_pattern.h"


int main(int argv,char **argc)
{
    //mediator pattern
    ConcreteMediator *p = new ConcreteMediator();
    Colleague *p1 = new ConcreteColleague0(p);
    Colleague *p2 = new ConcreteColleague1(p);

    p->add_colleague(p1, p2);
    std::cout << "Colleagueo发送消息:你下班了吗?" << std::endl;
    p1->send("你下班了吗?");
    std::cout << "Colleague1发送消息:没呢，你呢?" << std::endl;
    p2->send("没呢，你呢?");
    delete p1;
    delete p2;
    delete p;

    return 0;
}