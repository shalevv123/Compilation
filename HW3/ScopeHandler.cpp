#include "ScopeHandler.hpp"
#include <memory>
#include "hw3_output.hpp"
#include <string>
#include <utility>
#include <iostream>
using namespace std;
ScopeHandler::ScopeHandler():
        offsetStack(vector<int>()), tableStack(vector<Table>())
{
    offsetStack.push_back(0);
    tableStack.emplace_back();
    addFunction("print","VOID", vector<string>{""},  vector<string>{"STRING"});
    offsetStack.pop_back();
    tableStack.pop_back();
    addFunction("printi", "VOID", vector<string>{""}, vector<string>{"INT"});
    offsetStack.pop_back();
    tableStack.pop_back();
}

void ScopeHandler::newScope()
{
    offsetStack.push_back(offsetStack.back());
    tableStack.emplace_back();
}

void ScopeHandler::endScope()
{
    output::endScope();
    tableStack.back().printEntries();
    offsetStack.pop_back();
    tableStack.pop_back();
}

TableEntry* ScopeHandler::findSymbol(const std::string& name)
{
    TableEntry* entry;
    for(auto table = tableStack.rbegin(); table != tableStack.rend() ; table++){
        entry = (*table).findEntry(name);
        if (entry)
            return entry;
    }
    return nullptr;
}

bool ScopeHandler::addSymbol(const std::string& name, std::string type)
{
    if (findSymbol(name))
        return false;

    tableStack.back().addEntry(name, std::move(type), offsetStack.back());
    offsetStack.back() += 1;
    return true;
}

bool ScopeHandler::addFunction(const std::string& name, const std::string& returnType, const std::vector<std::string>& argnames, const std::vector<std::string>& argtypes)
{
    if (findSymbol(name))
        return false;
    for (const string& argname : argnames)
    {
        if(findSymbol(argname))
            return false;
    }
    tableStack.back().addEntry(name, output::makeFunctionType(returnType, argtypes), 0);
    newScope();
    int negCounter= -1;
    for (int it = 0; it<argnames.size(); it++)
    {
        tableStack.back().addEntry(argnames[it], argtypes[it], negCounter);
        negCounter--;
    }
    return true;
}