#include "Table.hpp"
#include <memory>
#include <utility>
#include "hw3_output.hpp"
using namespace std;

TableEntry::TableEntry(std::string name, std::string type, int offset):
name(std::move(name)), type(std::move(type)), offset(offset)
{}


TableEntry* Table::findEntry(const std::string& name_to_find){
    for(auto& entry : table){
        if(entry.name == name_to_find)
            return &entry;
    }      
    return nullptr;
}

void Table::addEntry(std::string name, std::string type, int offset){
    table.emplace_back(std::move(name), std::move(type), offset);
}

void Table::printEntries(){
    for(auto& entry : table){
        output::printID(entry.name, entry.offset, entry.type);
    }
}