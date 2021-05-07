#include "iterator_pattern.h"

int main(int argc,char **argv)
{
    Aggregate<int> *arg = new ConcreteAggregate<int>();
    arg->push_data(3);
    arg->push_data(2);
    arg->push_data(19);
    arg->push_data(200);
    Iterator<int> *it = arg->create_iterator();

    for(it->first(); !it->is_done(); it->next())
    {
        std::cout << *it->cur_item() << std::endl;
    }

    delete it;
    delete arg;


    return 0;
}