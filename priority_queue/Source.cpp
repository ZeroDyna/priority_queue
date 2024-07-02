#include<iostream>
#include <vector> //es mejor usar un array dinamico para al moemeno de implementar 
template<class T>
class priority {
public:
	std::vector<int> map;
	void push(int valor);
	void del(int valor);
	void heapify();
};
template<class T>
void priority<T>::heapify() {
	
}
int main() {
	return 0;
}