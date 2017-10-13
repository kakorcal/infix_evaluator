class SubExpression: public Expression
{
public:
    SubExpression(Expression* left, Expression* right);
    double evaluate();
    static Expression* parse();
protected: 
    Expression* left;
    Expression* right;
};