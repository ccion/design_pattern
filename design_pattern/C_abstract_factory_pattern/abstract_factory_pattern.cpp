#include "abstract_factory_pattern.h"

int main(int argv,char **argc)
{
    FactoryA  factory1;
    FactoryB  factory2;
    SoapBase *psoap1 = nullptr;
    ToothBase *ptoothpaste1 = nullptr;
    psoap1 = factory1.create_soap();
    ptoothpaste1 = factory1.create_toothpaste();

    psoap1->show();
    ptoothpaste1->show();

    SoapBase *psoap2 = nullptr;
    ToothBase *ptoothpaste2 = nullptr;

    psoap2 = factory2.create_soap();
    ptoothpaste2 = factory2.create_toothpaste();

    psoap2->show();
    ptoothpaste2->show();

    delete psoap1;
    delete psoap2;
    delete ptoothpaste1;
    delete ptoothpaste2;

    return 0;
}