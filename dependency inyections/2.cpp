#include <iostream>
#include <string>
using namespace std;


class IArma 
{
	public:
        virtual void Disparar()=0;
};

class Revolver : public IArma
{
    public:
	void Disparar()
    {
        cout<< "Pum Pum ..\n";
    }
};

class Rifle : public IArma
{
    public:
	void Disparar()
    {
        cout<< "Pum pum pum pum pum ..\n";
    }
};

class Escopeta : public IArma
{   
    public:
	void Disparar()
    {
        cout<< "pum PUMMM !! ..\n";
    }
};

class Soldado
{
    IArma *arma;

    public:
	Soldado(IArma *_arma)
    {
    arma =_arma;
    }
   void setArma(IArma *_arma)
    {
    arma =_arma;
    }

    void Disparar()
    {
        this->arma->Disparar();
    }
};

int main(){
	Soldado a(new Escopeta);
	a.Disparar();
	a.setArma(new Rifle);
	a.Disparar();
	a.setArma(new Revolver);
	a.Disparar();
	return 0;
}
