#include "memento_pattern.h"


int main(int argc,char **argv)
{
    Originator  *originator = new Originator();
    CareTaker   *care_taker = new CareTaker();

    originator->set_state("State #1");
    originator->set_state("State #2");
    care_taker->add(originator->save_state_memento());
    originator->set_state("State #3");
    care_taker->add(originator->save_state_memento());
    originator->set_state("State #4");
    std::cout << "Current state:" << originator->get_state() << std::endl;


    originator->get_state_from_memento(care_taker->get(0));
    std::cout << "First saved  state:" << originator->get_state() << std::endl;


    originator->get_state_from_memento(care_taker->get(1));
    std::cout << "Second saved  state:" << originator->get_state() << std::endl;

    if(originator != nullptr){
        delete originator;
    }
    if(care_taker != nullptr){
        delete care_taker;
    }
}