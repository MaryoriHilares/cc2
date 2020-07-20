#include <iostream>
 #include <string>
 using namespace std; 
class Perro
{
    std::string nombre;
    std::string raza;
public:
	Perro(){
		nombre=" ";
		raza=" ";
	}
	Perro(const Perro &perro){
		nombre=perro.nombre;
		raza=perro.raza;
	}
	Perro(std::string name,std::string raza){
		nombre=name;
		this->raza=raza;
	}
	Perro(Perro &&perro){ //<- entrada de referencia a un rvalue
		nombre=perro.nombre;
		raza=perro.raza;
		perro.nombre= " ";
	    perro.raza= " ";
		 cout<<"Usted llamo al operador de movimiento"<<endl;	
	}
    Perro& operator=(Perro&& other)     // <-- rvalue reference in input  
{  
        if (this == &other) return *this;

  
        nombre = other.nombre;   
        raza = other.raza;

        other.nombre= " ";
	    other.raza= " ";
	    cout<<"Usted llamo al operador de asignacion "<<endl;

  return *this;
}
    friend std::ostream& operator<< (std::ostream &out, const Perro &perro);
    friend std::istream& operator>> (std::istream &in, Perro &perro);
    bool operator== (const Perro &perro);
    bool operator!= (const Perro &perro);
};
 
std::ostream& operator<< (std::ostream &out, const Perro &perro)
{
    out <<"Nombre: "<<perro.nombre<<"  Raza:"<<perro.raza<<"\n";
 
    return out;
}
 
std::istream& operator>> (std::istream &in, Perro &perro)
{
    cout<<"Nombre: ";	in >> perro.nombre;
	cout<<"Raza: "; in>>perro.raza;
 
    return in;
}


bool Perro::operator== (const Perro &perro){
	if(this->nombre==perro.nombre && raza ==perro.raza)
	   return true;
	else
    	return false;
}

bool Perro::operator!= (const Perro &perro){
	if(this->nombre==perro.nombre && raza==perro.raza)
	   return false;
	else
    	return true;
}

int main(){
	Perro p1("Adobo", "Desconocida");
	Perro p2("Chamuquito" , "Pitbul");
	Perro p3=std::move(p2);
	
	cout<<p3<<p2<<endl;
	
	p2=std::move(p3);
	cout<<p1<<p3<<endl;
	return 0;
}
