#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments(string);
//int indexof(string, char);

int main()
{
    ifstream reader("input.txt");
    
    if(!reader.is_open()) {
        cout << "Error reading file" << endl;
    }else {
        string line;
        while(getline(reader, line)) {
            cout << "reading line: " << line << endl;
            Expression* expression = NULL;
            
            int comma = (int) line.find(',');
            string exp = line.substr(0, comma);
            string assigns = line.substr(comma + 2);
            
            cout << "parsing expression: " << exp << endl;
            expression = SubExpression::parse(exp);
            int temp = 0;
            cout << "parsed: " << temp << endl;
        }
        
        reader.close();
    }
    
    
//    cout << "Please enter each character in the expresion (use , to terminate): " << endl;
//    expression = SubExpression::parse();
//    cout << "Please enter each assignments followed by a comma (use ; to terminate):";
//    parseAssignments();
//    cout << "Value = " << expression->evaluate() << endl;
    return 0;
}

void parseAssignments(string assigns)
{
    char assignop, delimiter;
    string variable;
    double value;
    do
    {
        variable = parseName(assigns);
        cin >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}

//int indexof(string exp, char c) {
//    int idx = -1;
//    
//    for(int i = 0; i < exp.size(); i++) {
//        if(exp[i] == c) {
//            idx = i;
//            break;
//        }
//    }
//    
//    return idx;
//}