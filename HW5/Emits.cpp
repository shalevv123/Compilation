
#include "Emits.hpp"
#include "bp.hpp"
#include <string>
#include <utility>
#include "assert.h"
using namespace std;

std::string emits::emit_var(std::string var1, std::string op, std::string var2, bool isByte, bool isBool){
    string var = CodeBuffer::instance().freshVar();
    string str;
    if (!isBool){
    if (op == "+"){
        str = var + " = add i32 " + var1 + ", " + var2;
    }
    else if (op == "-"){
        str = var + " = sub i32 " + var1 + ", " + var2;
    }
    else if (op == "*"){
        str = var + " = mul i32 " + var1 + ", " + var2;  
    }
    else if (op == "/"){
        string flag_var = CodeBuffer::instance().freshVar();
        str = flag_var + " = icmp eq i32 " + var2 + ", 0";
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

        string falseLabel = CodeBuffer::instance().genLabel();
        CodeBuffer::instance().bpatch(CodeBuffer::makelist({fill,FIRST}), trueLabel);
        CodeBuffer::instance().bpatch(CodeBuffer::makelist({fill,SECOND}), falseLabel);

        if (isByte)
            str = var + " = udiv i32 " + var1 + ", " + var2;
        else
            str = var + " = sdiv i32 " + var1 + ", " + var2;
        

    }
    else if (op == ""){
        str = var + " = add i32 0, " + var1; 
    }

    CodeBuffer::instance().emit(str); 
    if(isByte){
        string mid_var = var;
        var = CodeBuffer::instance().freshVar();
        str = var +" = and i32 " + mid_var + ", 255";
        CodeBuffer::instance().emit(str);
    }
    }
    else{
        assert(op == ""); //TODO: remove this
        str = var +" = add i1 0, " + var1;
        CodeBuffer::instance().emit(str);
    }
    return var;
}

std::string emits::emit_num(Num* num){
    string var = CodeBuffer::instance().freshVar();
    string str = var + " = add i32 0, " + std::to_string(num->value);
    CodeBuffer::instance().emit(str);
    return var;
}

std::string emits::emit_exp(Exp* exp1, std::string op, Exp* exp2, bool isByte, bool isBool){
    if (exp2)
        return emit_var(exp1->var, std::move(op), exp2->var, isByte, isBool);
        
    return emit_var(exp1->var, "", "", isByte, isBool);
}

std::string emits::emit_global_string(String* str){
    string var = CodeBuffer::instance().freshVar();
    string value = str->value.substr(1);
    value.pop_back();
    string global_str = var + " = internal constant [" + to_string(value.size()+1) +
                 + " x i8] c\"" + value + "\\00\"";
    CodeBuffer::instance().emitGlobal(global_str);
    return var;
}

std::string emits::emit_relop(Exp* exp1, std::string op, Exp* exp2){
    string var = CodeBuffer::instance().freshVar();
    string str;
    if (op == "=="){
        str = var + " = icmp eq i32 " + exp1->var + ", " + exp2->var;
    }
    else if(op == "!="){
        str = var + " = icmp ne i32 " + exp1->var + ", " + exp2->var;
    }
    else if(op == "<"){
        str = var + " = icmp slt i32 " + exp1->var + ", " + exp2->var;
    }
    else if(op == "<="){
        str = var + " = icmp sle i32 " + exp1->var + ", " + exp2->var;
    }
    else if(op == ">"){
        str = var + " = icmp sgt i32 " + exp1->var + ", " + exp2->var;
    }
    else if(op == ">="){
        str = var + " = icmp sge i32 " + exp1->var + ", " + exp2->var;
    }
    CodeBuffer::instance().emit(str);
    return var;
}