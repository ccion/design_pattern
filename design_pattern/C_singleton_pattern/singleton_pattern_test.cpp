#include <iostream>
#include "singleton_pattern.h"

int main(int argv,char **argc)
{
    Singleton* singleton1 = Singleton::get_instance();
    Singleton* singleton2 = Singleton::get_instance();

    if(singleton1 == singleton2){
        std::cout << "singleton1 == singleton2" << std::endl;
    }

    return 0;
}