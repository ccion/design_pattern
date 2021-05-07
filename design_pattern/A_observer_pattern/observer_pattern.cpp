#include "observer_pattern.h"



void InstanceSubject::add_observer(IObserver *observer)
{
    m_observers.push_back(observer);
}


void InstanceSubject::delete_observer(IObserver *observer)
{
    m_iterator it = m_observers.begin();
    for(; it != m_observers.end(); it++)
    {
        std::string name = (*it)->get_name();
        if(name.compare(observer->get_name()) == 0)
        {
            m_observers.erase(it);
        }
    }
}

void InstanceSubject::notify_observers(std::string context)
{
    m_iterator it = m_observers.begin();
    for(;it != m_observers.end(); it++)
    {
        (*it)->update(context);
    }
}

void InstanceSubject::send_message()
{
    std::cout << "send message" << std::endl;
    notify_observers("hello world!");
}

BinaryObserver::BinaryObserver() : IObserver("binary")
{

}

BinaryObserver::~BinaryObserver()
{

}

void BinaryObserver::update(std::string context)
{
    std::cout << "binary observer" << std::endl;
    report_observer(context);
}

void BinaryObserver::report_observer(std::string report)
{
    std::cout << "binary:" << report.c_str() << std::endl;
}

std::string BinaryObserver::get_name()
{
    return m_name;
}

HexObserver::HexObserver() : IObserver("Hex")
{

}

HexObserver::~HexObserver()
{

}

void HexObserver::update(std::string context)
{
    std::cout << "Hex observer" << std::endl;
    report_observer(context);
}

std::string HexObserver::get_name()
{
    return m_name;
}

void HexObserver::report_observer(std::string report)
{
    std::cout << "Hex:" << report.c_str() << std::endl;
}