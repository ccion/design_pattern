#include "template_pattern.h"

int main(int argc,char **argv)
{
    Game *game;
    game = new Cricket();
    game->play();

    game = new Football();
    game->play();

    game = new BascketBall();
    game->play();
    
    return 0;
}