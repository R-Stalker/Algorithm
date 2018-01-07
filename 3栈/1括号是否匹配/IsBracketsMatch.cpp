#include <iostream>
#include <string>
#include <cassert>
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
	bool empty(){
		return top_index < 0;
	}
	Type top(){
		assert(top_index >= 0);
		return elements[top_index];
	}
};

bool IsLeftParentheses(char c){
	return (c == '(') || (c == '{') || (c == '[');
}

bool IsMatch(char left, char c){
	if(left == '('){
		return c == ')';
	}
	if(left == '['){
		return c == ']';
	}
	if(left == '{'){
		return c == '}';
	}
	return false;
}

bool IsParenthesesMatch(string &str){
	Stack<char> s(str.length());
	char cur;
	int i = 0;
	while(str[i] != '\0'){
		cur = str[i];
		if(IsLeftParentheses(cur)){
			s.push(cur);
		}else{
			if(s.empty() || !IsMatch(s.top(), cur)){
				return false;
			}
			s.pop();
		}
		i++;
	}
	return s.empty();
}

int main(){
    string str;
    cout << "请输入括号串:";
	cin >> str;
	bool bMathch = IsParenthesesMatch(str);
	if(bMathch){
		cout << "括号匹配.\n";
	}else{
		cout << "括号不匹配.\n";
	}
	return 0;
}
