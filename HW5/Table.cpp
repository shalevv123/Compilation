#include "Table.hpp"
#include <memory>
#include <utility>
#include "hw3_output.hpp"
#include "bp.hpp"

using namespace std;

TableEntry::TableEntry(std::string name, std::string type, int offset, std::string var):
name(std::move(name)), type(std::move(type)), offset(offset), var(std::move(var))
{}

std::string TableEntry::emit_store(const std::string& base_pointer, std::vector<std::pair<int,BranchLabelIndex>>& baseList) const{
    string new_var = CodeBuffer::instance().freshVar();
    string str = new_var + " = getelementptr [@ x i32], [@ x i32]* " + base_pointer + ", i32 0, i32 " + to_string(offset); //TODO: change types
    int bp = CodeBuffer::instance().emit(str);
    baseList.emplace_back(bp, FIRST);
    baseList.emplace_back(bp, SECOND);
    if (type == "BOOL"){
        string final_var = CodeBuffer::instance().freshVar();
        str =final_var + " = zext i1 " + var + " to i32";
        CodeBuffer::instance().emit(str);
        str = "store i32 " + final_var + ", i32* " + new_var;
        CodeBuffer::instance().emit(str);
        return final_var;
    }
    str = "store i32 " + var + ", i32* " + new_var;
    CodeBuffer::instance().emit(str);
    return var;
}

std::string TableEntry::emit_load(const std::string& base_pointer, std::vector<std::pair<int,BranchLabelIndex>>& baseList) const{
    string new_var = CodeBuffer::instance().freshVar();
    string str = new_var + " = getelementptr [@ x i32], [@ x i32]* " + base_pointer + ", i32 0, i32 " + to_string(offset); //TODO: change types
    int bp = CodeBuffer::instance().emit(str);
    baseList.emplace_back(bp, FIRST);
    baseList.emplace_back(bp, SECOND);
    string final_var = CodeBuffer::instance().freshVar();
    str = final_var + " = load i32, i32* " + new_var;
    CodeBuffer::instance().emit(str);
    if (type == "BOOL"){
        string bool_var = CodeBuffer::instance().freshVar();
        str =bool_var + " = trunc i32 " + final_var + " to i1";
        CodeBuffer::instance().emit(str);
        return bool_var;
    }
    return final_var;
}


TableEntry* Table::findEntry(const std::string& name_to_find){
    for(auto& entry : table){
        if(entry.name == name_to_find)
            return &entry;
    }      
    return nullptr;
}

void Table::addEntry(std::string name, std::string type, int offset,  std::string var){
    table.emplace_back(std::move(name), std::move(type), offset, var);
}

void Table::printEntries() const{
    for(auto& entry : table){
        output::printID(entry.name, entry.offset, entry.type, entry.var);
    }
}

int Table::localVars() {
    if(table.empty())
        return 0;
    return table.back().offset + 1;
}