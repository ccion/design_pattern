#include "state_pattern.h"


void go_run()
{
    CContext context;
    CCloseingState  closeingstate;
    context.set_liftstate(&closeingstate);
    context.close();
    context.open();
    context.run();
    context.stop();

}



int main(int argc,char **argv)
{
    go_run();
    std::cout << "------End--------" << std::endl;
    return 0;
}