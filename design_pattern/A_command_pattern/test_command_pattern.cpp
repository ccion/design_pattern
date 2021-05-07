#include "command_pattern.h"


void old_way()
{
    std::cout << "--------客户想增加一个需求----------" << std::endl;
    IGroup *rg = new CRequirementGroup();
    rg->find();
    rg->add();
    rg->plan();
    delete rg;

    std::cout << "-------客户又想修改一个页面---------" << std::endl;
    IGroup *pg = new CPageGroup();
    pg->find();
    pg->add();
    pg->plan();
    delete pg;

    std::cout << "------客户又想删除一个功能----------" << std::endl;
    IGroup *cg = new CCodeGroup();
    cg->find();
    cg->add();
    cg->plan();
    delete cg;
}

void new_way()
{
    std::cout << "------客户觉得烦了，希望只找一个人，并告诉他要做什么----" << std::endl;
    std::cout << "------客户要求增加一项需求---------" << std::endl;
    CInvoker gary;
    ICommand *pcommand = new CAddRequirementCommand();
    gary.set_command(pcommand);
    gary.action();
    delete pcommand;

    std::cout << "-----客户要求删除一个页面---------" << std::endl;
    CInvoker ricky;
    ICommand *pcommand2 = new CDeletePageCommand();
    ricky.set_command(pcommand2);
    ricky.action();
    delete pcommand2;
    std::cout << "---- end ----" << std::endl;

}

int main(int argc, char** argv)
{
    //客户原来的运行流程
    old_way();

    //客户觉得麻烦了，每次改动都要找不同的组，谈不同的事
    //客户只想找一个人，告诉他要做什么就可以，不想关心由哪几个组来做和怎么做
    new_way();

    return 0;
}