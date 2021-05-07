#include "flyweight_pattern.h"


int main(int argv,char **argc)
{
    std::shared_ptr<NetworkDevice> nd1,nd2,nd3,nd4,nd5;
    std::shared_ptr<DeviceFactory> df = std::make_shared<DeviceFactory>();

    nd1 = df->get_networkdevice("cisco");
    nd1->use();

    nd2 = df->get_networkdevice("cisco");
    nd2->use();

    nd3 = df->get_networkdevice("cisco");
    nd3->use();

    nd4 = df->get_networkdevice("tp");
    nd4->use();

    nd5 = df->get_networkdevice("tp");
    nd5->use();

    std::cout << "total device:" << df->get_totaldevice() << std::endl;
    std::cout << "total terminal:" << df->get_totalterminal() <<std:: endl;

    return 0;
}