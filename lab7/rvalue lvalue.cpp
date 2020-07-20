#include <iostream>
using namespace std;
class Goles
{
public:
    Goles()
    {    }
    Goles(int x) : mX{x}
    {    }
    int mX = 0;
};

void printGoles(const Goles goles)
{
    std::cout << goles.mX << std::endl;
}

int main()
{
    int x = 1; // x es un lvalue, 1 es un rvalue 
    Goles goles1{10}; // es su conjunto es una expresion de rvalue 
    Goles goles2{230}; //  goles2 es un lvalue 
    goles1 = Goles(); //  goles1 es un lvalue , Goles() es un rvalue ya que toma temporalmente la memoria
    goles1 = goles2; // 
    printGoles(goles1); // 
    printGoles(goles2); // printGoles2 es un lvalue 
}
