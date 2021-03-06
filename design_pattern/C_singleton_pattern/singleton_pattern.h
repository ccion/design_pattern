/**********************************************************************
 * 文件名: singleton_pattern.h
 * 
 * @功能描述:单例模式涉及到一个单一的类，该类负责创建自己的对象，同时确保只有单个
    对象被创建，这个类提供了一种访问其唯一的对象的方式，可以直接访问，不需要实例化
    该类的对象
 * @意图：
    保证一个类仅有一个实例，并提供一个访问它的全局访问点
 * @主要解决：
    一个全局使用的类频繁地创建与销毁
 * @应用实例:
    1.一个班级只有一个班主任
    2.windows是多进程多线程的，在操作一个文件的时候，就不可避免地出现多个进程或
    线程同时操作一个文件的现象，所以所有文件的处理必须通过唯一的实例来进行
    3.一些设备管理器常常设计为单例模式，比如一个电脑有两台打印机，在输出的时候就要
    处理不能两台打印机打印同一个文件
 * @优点：
    1.在内存里只有一个实例，减少了内存的开销，尤其是频繁的创建和销毁实例
    2.避免对资源的多重占用(比如写文件操作)
 * @缺点：
    1.没有接口，不能继承，与单一职责原则冲突，一个类应该只关心内部逻辑，而不关心外面
    怎么样来实例化
 * 
 ********************************************************************/
#ifndef SINGLETON_PATTERN_H
#define SINGLETON_PATTERN_H

class Singleton
{
public:
    static Singleton *get_instance();

private:
    Singleton();
    ~Singleton();
    Singleton(const Singleton&);

    static Singleton *m_instance;
};

#endif