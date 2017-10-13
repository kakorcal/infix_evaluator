#include <iostream>
#include <string>
#include <stack>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "greaterThan.h"
#include "lessThan.h"
#include "equals.h"
#include "and.h"
#include "or.h"
#include "unary.h"
#include "ternary.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

Expression* SubExpression::parse(string exp)
{
    // need to branch parse into three methods
    
    Expression* left;
    Expression* right;
    Expression* cond;
    string operand1, operand2, operand3;
    char op = ' ';
    // skipping initial (
    // check if nested expression
    int idx = 1;
    
    if(exp[idx] == '(') {
        operand1 = innerExpression(&idx, exp);
    }else {
        operand1 = innerValue(&idx, exp);
    }
    
    if(exp[idx] == '+' || exp[idx] == '-' ||
       exp[idx] == '*' || exp[idx] == '/' ||
       exp[idx] == '=' || exp[idx] == '<' ||
       exp[idx] == '>' || exp[idx] == '&' ||
       exp[idx] == '|') {
        // find operand2 and op
        op = innerValue(&idx, exp);
        
        if(exp[idx] == '(') {
            operand2 = innerExpression(&idx, exp);
        }else {
            operand2 = innerValue(&idx, exp);
        }
        
    }else if(exp[idx] == ':') {
        // find operand2 and operand3
        innerValue(&idx, exp);
        
        if(exp[idx] == '(') {
            operand2 = innerExpression(&idx, exp);
        }else {
            operand2 = innerValue(&idx, exp);
        }
        
        innerValue(&idx, exp);
        
        if(exp[idx] == '(') {
            operand3 = innerExpression(&idx, exp);
        }else {
            operand3 = innerValue(&idx, exp);
        }
    }
    
    if(!operand1.empty() && operand2.empty() && operand3.empty()) {
        // unary
        left = Operand::parse(operand1);
        right = NULL;
        
        return new Unary(left, right);
        
    }else if(!operand1.empty() && !operand2.empty() && operand3.empty()) {
        // binary
        left = Operand::parse(operand1);
        right = Operand::parse(operand2);
        
        switch(op) {
            case '+':
                return new Plus(left, right);
            case '-':
                return new Minus(left, right);
            case '*':
                return new Times(left, right);
            case '/':
                return new Divide(left, right);
            case '>':
                return new GreaterThan(left, right);
            case '<':
                return new LessThan(left, right);
            case '=':
                return new Equals(left, right);
            case '&':
                return new And(left, right);
            case '|':
                return new Or(left, right);
        }
    }else {
        // ternary
        left = Operand::parse(operand1);
        right = Operand::parse(operand2);
        cond = Operand::parse(operand3);
        
        return new Ternary(cond, left, right);
    }
    
    return 0;
}

string SubExpression::innerExpression(int* idx, string exp) {
    
    if(exp[*idx] != '(') {
        return 0;
    }
    
    stack<char> parens;
    string innerExp;
    int start = *idx;
    
    for(int i = start; i < exp.length(); i++) {
        if(exp[i] == '(') {
            parens.push(exp[i]);
        }else if(exp[i] == ')') {
            parens.pop();
            
            if(parens.empty()) {
                *idx = i;
                break;
            }
        }
    }
    
    innerExp = exp.substr(start, *idx - start + 1);
    // increment to skip space
    *idx = *idx + 2;
    return innerExp;
}

char SubExpression::innerValue(int* idx, string exp) {
    string innerVal = exp.substr(*idx, 1);
    // increment to skip space
    *idx = *idx + 2;
    return innerVal[0];
}

// recursively traverses the expression and finds the value
// looks at the symbol table to determine variable values
double SubExpression::evaluate() {
    return 0;
}
