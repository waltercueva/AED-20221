#include <iostream>
#include <functional>
#include <vector>
#include <string>
using namespace std;
template<class G>
class Tree {
	template<class T>
	class Node {//inner class(composicion)
	public:
		Node<T>* l, * r;
		T data;
		Node(T d) :data(d) { l = r = nullptr; }
	};
	Node<G>* root;
	//function<bool(G, G)> cmp;
	bool(*cmp)(G, G);
	//function<void(G)> imp;
	void (*imp)(G);
public:
	//Tree(function<bool(G, G)> cmp, function<void(G)> imp):cmp(cmp),imp(imp) { root = nullptr; }
	Tree(bool(*cmp)(G, G), void (*imp)(G)) :cmp(cmp), imp(imp) { root = nullptr; }
	void insert(G e, Node<G>*& tmp) {
		if (tmp == nullptr)
			tmp = new Node<G>(e);
		//else if (e>= tmp->data)
		else if (cmp(e,tmp->data))//insero a la derecha
			insert(e, tmp->r);
		else insert(e, tmp->l);

	}
	void insert(G e) {
		insert(e, root);
	}
	void print() { print(root); }
	void print(Node<G>* tmp) {//enOrden
		if (tmp == nullptr)return;
		print(tmp->l);
		imp(tmp->data);
		//cout << tmp->data << " ";
		print(tmp->r);
	}
	void preOrden(Node<G>* tmp) {//preOrden
		if (tmp == nullptr)return;
		cout << tmp->data << " ";//lista->push_back(tmp->data);
		preOrden(tmp->l);
		preOrden(tmp->r);
	}
	void postOrden(Node<G>* tmp) {//postOrden
		if (tmp == nullptr)return;
		postOrden(tmp->l);
		postOrden(tmp->r);
		cout << tmp->data << " ";
	}
};
class Registro {
	short x;
	char y;
	string z;
	friend class Coleccion;
public:
	Registro(short x,char y,string z):x(x),y(y),z(z) {}
	string toString() { return "("+to_string(x) + " " + y + " " + z+")"; }
};
class Coleccion {
	Tree<Registro>* arbolX;
	Tree<Registro>* arbolY;
	Tree<Registro>* arbolZ;
	vector<Registro> vecR;
public:
	Coleccion() {
		auto l = [](Registro x) {cout << x.toString() << endl;};
		arbolX = new Tree<Registro>([](Registro a, Registro b) {return a.x >= b.x;},l);//criterio de indexacion
		arbolY = new Tree<Registro>([](Registro a, Registro b) {return a.y >= b.y;},l);
		arbolZ = new Tree<Registro>([](Registro a, Registro b) {return a.z.compare(b.z)>0;},l);
	
	}
	void datos() {
		for (size_t i = 0;i < 10;++i) {
			vecR.push_back(Registro(rand() % 1000, rand() % 26 + 65, "v" + to_string(rand() % 1000)));
		}
	}
	void indexar() {
		for (size_t i = 0;i < vecR.size();++i) {
			arbolX->insert(vecR[i]);
			arbolY->insert(vecR[i]);
			arbolZ->insert(vecR[i]);
		}
	}
	void imprimir() {
		arbolX->print();
		cout << "\n\n";
		arbolY->print();
		cout << "\n\n";
		arbolZ->print();
	}
};
int main() {
	Coleccion c;
	c.datos();
	c.indexar();
	c.imprimir();
	return 0;
}
