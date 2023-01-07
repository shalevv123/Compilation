//
// Created by User1 on 1/7/2023.
//

#include "Node.hpp"
#include "bp.hpp"
#include <string>
#include <vector>
#include <utility>

using namespace std;

//Type
Type::Type(const std::string &type):
        type(type){};

//String
String::String(const std::string& value):
        value(value){};



//Num
Num::Num(const std::string &value):
        value(stoi(value)){};

//Id
Id::Id(const std::string &name):
        name(name){};

//Exp
Exp::Exp(const std::string &type, const std::string& var):
        type(type), var(var){};

std::string Exp::emitOp(const Exp *exp1, const std::string &op, const Exp *exp2){
    string str;
    if (op == "+"){
        str = var + " = add i32 " + exp1->var + ", " + exp2->var;
    }
    else if (op == "-"){
        str = var + " = sub i32 " + exp1->var + ", " + exp2->var;
    }
    else if (op == "*"){
        str = var + " = mul i32 " + exp1->var + ", " + exp2->var;
    }
    else if (op == "/"){
        string flag_var = CodeBuffer::instance().freshVar();
        str = flag_var + " = icmp eq i32 " + exp2->var + ", 0";
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

        if (type == "BYTE")
            str = var + " = udiv i32 " + exp1->var + ", " + exp2->var;
        else
            str = var + " = sdiv i32 " + exp1->var + ", " + exp2->var;


    }
    else if (op == "=="){
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
    if(type == "BYTE"){
        string mid_var = var;
        var = CodeBuffer::instance().freshVar();
        str = var +" = and i32 " + mid_var + ", 255";
        CodeBuffer::instance().emit(str);
    }
    return var;
}

//BoolExp


//StringExp
StringExp::StringExp(const std::string& value, std::string var):
        Exp("STRING", "@." + var.substr(1)), value(value){};

std::string StringExp::emitGlobalString() const
{
    string val = value.substr(1); //value = i am a string"
    val.pop_back(); //value = i am a string
    string global_str = var + " = internal constant [" + to_string(val.size()+1) +
                        + " x i8] c\"" + val + "\\00\"";
    CodeBuffer::instance().emitGlobal(global_str);
    return var;
};
//ExpList
ExpList::ExpList(const std::vector<Exp> &expressions):
        expressions(expressions){};

//Call
Call::Call(const std::string &type):
        type(type){};

//RetType
RetType::RetType(const std::string &name):
        name(name){};

//Relop
Relop::Relop(const std::string &op):
        op(op){};

//Equal
Equal::Equal(const std::string &op):
        op(op){};

//MulDiv
MulDiv::MulDiv(const std::string &op):
        op(op){};

//PlusMinus
PlusMinus::PlusMinus(const std::string &op):
        op(op){};
