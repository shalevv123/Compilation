#ifndef TABLE
#define TABLE
#include <string>
#include <vector>
#include <memory>
#include "bp.hpp"
struct TableEntry{
    std::string name;
    std::string type;
    int offset;
    std::string var;
    TableEntry(std::string name, std::string type, int offset, std::string var = "");

    std::string emit_store(const std::string& base_pointer) const;
    std::string emit_load(const std::string& base_pointer) const;
};
class Table{
public:
    TableEntry* findEntry(const std::string& name_to_find);
    void addEntry(std::string name, std::string type, int offset, std::string var = "");
    void printEntries() const;
private:
    std::vector<TableEntry> table;
};



#endif //Table