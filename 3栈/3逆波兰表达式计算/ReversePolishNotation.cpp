#include <iostream>
#include <cassert>
#include <string>
#include <cctype>
using std::cin;
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
	Type top(){
		assert(top_index >= 0);
		return elements[top_index];
	}
	bool empty(){
		return top_index < 0;
	}
};

int Calculate(int &num1, int &num2, char op){
	if(op == '+'){
		return num1 + num2;
	}else if(op == '-'){
		return num1 - num2;
	}else if(op == '*'){
		return num1 * num2;
	}else if(op == '/'){
		return num1 / num2;
	}else{
        return -1;
	}
}

bool OperatorPriority(char a, char b){
	if((a == '*' || a == '/') && (b == '+' || b == '-')){
		return true;
	}
	return false;
}

int ReversePolishNotation(string &str){
	int size = str.length();
	Stack<int> nums(size);
	Stack<char> ops(size);
	for(int i = 0; i < size; i++){
		if(isdigit(str[i])){
			nums.push(str[i] - '0');
		}else{
			if(!ops.empty() && OperatorPriority(ops.top(),str[i])){
				int n1 = nums.top();
				nums.pop();
				int n2 = nums.top();
				nums.pop();
				nums.push(Calculate(n2, n1, ops.top()));
				ops.pop();
			}
			ops.push(str[i]);
		}
	}
	while(!ops.empty()){
		int n1 = nums.top();
		nums.pop();
		int n2 = nums.top();
		nums.pop();
		nums.push(Calculate(n2, n1, ops.top()));
		ops.pop();
	}
	return nums.top();
}

int main(){
	string str;
	cout << "输入式子(如：5+2*3-4/2):  " << endl;
	cin >> str;
	cout << ReversePolishNotation(str);
	return 0;
}
