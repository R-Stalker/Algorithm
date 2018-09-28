#include <iostream>
using std::cout;
using std::endl;

template <typename Type> class Queue{
private:
	Type *data;
	int length, head, tail, count;
public:
	Queue(int input_length){
		data = new Type[input_length];
		length = input_length;
		head = 0;
		tail = -1;
		count = 0;
	}
	~Queue(){
		delete[] data;
	}
	bool push(Type element){
		if(count >= length){
			return false;
		}
		tail = (tail + 1) % length;
		data[tail] = element;
		count++;
		return true;
	}
	void pop(){
		head = (head + 1) % length;
		count--;
	}
	void output(){
		int i = head;
		do{
			cout << data[i] << " ";
			i = (i + 1) % length;
		}while(i != (tail + 1) % length);
		cout << endl;
	}
	Type front(){
		return data[head];
	}
	bool empty(){
		return count == 0;
	}
};

int main(){
	return 0;
}