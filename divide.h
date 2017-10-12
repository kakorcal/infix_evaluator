class Divide: public SubExpression
{
public:
    Divide(Expression* left, Expression* right):
        SubExpression(left, right)
    {
    }
    double evaluate()
    {
       return left->evaluate() / right->evaluate();
    }
};