#include "command_pattern.h"

CInvoker::CInvoker()
{

}

CInvoker::~CInvoker()
{

}

void CInvoker::set_command(ICommand *pcommand)
{
    m_pcommand = pcommand;
}

void CInvoker::action()
{
    m_pcommand->execute();
}

CRequirementGroup::CRequirementGroup()
{

}

CRequirementGroup::~CRequirementGroup()
{

}

void CRequirementGroup::find()
{
    std::cout << "找到需求组..." << std::endl;
}

void CRequirementGroup::add()
{
    std::cout << "客户要求增加一项需求..." << std::endl;
}

void CRequirementGroup::erase()
{
    std::cout << "客户要求删除一项需求..." << std::endl;
}

void CRequirementGroup::change()
{
    std::cout << "客户要求修改一项需求..." << std::endl;
}

void CRequirementGroup::plan()
{
    std::cout << "客户要求需求变更计划..." << std::endl;
}

CPageGroup::CPageGroup()
{

}

CPageGroup::~CPageGroup()
{

}

void CPageGroup::find()
{
    std::cout << "找到美工组..." << std::endl;
}

void CPageGroup::add()
{
    std::cout << "客户要求增加一个页面..." << std::endl;
}

void CPageGroup::erase()
{
    std::cout << "客户要求删除一个页面..." << std::endl;
}

void CPageGroup::change()
{
    std::cout << "客户要求修改一个页面..." << std::endl;
}

void CPageGroup::plan()
{
    std::cout << "客户要求页面变更计划..." << std::endl;
}

CCodeGroup::CCodeGroup()
{

}

CCodeGroup::~CCodeGroup()
{

}

void CCodeGroup::find()
{
    std::cout << "找到代码组..." << std::endl;
}

void CCodeGroup::add()
{
    std::cout << "客户要求增加一项功能..." << std::endl;
}

void CCodeGroup::erase()
{
    std::cout << "客户要求删除一项功能..." << std::endl;
}

void CCodeGroup::change()
{
    std::cout << "客户要求修改一项功能..." << std::endl;
}

void CCodeGroup::plan()
{
    std::cout << "客户要求代码变更计划..." << std::endl;
}

ICommand::ICommand()
{
    m_prg = new CRequirementGroup();
    m_ppg = new CPageGroup();
    m_pcg = new CCodeGroup();
}

ICommand::~ICommand()
{
    if(m_prg != nullptr){
        delete m_prg;
    }
    if(m_ppg != nullptr){
        delete m_ppg;
    }
    if(m_pcg != nullptr){
        delete m_pcg;
    }
}

CAddRequirementCommand::CAddRequirementCommand()
{

}

CAddRequirementCommand::~CAddRequirementCommand()
{

}

void CAddRequirementCommand::execute()
{
    //执行增加一项需求的命令
    ICommand::m_prg->find();

    //增加一份需求
    ICommand::m_prg->add();

    //给出计划
    ICommand::m_prg->plan();
}

CDeletePageCommand::CDeletePageCommand()
{

}

CDeletePageCommand::~CDeletePageCommand()
{

}

void CDeletePageCommand::execute()
{
    //执行增加一项需求的命令
    ICommand::m_ppg->find();

    //增加一份需求
    ICommand::m_ppg->erase();

    //给出计划
    ICommand::m_ppg->plan();
}