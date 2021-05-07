#include "bridge_pattern.h"

int main(int argc,char **argv)
{
    IBridge *bridge = nullptr;

    bridge = new Client(10, new Run());
    bridge->do_sport();
    delete bridge;

    bridge = new Client(8, new Swim());
    bridge->do_sport();
    delete bridge;

    bridge = new Client(2, new Fly());
    bridge->do_sport();
    delete bridge;

    return 0;
}