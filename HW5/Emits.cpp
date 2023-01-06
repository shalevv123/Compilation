
#include "Emits.hpp"
#include "bp.hpp"
#include <string>

using namespace std;

std::string emits::emit_var(std::string var1, std::string op, std::string var2, bool isByte){
    string var = CodeBuffer::instance().freshVar();
    string str = "";
    if (op == "+"){
        str = var + "= add i32 " + var1 + ", " + var2;
    }
    else if (op == "-"){
        str = var + "= sub i32 " + var1 + ", " + var2;
    }
    else if (op == "*"){
        str = var + "= mul i32 " + var1 + ", " + var2;  
    }
    else if (op == "/"){
        string flag_var = CodeBuffer::instance().freshVar();
        str = flag_var + "= icmp eq i32 " + var2 + ", 0";
        CodeBuffer::instance().emit(str); 

        str = "br i1 " + flag_var + ", label @, label @";
        int fill = CodeBuffer::instance().emit(str);
        
        string trueLabel = CodeBuffer::instance().genLabel();
        string err_var = CodeBuffer::instance().freshVar();
        str = err_var + " = getelementptr [23 x i8], [23 x i8]* @.div_error, i32 0, i32 0";
        CodeBuffer::instance().emit(str);

        str = "call void @print(i8* " + err_var + ")";
        CodeBuffer::instance().emit(str);
        str = "call void @exit(i32 0)";
        CodeBuffer::instance().emit(str);

        string false_label = CodeBuffer::instance().genLabel();
        CodeBuffer::instance().bpatch(CodeBuffer::makelist({fill,FIRST}), trueLabel);
        CodeBuffer::instance().bpatch(CodeBuffer::makelist({fill,SECOND}), falseLabel);

        if (isByte)
            str = var + " udiv i32 " + var1 + ", " + var2;
        else
            str = var + " sdiv i32 " + var1 + ", " + var2;
        

    }
    else if (op == ""){
        str = var + "= add i32 0, " + var1; 
    }

    CodeBuffer::instance().emit(str); 
    if(isByte){
        string mid_var = var;
        var = CodeBuffer::instance().freshVar();
        str = var +" = and i32 " + mid_var + ", 255";
        CodeBuffer::instance().emit(str);
    }
    return var;
}

std::string emits::emit_num(Num* num){
    string var = CodeBuffer::instance().freshVar();
    string str = var + "add i32 0, " + num->value;
    return var;
}

std::string emits::emit_exp(Exp* exp1, std::string op, Exp* exp2, bool isByte){
    return emit_vars(exp1->var, op, exp2->var, isByte)
}
