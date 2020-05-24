#include<iostream>
using namespace std;

class Curso{
        public:
		string nombre;
		string codigo;
		int nroAlumnos;
		Curso()
		{ nombre="o";
		  codigo="o";
		  nroAlumnos=0;
		}
		Curso(string nom, string cod, int nro)
		{ nombre=nom;
		  codigo=cod;
		  nroAlumnos=nro;
		}
        string getNombre() const;
        string getCodigo() const;
        int getNroAlumnos() const;
        void setNombre(const string nombre);
        void setCodigo(const string codigo);
        void setNroAlumnos(const int nroAlumnos);
};

string Curso::getNombre() const
{
	return nombre;
}
string Curso::getCodigo() const
{
	return codigo;
}
int Curso::getNroAlumnos() const
{
	return nroAlumnos;
}

void Curso::setNombre(const string name)
{   
	nombre=name;
}
void Curso::setCodigo(const string cod)
{   
	codigo=cod;
}
void Curso::setNroAlumnos(const int nro)
{   
	nroAlumnos=nro;
}
int main()
{
   Curso arte;
   arte.setNombre("Maryori");
   cout<<arte.getNombre();
   return 0;
}
