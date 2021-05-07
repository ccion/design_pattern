#include "interpreter_pattern.h"





Expression* get_maleexpression()
{
    Expression *robert = new TerminalExpression("Robert");
    Expression *john = new TerminalExpression("John");
    return  new OrExpression(robert, john);
}

Expression* get_womenexpression()
{
    Expression *julie = new TerminalExpression("Julie");
    Expression *married = new TerminalExpression("Married");
    return new AndExpression(julie,married);
}

int main(int argv,char **argc)
{
    Expression *is_male = get_maleexpression();
    Expression *is_woman = get_womenexpression();

    std::cout << "Jonh is male? " << is_male->interpret("John") << std::endl;
    std::cout << "Julie is a married women?" << is_woman->interpret("Julie Married") << std::endl;

    return 0;
}
