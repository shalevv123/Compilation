#ifndef NODE
#define NODE
#include <string>
#include <vector>
struct Node{};


struct Type : public Node {
    std::string type;

    explicit Type(const std::string& type);
};

struct String : public Node {
    std::string value;
    
    explicit String(const std::string& value);
};

struct Num : public Node {
    int value;

    explicit Num(const std::string& value);
};

struct Id : public Node {
    std::string name;

    explicit Id(const std::string& name);
};

struct Exp : public Node {
    std::string type;
    std::string var;
    Exp(const std::string& type, const std::string& var = "");
    std::string emitOp(const Exp* exp1, const std::string& op,const Exp* exp2);
};

struct BoolExp: public Exp{

};

struct StringExp: public Exp{
    std::string value;

    explicit StringExp(const std::string& value, std::string var);
    std::string emitGlobalString() const;
};

struct ExpList : public Node {
    std::vector<Exp> expressions;

    explicit ExpList(const std::vector<Exp>& expressions);
};

struct Call : public Node {
    std::string type;
    
    explicit Call(const std::string& type);
};

struct RetType : public Node {
    std::string name;

    explicit RetType(const std::string& name);
};

struct Relop : public Node {
    std::string op;

    explicit Relop(const std::string& op);
};

struct Equal : public Node {
    std::string op;

    explicit Equal(const std::string& op);
};

struct MulDiv : public Node {
    std::string op;

    explicit MulDiv(const std::string& op);
};

struct PlusMinus : public Node {
    std::string op;

    explicit PlusMinus(const std::string& op);
};

#define YYSTYPE Node*

#endif //Node