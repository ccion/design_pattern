#include "builder_pattern.h"

int main(int argv,char **argc)
{
    Builder *builder = new ConcreteBuilder0();
    Director *director = new Director();
    director->build(builder);
    builder->get_result().show();

    builder = new ConcreteBuilder1();
    director->build(builder);
    builder->get_result().show();


    return 0;
}