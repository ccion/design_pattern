/*****************************************************************************
 * 文件名: adapter_pattern.h
 * 
 * @功能描述:适配器模式是作为两个不兼容的接口之间的桥梁，它结合了两个独立接口的功能，
 * 这种模式涉及到一个单一的类，该类负责加入独立的或不兼容的接口功能
 * @意图
    将一个类的接口转换成客户希望的另一个接口，适配器模式使得原本由于接口不兼容而不能一起工作
    的那些类可以一起工作
 * @主要解决:
    主要解决在软件系统中，常常要将一些"现存的对象”放到新的环境中，而新环境要求的接口是现对象
    不能满足的
 * @何时使用:
    1.系统需要使用现有的类，而此类的接口不符合系统的需要
    2.想要建立一个可以重复使用的类，用于与一些彼此之间没有太大关联的一些类，包括一些可能在将
      引进的类一起工作，这些源类不一定有一致的接口
    3.通过接口转换，将一个类插入另一个系中
 * @应用实例
    1.美国电器110v,中国220v,就要有一个适配器将110v转换为220v
 * @优点:
    1.可以让任何两个没有关联的类一起运行
    2.提高了类的复用
    3.增加了类的透明度
    4.灵活性好
 *@缺点:
    1.过多地使用适配器，会让系统非常凌乱，不易整体进行把握
 *
 * 
 * *************************************************************************/
#ifndef ADAPTER_PATTERN_H
#define ADAPTER_PATTERN_H
#include <iostream>
#include <string>


/*套接字包(可以被复用)*/
class SocketPackage
{
public:
   SocketPackage() {}
   ~SocketPackage() {}

   void create_specific_socket()
   {
      std::cout << "创建套接字...!!!" << std::endl;
   }

   void bind_specific_socket()
   {
      std::cout << "绑定套接字...!!!" << std::endl;
   }

   void listen_specific_socket()
   {
      std::cout << "监听套接字...!!!" << std::endl;
   }

   void connect_specific_socket()
   {
      std::cout << "链接套接字...!!!" << std::endl;
   }
};

/*抽象套接字类*/
class Socket
{
public:
   Socket() {}
   virtual ~Socket() {}

   /*创建套接字*/
   virtual void create_socket() = 0;

   /*绑定套接字*/
   virtual void bind_socket() = 0;

   /*监听套接字*/
   virtual void listen_socket() = 0;

   /*链接套接字*/
   virtual void connect_socket() = 0;
};

/*套接字适配器*/
class SocketAdapter : public Socket
{
public:
   /*构造函数，创建一个需要复用的套接字包对象*/
   SocketAdapter()
   {
      m_socketpackage = new SocketPackage();
   }

   /*销毁需要复用的套接字包对象*/
   ~SocketAdapter()
   {
      if(nullptr != m_socketpackage)
      {
         delete m_socketpackage;
         m_socketpackage = nullptr;
      }
   }

   /*创建套接字*/
   void create_socket()
   {
      m_socketpackage->create_specific_socket();
   }

   /*绑定套接字*/
   void bind_socket()
   {
      m_socketpackage->bind_specific_socket();
   }

   /*监听套接字*/
   void listen_socket()
   {
      m_socketpackage->listen_specific_socket();
   }

   /*链接套接字*/
   void connect_socket()
   {
      m_socketpackage->connect_specific_socket();
   }

private:
   SocketPackage*   m_socketpackage;

};






#endif