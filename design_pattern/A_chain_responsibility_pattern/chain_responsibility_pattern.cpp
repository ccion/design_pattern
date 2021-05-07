#include "chain_responsibility_pattern.h"


CWomen::CWomen(int type, std::string request)
{
    m_type = type;
    switch (m_type)
    {
    case 1:
        m_request.append("女儿的请求是:");
        m_request.append(request);
        break;
    
    case 2:
        m_request.append("妻子的请求是:");
        m_request.append(request);
        break;
    
    case 3:
        m_request.append("母亲的请求是:");
        m_request.append(request);
        break;
    
    default:
        break;
    }
}

CWomen::~CWomen()
{

}

int CWomen::get_type()
{
    return m_type;
}

std::string CWomen::get_request()
{
    return m_request;
}

CHandler::CHandler(int level) : m_level(level)
{
    m_pnexthandler = NULL;
}
CHandler::~CHandler()
{
    
}

void CHandler::handle_message(IWomen *pwomen)
{
    if(pwomen->get_type() == m_level){
        response(pwomen);
    }else{
        if(m_pnexthandler != nullptr){
            m_pnexthandler->handle_message(pwomen);
        }else{
            std::cout << "------没地方请示了，不做处理！----" << std::endl;
        }
    }
}

void CHandler::set_next(CHandler *phandler)
{
    m_pnexthandler = phandler;
}

CFather::CFather() :CHandler(1)
{

}

CFather::~CFather()
{

}

void CFather::response(IWomen *pwomen)
{
    std::cout << "女儿向父亲请示："  << std::endl;
    std::cout << pwomen->get_request().c_str() << std::endl;
    std::cout << "父亲的答复是:同意" << std::endl;
}

CHusband::CHusband() : CHandler(2)
{

}

CHusband::~CHusband()
{

}

void CHusband::response(IWomen *pwomen)
{
    std::cout << "妻子向丈夫请示:" << std::endl;
    std::cout << pwomen->get_request().c_str() << std::endl;
    std::cout << "丈夫的答复是:同意" << std::endl;
}

CSon::CSon() : CHandler(3)
{

}

CSon::~CSon()
{

}

void CSon::response(IWomen *pwomen)
{
    std::cout << "母亲向儿子请示:" << std::endl;
    std::cout << pwomen->get_request().c_str() << std::endl;
    std::cout << "儿子的答复是:同意"  << std::endl;
}

