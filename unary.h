class Unary: public SubExpression
{
public:
    Unary(Expression* left, Expression* right):
        SubExpression(left, right)
    {
    }
    double evaluate()
    {
        return !(left->evaluate());
    }
};