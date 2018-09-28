#include <iostream>
#include <string>
#include <cassert>
using std::cout;
using std::endl;
using std::string;

template <typename Type> class Stack{
private:
	Type *elements;
	int max_size, top_index;
public:
	Stack(int input_size){
		elements = new Type[input_size];
		max_size = input_size;
		top_index = -1;
	}
	~Stack(){
		delete[] elements;
	}
	bool push(const Type &element){
		if(top_index + 1 >= max_size){
			return false;
		}
		top_index++;
		elements[top_index] = element;
		return true;
	}
	bool pop(){
		if(top_index < 0){
			return false;
		}
		top_index--;
		return true;
	}
	bool empty(){
		return top_index < 0;
	}
	Type top(){
		assert(top_index >= 0);
		return elements[top_index];
	}
};

int main(){
	return 0;
}