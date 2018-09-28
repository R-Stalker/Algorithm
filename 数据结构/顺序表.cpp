#include <iostream>
#include <string>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename Type> class Vector{
private:
	Type *data;
	int size, length;
public:
	Vector(int input_size){
		data = new Type[input_size];
		size = input_size;
		length = 0;
	}
	~Vector(){
		delete[] data;
	}
	bool insert(int loc, Type value){
		if(loc < 0 || loc > length){
			return false;
		}
		if(loc >= size){
			expand();
		}
		for(int i = length; i > loc; i--){
			data[i] = data[i-1];
		}
		data[loc] = value;
		length++;
		return true;
	}
	void expand(){
		Type *old_data = data;
		size = size*2;
		data = new Type[size];
		for(int i = 0; i < length; i++){
			data[i] = old_data[i];
		}
		delete[] old_data;
	}
	bool search(const Type &value){
		for(int i = 0; i < length; i++){
			if(value == data[i]){
				return true;
			}
			return false;
		}
	}
	bool remove(int index){
		if(index < 0 || index >= length){
			return false;
		}
		for(int i = index + 1; i < length; i++){
			data[i-1] = data[i];
		}
		length--;
		return true;
	}
	void print(){
		for(int i = 0; i < length; i++){
			if(i > 0){
				cout << " ";
			}
			cout << data[i];
		}
		cout << endl;
	}
};

int main()
{
	return 0;
}