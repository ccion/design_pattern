#include "prototype_pattern.h"

int main(int argc,char **argv)
{
    CPrototype* conproa = new CConcretePrototype();

    CPrototype* conprob = conproa->clone();
    delete conproa;
    conproa = nullptr;
    delete conprob;
    conprob = nullptr;
    return 0;
}