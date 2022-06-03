#include<iostream>
#include<vector>
#include <string>
#include<functional>
using namespace std;
template<typename T>
class Array {
	vector<T> vec;
private:
	long binarySearch(function<int(T)> cmp, int s, int e) {//Recursivo
		if (s <= e) {
			int m = (s + e) / 2;
			if (cmp(vec[m]) == 0)return m;//encontró
			else if (cmp(vec[m]) < 0)return binarySearch(cmp, s, m - 1);
			else return binarySearch(cmp, m + 1, e);
		}
		return -1;
	}
public:
	long linearSearch(function<bool(T)> cmp) {
		for (size_t i = 0; i < vec.size(); i++)
			if (cmp(vec.at(i))) return i;		
		return -1;
	}
	
	long binarySearch(function<int(T)> cmp) {
		return binarySearch(cmp, 0, vec.size() - 1);
	}
	long searchBinary(function<int(T)>verificar) {
		long inicio = 0;
		long fin = vec.size() - 1;
		while (inicio <= fin) {
			long medio = (inicio + fin) / 2;
			if (verificar(vec.at(medio)) == 1) { return medio; }
			else if (verificar(vec.at(medio)) == 2) { inicio = medio + 1; }//derecha
			else { fin = medio - 1; }//izquierda
		}
		return -1;
	}
	void add(T e) { vec.push_back(e); }
};


int main() {
	srand(time(NULL));
	Array<int> arreglo;
	for (size_t i = 0; i < 10; i++) {
		arreglo.add(i+1);		
	}
	cout << endl;
	int aux;
	cout << "Digite el numero a buscar: "; cin >> aux;
	cout << arreglo.linearSearch([=](int x) {return x == aux;})<<endl;
	cout << arreglo.binarySearch([=](int x) {
		if (x == aux)return 0;
		else if (x > aux)return -1;
		else return 1;})<< endl;
	cout << endl;
	//probando para string
	Array<string> arrS;
	arrS.add("Ana");
	arrS.add("Beatriz");
	arrS.add("Carlos");
	arrS.add("Edwin");
	arrS.add("Fidel");
	
	cout << endl;
	string tmp;
	cout << "Digite el nombre a buscar: "; cin >> tmp;
	cout << arrS.linearSearch([=](string x) {return x.compare(tmp)==0;}) << endl;
	cout << arrS.binarySearch([=](string x) {return x.compare(tmp);}) << endl;
	cout << endl;


	cout << arreglo.searchBinary([=](int num)->int {if (num == aux) {
		return 1;	}

	else if (num < aux) {
		return 2;	}
	else {
		return 0;
	}});


	return 0;
}
