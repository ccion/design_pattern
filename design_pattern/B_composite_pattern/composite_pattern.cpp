#include "composite_pattern.h"


int main(int argv,char **argc)
{
    /*组合模式*/
    Composite *param = new Composite("总部");

    param->add(new Leaf("总部财务部门"));
    param->add(new Leaf("总部人力资源部门"));

    Composite *param2 = new Composite("上海分部");
    param2->add(new Leaf("上海分部财务部门"));
    param2->add(new Leaf("上海分部人力资源部门"));

    param->add(param2);
    param->display();



    return 0;
}