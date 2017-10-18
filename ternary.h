class Ternary: public SubExpression
{
public:
    
    Ternary(Expression* cond, Expression* left, Expression* right) :
    SubExpression(left, right) {
        this -> cond = cond;
    };

    double evaluate()
    {
        return cond->evaluate() ? left->evaluate() : right->evaluate();
    };
private:
    Expression* cond;
};