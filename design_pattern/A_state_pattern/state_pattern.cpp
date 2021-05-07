#include "state_pattern.h"

CLiftState::CLiftState()
{

}

CLiftState::~CLiftState()
{

}
void CLiftState::set_context(CContext *pcontext)
{
    m_pcontext = pcontext;
}

CCloseingState::CCloseingState()
{

}

CCloseingState::~CCloseingState()
{

}

void CCloseingState::open()
{
    CLiftState::m_pcontext->set_liftstate(CContext::m_openningstate);
    CLiftState::m_pcontext->get_liftstate()->open();
}

void CCloseingState::close()
{
    std::cout << "电梯门关闭..." << std::endl;
}

void CCloseingState::run()
{
    CLiftState::m_pcontext->set_liftstate(CContext::m_runningstate);
    CLiftState::m_pcontext->get_liftstate()->run();
}

void CCloseingState::stop()
{
    CLiftState::m_pcontext->set_liftstate(CContext::m_stoppingstate);
    CLiftState::m_pcontext->get_liftstate()->stop();
}

COpenningState::COpenningState()
{

}

COpenningState::~COpenningState()
{

}

void COpenningState::open()
{
    std::cout << "电梯门开启..." << std::endl;
}

void COpenningState::close()
{
    CLiftState::m_pcontext->set_liftstate(CContext::m_closeingstate);
    CLiftState::m_pcontext->get_liftstate()->close();
}

void COpenningState::run()
{
    //do nothing
}

void COpenningState::stop()
{
    //do nothing
}

CRunningState::CRunningState()
{

}

CRunningState::~CRunningState()
{

}

void CRunningState::open()
{
    //do nothing
}

void CRunningState::close()
{
    //do nothing
}

void CRunningState::run()
{
    std::cout << "电梯上下跑..." << std::endl;
}

void CRunningState::stop()
{
    CLiftState::m_pcontext->set_liftstate(CContext::m_stoppingstate);
    CLiftState::m_pcontext->get_liftstate()->stop();
}

CStoppingState::CStoppingState()
{

}

CStoppingState::~CStoppingState()
{

}

void CStoppingState::open()
{
    CLiftState::m_pcontext->set_liftstate(CContext::m_openningstate);
    CLiftState::m_pcontext->get_liftstate()->open();
}

void CStoppingState::close()
{
    //do nothing
}

void CStoppingState::run()
{
    CLiftState::m_pcontext->set_liftstate(CContext::m_runningstate);
    CLiftState::m_pcontext->get_liftstate()->run();
}

void CStoppingState::stop()
{
    std::cout << "电梯停止了..." << std::endl;
}

COpenningState* CContext::m_openningstate = nullptr;
CCloseingState* CContext::m_closeingstate = nullptr;
CRunningState* CContext::m_runningstate = nullptr;
CStoppingState* CContext::m_stoppingstate = nullptr;

CContext::CContext()
{
    m_pliftstate = nullptr;
    m_openningstate = new COpenningState();
    m_closeingstate = new CCloseingState();
    m_runningstate = new CRunningState();
    m_stoppingstate = new CStoppingState();
}

CContext::~CContext()
{
    delete m_openningstate;
    m_openningstate = nullptr;
    delete m_closeingstate;
    m_closeingstate = nullptr;
    delete m_runningstate;
    m_runningstate = nullptr;
    delete m_stoppingstate;
    m_stoppingstate = nullptr;
}

CLiftState* CContext::get_liftstate()
{
    return m_pliftstate;
}

void CContext::set_liftstate(CLiftState *pliftstate)
{
    m_pliftstate = pliftstate;
    m_pliftstate->set_context(this);
}

void CContext::open()
{
    m_pliftstate->open();
}

void CContext::close()
{
    m_pliftstate->close();
}

void CContext::run()
{
    m_pliftstate->run();
}

void CContext::stop()
{
    m_pliftstate->stop();
}