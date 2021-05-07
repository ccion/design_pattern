#include "proxy_pattern.h"

int main(int argv,char **argc)
{
    Image *image = new BigImageProxy("Image.txt");
    image->show();

    delete image;

    return 0;
}
