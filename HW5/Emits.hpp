#ifndef EMITS
#define EMITS

#include <string>
#include "Node.hpp"

namespace emits{
    std::string emit_var(std::string var1, std::string op = "", std::string var2 = "", bool isByte = false, bool isBool = false);
    std::string emit_num(Num* num);
    std::string emit_exp(Exp* exp1, std::string op = "", Exp* exp2 = nullptr, bool isByte = false, bool isBool = false);
    std::string emit_global_string(String* str);
    std::string emit_relop(Exp* exp1, std::string op, Exp* exp2);
}   


#endif  //EMITS