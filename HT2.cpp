#include <array>
#include <list>
#include <vector>
#include <iostream>

using namespace std;
typedef unsigned long ul;
class Entity {
	ul key;
	ul value;
	friend class HT;
public: Entity(ul k=0, ul v=0) :key(k), value(v) {}
};
class HT {
	array<list<Entity>, 5> container;
public:	
	ul getIndex(ul key) { return key % 5; }
	void add(ul key, ul value) { container[getIndex(key)].push_back(Entity(key,value)); }
	void display() {
		for (size_t i = 0;i < container.size();++i) {//recorre el array
			cout << i << "->";
			/*for (list<Entity>::iterator it = container[i].begin();it != container[i].end();++it) {
				cout <<"("<<(*it).key << "-" << (*it).value << ")-> ";
			}*/
			for (auto it:container[i]) {
				cout << "(" << it.key << "-" << it.value << ")-> ";
			}
			cout << "\n";
		}
	}
};
int main() {
	/*vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	//vector<int>::iterator i;//recorrer direcciones de memoria
	
	for (vector<int>::iterator i = vec.begin();i != vec.end();++i) {
		cout << *i << " ";
	}
	*/

	HT ht;
	ht.add(500,100);
	ht.add(1000,150);
	ht.add(738,200);
	ht.add(801,250);
	ht.add(603,300);
	ht.display();
	return 0;
}
