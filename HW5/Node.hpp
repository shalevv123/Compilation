#ifndef NODE
#define NODE
#include <string>
#include <vector>
#include "bp.hpp"
#include <memory>
struct Node{
    virtual ~Node() = default;
};


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
    std::vector<std::pair<int,BranchLabelIndex>> bp;
    std::string label;
    Exp(const std::string& type, const std::string& var = "");
    virtual std::string emitOp(const Exp* exp1, const std::string& op,const Exp* exp2);
    void selfBPatch() const;
    virtual ~Exp() = default;
};

struct BoolExp: public Exp{
    std::vector<std::pair<int,BranchLabelIndex>> trueList = std::vector<std::pair<int,BranchLabelIndex>>();
    std::vector<std::pair<int,BranchLabelIndex>> falseList = std::vector<std::pair<int,BranchLabelIndex>>();

    std::string midLabel;
    bool fresh;
    explicit BoolExp(const std::string& var = "", bool fresh = true);

    std::string emit();
    std::string emitOp(const Exp* exp1, const std::string& op,const Exp* exp2) override ;
    std::string notOp(const Exp* exp);
    std::string evaluate() const;

};

struct StringExp: public Exp{
    std::string value;

    explicit StringExp(const std::string& value = "", std::string var = "");
    std::string emitGlobalString() const;
};

struct ExpList : public Node {
    std::vector<std::shared_ptr<Exp>> expressions;

    explicit ExpList(const std::vector<std::shared_ptr<Exp>>& expressions);
};

struct Call : public Node {
    std::string type;
    std::string var;
    std::vector<std::pair<int,BranchLabelIndex>> bp;
    std::string label;

    explicit Call(const std::string& type, const std::string& var = "");
    void selfBPatch() const;
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

struct Statement: public Node{
    std::vector<std::pair<int,BranchLabelIndex>> nextList = std::vector<std::pair<int,BranchLabelIndex>>();
    bool isRet = false;
    bool isControl = false;

};
#define YYSTYPE Node*

#endif //Node