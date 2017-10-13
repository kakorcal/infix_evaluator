class SubExpression: public Expression
{
public:
    SubExpression(Expression* left, Expression* right);
    double evaluate();
    static string innerExpression(int* idx, string exp);
    static char innerValue(int* idx, string exp);
    static Expression* parse(string exp);
protected: 
    Expression* left;
    Expression* right;
};