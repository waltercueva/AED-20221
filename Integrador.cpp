#include <iostream>
#include <string>
#include <functional>
#include <fstream>
using namespace std;

template<class Generico>
class Nodo {
public:
	Generico elemento;
	Nodo<Generico>* sig;
	Nodo(Generico e) {
		elemento = e;
		sig = nullptr;
	}
};
template<class Generico>
class Lista {	
	Nodo<Generico>* inicio;
	Nodo<Generico>* fin;
	size_t cantidad;
public:
	Lista() {
		inicio=fin= nullptr;
		cantidad = 0;
	}
	void push_front(Generico e) {//Ojo: es lista simple, cambiarlo
		Nodo<Generico>* n = new Nodo<Generico>(e);
		if (cantidad == 0)
			inicio = n;
		else {
			n->sig = inicio;
			inicio = n;
		}
		++cantidad;
	}
	void push_back_lineal(Generico elem) {
		Nodo<Generico>* nuevo = new Nodo<Generico>(elem);
		if(cantidad == 0)
			inicio = nuevo;		
		else
		{
			Nodo<Generico>* aux = inicio;
			while (aux->sig != nullptr)
			aux = aux->sig;
			aux->sig = nuevo;
		}
		cantidad++;
	}
	void push_back_1(Generico e){
		Nodo<Generico>* nuevo=new Nodo<Generico>(e);
		if(inicio==nullptr)//cantidad==0
			inicio=fin=nuevo;
		else{
			fin->sig=nuevo;
			fin=nuevo;
		}
		cantidad++;
	}
	void print() {
		Nodo<Generico>* aux = inicio;
		while (aux->sig != nullptr) {			
			cout<<aux->elemento<<" ";
			aux = aux->sig;
		}
		cout << aux->elemento;
	}	

	void print(function<void(Generico)> imprime) {
		Nodo<Generico>* aux = inicio;
		while (aux != nullptr) {
			imprime(aux->elemento);//será enviado desde otro lugar
			//cout<<aux->elemento<<" ";
			aux = aux->sig;
		}		
	}
};

class Estudiante {
public://TO-DO private
	string  nombre;
	long dni;
	Estudiante(string  nombre="", long dni=0) :nombre(nombre), dni(dni) {}
	string toString() { return nombre + " " + to_string(dni);}
};

class ListaEstudiante {
	Lista<Estudiante> estudiantes;
	ofstream archivo;
public:
	ListaEstudiante() {
		archivo.open("texto.txt");
	}
	void insercion() {
		string nombre; long dni;
		char opcion;
		do {
			cout << "Ingrese nombre: ";
			cin >> nombre;
			cout << "Ingrese dni: ";
			cin >> dni;
			estudiantes.push_back_1(Estudiante(nombre, dni));
			archivo << nombre << " " << dni << endl;
			cout << "Desea continuar (S/N)";
			cin >> opcion;
		} while (opcion == 'S');
		archivo.close();
	}	
	void listar() {
		estudiantes.print([](Estudiante e) {cout << e.toString() << endl;});
	}
	//eliminacion
	//busqueda
	//....
	
};
// Ejemplo de entidades adicionales
class Controladora {
	ListaEstudiante* registros;
public:
	Controladora() {
		registros = new ListaEstudiante();
	}
	
	void run() {
		registros->insercion();
		registros->listar();
	}
};

int main() {
	Controladora c;
	c.run();	
	return 0;
}
