#include <iostream>
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
//---------
class ArregloDeCursos{
	int tamanio;
    Curso *ptrcurso;	
	void redimensionar(int n);
	public:
		ArregloDeCursos();
		ArregloDeCursos(const Curso cursos[], const int tam);
		ArregloDeCursos(const ArregloDeCursos &o);
		~ArregloDeCursos();
		const int getSize() const;
		const Curso getCursos() const;
		void pushBack(const Curso &p);
		void insert(const int posicion,const Curso &p);
		void remove(const int pos);
        void clear(); 
		void mostrarCursos(); 
};

ArregloDeCursos::ArregloDeCursos(const Curso cursos[], const int tam){   
   tamanio=tam;
   ptrcurso=new Curso[tamanio];
   for(int i=0;i<tam;i++){
   	  *(ptrcurso+i)=cursos[i];
   }
}
ArregloDeCursos::ArregloDeCursos(){   
   tamanio=0;
   ptrcurso=new Curso[tamanio];
}
ArregloDeCursos::ArregloDeCursos(const ArregloDeCursos &o){
	tamanio=o.tamanio;
	ptrcurso=new Curso[tamanio];
	for(int i=0;i<tamanio;i++){
   	  *(ptrcurso+i)=*(o.ptrcurso+i);
   }
}
ArregloDeCursos::~ArregloDeCursos(){
  delete[] ptrcurso;  }
const int ArregloDeCursos::getSize() const{	
         return tamanio;
}
void ArregloDeCursos::redimensionar(int n){
	Curso *aux= new Curso[n];
	for(int i = 0; i < tamanio ; i++)
    {
        aux[i] = ptrcurso[i];
    }
        delete[] ptrcurso;

    ptrcurso = aux;
    tamanio=n;
}

void ArregloDeCursos::pushBack(const Curso &p){  ///adiciona un curso al final del arreglo 

  redimensionar(tamanio+1);
  ptrcurso[tamanio-1]=p;
}
void ArregloDeCursos::insert(const int posicion, const Curso &p){//inserta un curso en x posicion
    redimensionar(tamanio+1);
	for(int i=tamanio-1;i>posicion;i--){
		*(ptrcurso+i)=*(ptrcurso+i-1);
	}
	*(ptrcurso+posicion)=p;
	tamanio++;
}
void ArregloDeCursos::remove(const int pos){ //elimina un curso F
	for(int i=pos;i<tamanio-1;i++){
		*(ptrcurso+i)=*(ptrcurso+i+1);
	}
	redimensionar(tamanio-1);
	tamanio--;
}
void ArregloDeCursos::clear(){ ///elimina el arreglo de cursos
	delete [] ptrcurso;
	ptrcurso=new Curso[tamanio];	
}
void ArregloDeCursos::mostrarCursos(){ // muestra el arreglo de cursos
	for(int i=0; i<tamanio; ++i)
{	  cout<<ptrcurso[i].getNombre()<<" ";
	  cout<<ptrcurso[i].getCodigo()<<" ";
	  cout<<ptrcurso[i].getNroAlumnos()<<endl;
    }
}



int main(){
	Curso arte("Panchita", "ar202001", 1), literatura("Maria", "lt2020001", 1), computo("Tadeo", "cm202001", 1), matematicas("Juan", "mt202001", 1);
	Curso cursos[] = {arte,literatura,computo};
	ArregloDeCursos arr(cursos, 3);
	arr.mostrarCursos();
	cout<<"------"<<endl;
	arr.pushBack(matematicas);//adicionamos un curso
	arr.mostrarCursos();
	cout<<"------"<<endl;
	arr.insert(1,arte);	//insertando un curso en la posicion
	arr.mostrarCursos();
	cout<<"------"<<endl;
	return 0;
}
