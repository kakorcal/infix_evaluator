#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

/*
 File: module3.cpp
 Author: Kenneth Korcal
 Date: Oct 13, 2017
 Purpose: read input file, parses line of input into binary tree
          , and recursively evaluates the tree
 */

SymbolTable symbolTable;

void parseAssignments(string);

int main()
{
    ifstream reader("input.txt");
    
    if(!reader.is_open()) {
        cout << "Error reading file" << endl;
    }else {
        string line;
        int testIdx = 1;
        while(getline(reader, line)) {
            cout << "test " << testIdx << ": " << line << endl;
            Expression* expression = NULL;
            
            int comma = (int) line.find(',');
            string exp = line.substr(0, comma);
            string assigns = line.substr(comma + 2);
            
            // cout << "parsing expression: " << exp << endl;
            expression = SubExpression::parse(exp);
            // cout << "assigning variables: " << assigns << endl;
            parseAssignments(assigns);
            
            // int result = expression->evaluate();
            double result = expression->evaluate();
            cout << "result: " << round(result) << "\n\n";
            
            symbolTable.resetElements();
            testIdx++;
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
            value += acc.substr(4);
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