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
            cout << "assigning variables: " << assigns << endl;
            parseAssignments(assigns);
            
//            cout << "x = " << symbolTable.lookUp("x") << endl;
//            cout << "y = " << symbolTable.lookUp("y") << endl;
//            cout << "z = " << symbolTable.lookUp("z") << endl;
            
            
//            cout << "evaluation result: " << expression->evaluate() << "\n\n";
        }
        
        reader.close();
    }
    
    return 0;
}

void parseAssignments(string assigns)
{
    string acc = "";
    string variable = "";
    string value = "";
    
    for(int i = 0; i < assigns.size(); i++) {
        if(assigns[i] == ',' || assigns[i] == ';') {
            variable += acc[0];
            value += acc[acc.length() - 1];
            symbolTable.insert(variable, stod(value));
            acc = "";
            variable = "";
            value = "";
            i++;
        }else {
            acc += assigns[i];
        }
    }
}