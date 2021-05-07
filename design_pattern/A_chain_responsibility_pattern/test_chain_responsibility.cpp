#include <iostream>
#include "chain_responsibility_pattern.h"




void new_way()
{
    std::cout << "----使用模式后的处理方式-----" << std::endl;
    IWomen *pwomen1 = new CWomen(1, "我要出去逛街");
    IWomen *pwomen2 = new CWomen(2, "我要出去吃饭");
    IWomen *pwomen3 = new CWomen(3, "我也要出去吃饭");
    IWomen *pwomen4 = new CWomen(4, "我也要出去逛街");

    CHandler *pfather = new CFather();
    CHandler *phushband = new CHusband();
    CHandler *pson = new CSon();

    pfather->set_next(phushband);
    phushband->set_next(pson);

    pfather->handle_message(pwomen1);
    pfather->handle_message(pwomen2);
    pfather->handle_message(pwomen3);
    pfather->handle_message(pwomen4);

    delete pfather;
    delete phushband;
    delete pson;
    delete pwomen1;
    delete pwomen2;
    delete pwomen3;
    delete pwomen4;
}


int main(int argc,char **argv)
{
    //要实现逻辑判断，即女性的请求先发送到父亲类，父亲类一看是自己要处理的，就回应
    //进行处理，如果女儿已经出嫁了，那就把这个请求转发到女婿类来处理，依次类推，形
    //成了一个责任链
    new_way();

    return 0;
}