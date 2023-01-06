#ifndef EMITS
#define EMITS

#include <string>
#include "Node.hpp"

namespace emits{
    std::string emit_var(Exp* exp1, std::string op = "", Exp* exp2 = nullptr, bool isByte = false);
    std::string emit_num(Num* num, isByte = false);
    std::string emit_exp(Exp* exp1, std::string op = "", Exp* exp2 = nullptr, bool isByte = false);
}   


#endif  //EMITS