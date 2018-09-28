#include <iostream>
using std::cout;
using std::endl;

template <typename Type> class Queue{
private:
	Type *data;
	int length, head, tail;
public:
	Queue(int input_length){
		data = new Type[input_length];
		length = input_length;
		head = 0;
		tail = -1;
	}
	~Queue(){
		delete[] data;
	}
	bool push(Type element){
		if(tail + 1 >= length){
			return false;
		}
		tail++;
		data[tail] = element;
		return true;
	}
	void pop(){
		head++;
	}
	void output(){
		int count = 0;
		for(int i = head; i <= tail; i++){
			if(count > 0){
				cout << " ";
			}
			cout << data[i];
			count++;
		}
		cout << endl;
	}
	Type front(){
		return data[head];
	}
	bool empty(){
		return head > tail;
	}
};

int main(){
	return 0;
}