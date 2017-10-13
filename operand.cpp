#include <cctype>
#include <iostream>
#include <list>
#include <string>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

Expression* Operand::parse(string exp)
{
    
    if (isdigit(exp[0]))
    {
        int digit = exp[0] - '0';
        Expression* literal = new Literal(digit);
        return literal;
    }
    if (exp[0] == '(')
    {
        return SubExpression::parse(exp);
    }
    else
        return new Variable(parseName(exp));
    return 0;
}