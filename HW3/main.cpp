#include "Table.hpp"
#include "ScopeHandler.hpp"
#include <string>
using namespace std;

int main(){
    ScopeHandler scopeHandler;
    scopeHandler.addSymbol("main", "VOID");
    scopeHandler.newScope();
    scopeHandler.addSymbol("x", "INT");
    scopeHandler.addSymbol("y", "BOOL");
    scopeHandler.newScope();
    scopeHandler.addSymbol("z", "STRING");
    scopeHandler.endScope();
    scopeHandler.endScope();

    return 0;
}