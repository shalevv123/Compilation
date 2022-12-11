#ifndef NODE
#define NODE
#include <string>
#include <vector>
struct Node{};

struct Type : public Node {
    std::string type;

    Type(std::string type):
    type(type){};
};

struct String : public Node {
    std::string value;
    
    String(std::string value):
    value(value){};
};

struct Num : public Node {
    int value;

    Num(std::string value):
    value(stoi(value)){};
};

struct Id : public Node {
    std::string name;

    Id(std::string name):
    name(name){};
};

struct Exp : public Node {
    std::string type;
    Exp(std::string type):
    type(type){};
};

struct ExpList : public Node {
    std::vector<Exp> expressions;

    ExpList(std::vector<Exp> expressions):
    expressions(expressions){};
};

struct Call : public Node {
    std::string type;
    
    Call(std::string type):
    type(type){};
};

struct RetType : public Node {
    std::string name;

    RetType(std::string name):
    name(name){};
};

struct Relop : public Node {
    std::string op;

    Relop(std::string op):
    op(op){};
};

struct Equal : public Node {
    std::string op;

    Equal(std::string op):
    op(op){};
};

struct MulDiv : public Node {
    std::string op;

    MulDiv(std::string op):
    op(op){};
};

struct PlusMinus : public Node {
    std::string op;

    PlusMinus(std::string op):
    op(op){};
};

#endif //Node