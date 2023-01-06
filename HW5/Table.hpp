#ifndef TABLE
#define TABLE
#include <string>
#include <vector>
#include <memory>
struct TableEntry{
    std::string name;
    std::string type;
    int offset;
    std::string var;
    TableEntry(std::string name, std::string type, int offset, std::string var = "");

};
class Table{
public:
    TableEntry* findEntry(const std::string& name_to_find);
    void addEntry(std::string name, std::string type, int offset, std::string var = "");
    void printEntries();
private:
    std::vector<TableEntry> table;
};



#endif //Table