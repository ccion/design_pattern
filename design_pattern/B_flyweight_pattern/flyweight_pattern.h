/***************************************************************
 * 文件名： flyweight_pattern.h
 * 
 * @功能描述:亨元模式，主要用于减少创建对象的数量，以减少内存占用和提高性能，
    这种类型的设计模式属于结构型模式，它提供了减少对象数量从而改善应用所需的
    对象结构的方式
 * @意图：运用共享技术有效地支持大量细粒度的对象
 * @主要解决：
      在有大量对象时，有可能会造成内存溢出，我们把其中共同的部分抽象出来，如果
    有相同的业务请求，直接返回在内存中已有的对象，避免重新创建
 * @何时使用：
    1.系统中有大量对象
    2.这些对象消耗大量内存
    3.这些对象的状态大部分可以外部化
    4.这些对象可以按照内蕴状态分为很多组，当把外蕴对象中剔除出来时，每一组对象
    都可以用一个对象来代替
    5.系统不依赖这些对象身份，这些对象是不可分辨的
 * @应用实例：
    1.java中的string,如果没有则创建一个字符串保存在字符串缓存池里面
 * @优点：
    大大减少对象的创建，降低系统的内存，使效率提高
 * @缺点：
    提高了系统的复杂度，需要分离出外部状态和内部状态，而且外部状态具有固有化的
    性质，不应该随着内部状态的变化而变化，否则会造成系统的混乱
 * @使用场景:
 *  1.系统有大量相似对象
 *  2.需要缓冲池的场景
 * 
 ***************************************************************/
#ifndef FLYWEIGHT_PATTERN_H
#define FLYWEIGHT_PATTERN_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>

class NetworkDevice
{
public:
    NetworkDevice() {}
    virtual ~NetworkDevice() {}
    virtual std::string get_type() = 0;
    virtual void use() = 0;
};

/*具体亨元类switch*/
class Switch : public NetworkDevice
{
public:
    Switch(std::string type)
    {
        m_type = type;
    }

    ~Switch() {}

    std::string get_type()
    {
        return m_type;
    }

    void use()
    {
        std::cout << "Linked by switch,type is:" << m_type << std::endl;
    }
    
private:
    std::string m_type;
};

/*具体亨元类hub*/
class Hub : public NetworkDevice
{
public:
    Hub(std::string type)
    {
        m_type = type;
    }

    std::string get_type()
    {
        return m_type;
    }

    void use()
    {
        std::cout << "Linked by Hub,type is:" << m_type << std::endl;
    }

private:
    std::string m_type;
};

class DeviceFactory
{
public:
    DeviceFactory()
    {
        std::shared_ptr<NetworkDevice> nd1 = std::make_shared<Switch>("Ciso-WS-C2100-21");
        m_devices.insert(std::make_pair("cisco",nd1));
        std::shared_ptr<NetworkDevice> nd2 = std::make_shared<Hub>("TP-LINK");
        m_devices.insert(std::make_pair("tp",nd2));
    }
    ~DeviceFactory() {}

    std::shared_ptr<NetworkDevice> get_networkdevice(std::string type)
    {
        if(m_devices.count(type)){
            m_totalterminal++;
            return m_devices.find(type)->second;
        }else{
            return nullptr;
        }
    }

    int get_totaldevice()
    {
        return m_devices.size();
    }

    int get_totalterminal()
    {
        return m_totalterminal;
    }

private:
    std::map<std::string ,std::shared_ptr<NetworkDevice>> m_devices;
    int  m_totalterminal = 0;
};

#endif