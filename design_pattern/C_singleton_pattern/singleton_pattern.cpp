#include "singleton_pattern.h"

Singleton* Singleton::m_instance = nullptr;

Singleton::Singleton()
{

}
Singleton::~Singleton()
{

}

Singleton::Singleton(const Singleton&)
{

}



Singleton* Singleton::get_instance()
{
    if(m_instance == nullptr){
        m_instance = new Singleton();
    }

    return m_instance;
}

