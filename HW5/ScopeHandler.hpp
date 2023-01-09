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
    void newScope();
    void endScope();
    TableEntry* findSymbol(const std::string& name);
    // TODO: add function support
    bool addSymbol(const std::string& name, std::string type, const std::string var="");
    std::shared_ptr<std::string> addFunction(const std::string& name , const std::string& type,const std::vector<std::string>& argnames,const std::vector<std::string>& argtypes);
    int localVars();
private:
std::vector<int> offsetStack = std::vector<int>();
std::vector<Table> tableStack = std::vector<Table>();
};


#endif //ScopeHandler