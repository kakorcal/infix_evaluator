class Or: public SubExpression
{
public:
    Or(Expression* left, Expression* right):
        SubExpression(left, right)
    {
    }
    double evaluate()
    {
        return left->evaluate() || right->evaluate();
    }
};