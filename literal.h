class Literal: public Operand
{
public:
    Literal(int value)
    {
        this->value = value;
    }
    double evaluate()
    {
        return value;
    }
private:
    int value;
};