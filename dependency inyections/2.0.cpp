#include <iostream>
#include <string>
using namespace std;
///Sin usar dependencias
class Revolver {
    public:
	void Disparar() { cout<< "Pum Pum ..\n";}
};

class Rifle {
    public:
	void Disparar()  { cout<< "Pum pum pum pum pum ..\n"; }
};

class Escopeta{
    public:
	void Disparar() { cout<< "pum PUMMM !! ..\n";}
    };

//Como se darán cuenta, las armas implementan el método Disparar(), la cual el disparo varía dependiendo del tipo de arma que se elija.

class Soldado{
	public:
    void DispararRevolver()  {
         Revolver a;
		 a.Disparar();
    }
    void DispararRifle()  {
        Rifle a;
		a.Disparar();
    }
    void DispararEscopeta(){
        Escopeta a;
		a.Disparar();
    }
};

int main(){
	Soldado a;
	a.DispararRevolver();
}
