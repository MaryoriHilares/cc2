#include <string>
#include <iostream>
using namespace std;

void doblar(int& x) { cout<< x*2<<endl;  }
void doblar2(const int& x) { cout<< x*2<<endl;  }

void doblarRV(int && x) { cout<< x*2<<endl;  }
int main()
{
  int i=7;
  int &r= i; //correcta referencia a un lvalue
  //int &r; = 7; // error: &r refiere a un lvalue, sin embargo, 7 es un rvalue
  const int& s =7; //al poner const se cinvierte el 7 en un lvalue
  doblar(i);  // es correcto
  //doblar(7);  // error, 7 es un rvalue asi que no puede ser asignado por referencia
  doblar2(27);//ya que la funcion recibe una referencia const,seria posible admitir 27 por referencia
  int && rvalue_ref = 99; //asi se declara una referencia a rvalue
  cout<<rvalue_ref<<endl;
  doblarRV(9);//la funcion solo admite una referencia rvalue
  
   return 0;
}
