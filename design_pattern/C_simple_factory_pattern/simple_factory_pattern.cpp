#include "simple_factory_pattern.h"

int main(int argv,char **argc)
{
    Factory factory;
    SoapBase *psoap1 = factory.create_soap(SFJ);
    psoap1->show();

    SoapBase *psoap2 = factory.create_soap(XSL);
    psoap2->show();

    SoapBase *psoap3 = factory.create_soap(NAS);
    psoap3->show();

    delete psoap1;
    delete psoap2;
    delete psoap3;

    return 0;
}