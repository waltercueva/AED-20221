#include <iostream>
#include <functional>
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
	public:
		Tree() { root = nullptr; }
		void insert(G e,Node<G>*& tmp ) {
			if (tmp == nullptr)
				tmp = new Node<G>(e);
			else if (e >= tmp->data)//insero a la derecha
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
			cout << tmp->data << " ";
			print(tmp->r);
		}
		void print(Node<G>* tmp) {//preOrden
			if (tmp == nullptr)return;
			cout << tmp->data << " ";
			print(tmp->l);			
			print(tmp->r);
		}
		void print(Node<G>* tmp) {//postOrden
			if (tmp == nullptr)return;			
			print(tmp->l);
			print(tmp->r);
			cout << tmp->data << " ";
		}

};
int main() {
	Tree<int> enteros;
	for (size_t i = 0;i < 1000;++i) {
		enteros.insert(rand() % 100000);
	}	
	enteros.print();
	return 0;
}


