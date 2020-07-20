#include <iostream>
using namespace std;

void unir(string& a, string& b) {
    string tmp(std::move(a)); //convierte a a un rvalue
    tmp += std::move(b);   
    cout<<tmp;
}

int main(){
	string a,b;
	a="hola ";
	b="a todos ";
    unir(a,b); 
	return 0;
}
