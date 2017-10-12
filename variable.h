class Variable: public Operand
{
public:
    Variable(string name)
    {
        this->name = name;
    }
    double Variable::evaluate();
private:
    string name;
};