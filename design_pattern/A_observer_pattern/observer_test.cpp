#include "observer_pattern.h"


int main(int argc,char **argv)
{
    IObserver *binary = new BinaryObserver();
    IObserver *hex = new HexObserver();

    InstanceSubject *subject = new InstanceSubject();

    subject->add_observer(binary);

    subject->add_observer(hex);

    subject->send_message();

    delete binary;
    binary = nullptr;

    delete hex;
    hex = nullptr;

    
    return 0;
}