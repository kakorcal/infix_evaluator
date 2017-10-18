class Equals: public SubExpression
{
public:
    Equals(Expression* left, Expression* right):
        SubExpression(left, right)
    {
    }
    double evaluate()
    {
        return left->evaluate() == right->evaluate();
    }
};