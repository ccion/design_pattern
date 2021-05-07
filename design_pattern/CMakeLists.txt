cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(design_pattern LANGUAGES CXX)
include(../build/BuildDefaults.cmake)

#11ways 行为型模式
add_subdirectory("A_strategy_pattern") #策略模式
add_subdirectory("A_template_pattern") #模板模式
add_subdirectory("A_observer_pattern") #观察者模式
add_subdirectory("A_iterator_pattern") #迭代器模式
add_subdirectory("A_chain_responsibility_pattern") #责任链模式
add_subdirectory("A_command_pattern") #命令模式
add_subdirectory("A_memento_pattern") #备忘录模式
add_subdirectory("A_state_pattern")   #状态模式
add_subdirectory("A_visitor_pattern") #访问者模式
add_subdirectory("A_mediator_pattern") #中介者模式
add_subdirectory("A_interpreter_pattern") #解释器模式

#7ways 结构型模式
add_subdirectory("B_adapter_pattern") #适配器模式
add_subdirectory("B_decorator_pattern") #装饰器模式
add_subdirectory("B_proxy_pattern") #代理模式
add_subdirectory("B_facade_pattern") #外观模式
add_subdirectory("B_bridge_pattern") #桥接模式
add_subdirectory("B_composite_pattern") #组合模式
add_subdirectory("B_flyweight_pattern") #亨元模式

#6ways 创建型模式
add_subdirectory("C_simple_factory_pattern") #简单工厂模式
add_subdirectory("C_factory_pattern") #工厂模式
add_subdirectory("C_abstract_factory_pattern") #抽象工厂模式
add_subdirectory("C_singleton_pattern") #单例模式
add_subdirectory("C_builder_pattern") #构建者模式
add_subdirectory("C_prototype_pattern") #原型模式
