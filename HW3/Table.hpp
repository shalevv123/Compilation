#ifndef TABLE
#define TABLE
#include <string>
#include <vector>
#include <memory>
struct TableEntry{
    std::string name;
    std::string type;
    int offset;
    TableEntry(std::string name, std::string type, int offset);

};
class Table{
public:
    TableEntry* findEntry(const std::string& name_to_find);
    void addEntry(std::string name, std::string type, int offset);
    void printEntries();
private:
    std::vector<TableEntry> table;
};



#endif //Table