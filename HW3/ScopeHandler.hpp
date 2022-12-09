#ifndef SCOPEHANDLER
#define SCOPEHANDLER

#include <vector>
#include <string>
#include "Table.hpp"
#include <memory>
#include <initializer_list>
class ScopeHandler{
public:
    ScopeHandler();
    ~ScopeHandler();
    void newScope();
    void endScope();
    TableEntry* findSymbol(const std::string& name);
    // TODO: add function support
    bool addSymbol(const std::string& name, std::string type);
    bool addFunction(const std::string& name , const std::string& type,const std::vector<std::string>& argnames,const std::vector<std::string>& argtypes);

private:
std::vector<int> offsetStack;
std::vector<Table> tableStack;
};


#endif //ScopeHandler