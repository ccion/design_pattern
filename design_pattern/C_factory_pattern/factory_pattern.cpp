#include "factory_pattern.h"


int main(int argc,char **argv)
{
    Factory *factory = new BenzFactory();
    Car *specific_car1 = factory->create_specific_car();
    specific_car1->created_car();

    factory = new BmwFactory();
    Car *specific_car2 = factory->create_specific_car();
    specific_car2->created_car();

    delete factory;
    delete specific_car1;
    delete specific_car2;

    return 0;
}