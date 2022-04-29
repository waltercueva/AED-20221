#include <cstdlib>//srand
#include <ctime>//time
#include <cstdio>//printf
#include <iostream>
#include <functional>
#include <string>
using std::function;
using std::cin;
using std::string;
template <class G>
class Vector {
private:
	G* arr;
	long id;
	unsigned long size;
public:
	Vector(unsigned long size=10):size(size),id(-1) {
		arr = new G[size];	
	}
	/*void increment() {
		G* arrT= new G[size*1.3];
		for (size_t i = 0;i < size;++i) {
			arrT[i] = arr[i];
		}
		delete arr;
		arr = arrT;
	}*/
	void swap(G* a, G* b)
	{
		G temp = *a;
		*a = *b;
		*b = temp;
	}
	
	void randomize()
	{
		for (int i = id; i > 0; i--)
		{
			int j = rand() % (i + 1);
			swap(&arr[i], &arr[j]);
		}
	}
	void bubbleSortV1() {//lenta(n^2)
		for (size_t i = 0;i <= id-1;++i) {
			for (size_t j = 0;j <= id - 1;++j) {
				if (arr[j] > arr[j + 1])
					swap(&arr[j], &arr[j + 1]);
			}
		}	
	}
	void bubbleSortV2() {//Promedio(n(n-1)/2)
		for (size_t i = 0;i <= id - 1;++i) {
			for (size_t j = 0;j <= id - 1-i;++j) {//reducir la cantidad de comparaciones en cada iteracion 
				if (arr[j] > arr[j + 1])
					swap(&arr[j], &arr[j + 1]);
			}
		}
	}
	void bubbleSortV3() {//Optimo(n(n-1)/2)
		bool sorted;
		for (size_t i = 0;i <= id - 1;++i) {
			sorted = true;//supuesto que esta ordenado
			for (size_t j = 0;j <= id - 1 - i;++j) {//reducir la cantidad de comparaciones en cada iteracion 
				if (arr[j] > arr[j + 1]) {
					swap(&arr[j], &arr[j + 1]);
					sorted = false;
				}
			}
			if (sorted)break;
		}
	}
	void bubbleSortV4(function<bool(G,G)> func) {//Optimo(n(n-1)/2)
		bool sorted;
		for (size_t i = 0;i <= id - 1;++i) {
			sorted = true;//supuesto que esta ordenado
			for (size_t j = 0;j <= id - 1 - i;++j) {//reducir la cantidad de comparaciones en cada iteracion 
				if (func(arr[j],arr[j + 1])) {
					swap(&arr[j], &arr[j + 1]);
					sorted = false;
				}
			}
			if (sorted)break;
		}
	}


	void iterate(function<void(G)> func)
	{
		for (int i = 0; i <= id; i++)
			func(arr[i]);
	}
	void push_back(G v) {arr[++id] = v;
	//incrementar
	}
};
struct Real {
	unsigned short entera;
	unsigned short decimal;
	Real(unsigned short entera=0, unsigned short decimal=0) :entera(entera), decimal(decimal) {}
};
class Persona {
public://TO-DO
	string nombre;
	unsigned short edad;
	Persona(string nombre="", unsigned short edad=20) :nombre(nombre), edad(edad) {}
};
int main()
{	srand(time(NULL));	
	Vector<int> vEnteros(25);
	for (int i = 0;i < 25;++i)
		vEnteros.push_back(i);
	vEnteros.iterate([](int v) {printf("%d ", v);});
	printf("\n");
	vEnteros.randomize();
	vEnteros.iterate([](int v) {printf("%d ", v);});
	printf("\n");
	vEnteros.bubbleSortV4([](int v1, int v2) {return v1 > v2;});
	vEnteros.iterate([](int v) {printf("%d ", v);});
	printf("\n");

	
	//----------------------------------------------
	Vector<Real> vReal(15);
	for (int i = 0;i < 15;++i)
		vReal.push_back(Real(i, rand()));
	vReal.iterate([](Real v) {printf("(%d,%d)\n", v.entera,v.decimal);});		                 
	printf("\n");
	vReal.randomize();
	vReal.iterate([](Real v) {printf("(%d,%d)\n", v.entera, v.decimal);});
	printf("\n");	
	vReal.bubbleSortV4([](Real v1, Real v2) {return v1.entera > v2.entera;});
	vReal.iterate([](Real v) {printf("(%d,%d)\n", v.entera, v.decimal);});//imprimir
	vReal.iterate([](Real v) {if (v.entera > 0)std::cout << v.entera;});//comparar
	vReal.iterate([](Real v) {if (v.entera == 10) std::cout << v.entera;});//busqueda
	printf("\n");

	//----------------------------------------------
	Vector<Persona> vPersonas(3);
	vPersonas.push_back(Persona("Luis", 19));
	vPersonas.push_back(Persona("Barbara", 17));
	vPersonas.push_back(Persona("Shayla", 18));
	vPersonas.iterate([](Persona v) {std::cout << v.nombre << "-" << v.edad << "\n";});
	//vPersonas.bubbleSortV4([](Persona v1, Persona v2) {return v1.nombre.compare(v2.nombre)>0;});
	vPersonas.bubbleSortV4([](Persona v1, Persona v2) {return v1.edad>v2.edad;});
	std::cout << "\n\n";
	
	vPersonas.iterate([](Persona v) {std::cout<<v.nombre<<"-"<<v.edad<<"\n";});
	cin.ignore();
	cin.get();
	return 0;
}
