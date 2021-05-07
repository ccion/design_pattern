#include "adapter_pattern.h"

int main(int argv, char **argc)
{
    /*创建套接字适配器对象*/
    Socket *socket_adapter = new SocketAdapter();

    /*使用适配器进行套接字操作*/
    socket_adapter->create_socket();
    socket_adapter->bind_socket();
    socket_adapter->listen_socket();
    socket_adapter->connect_socket();

    /*销毁操作*/
    delete socket_adapter;
    socket_adapter = nullptr;
    return 0;
}