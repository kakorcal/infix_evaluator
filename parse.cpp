#include <cctype> 
#include <iostream> 
#include <string> 
using namespace std;

#include "parse.h"

string parseName(string var)
{
    string name = "";
    int idx = 0;
    while (isalnum(var[idx]) || var.size() > idx)
    {
        name += var[idx];
        idx++;
    }
    return name;
}