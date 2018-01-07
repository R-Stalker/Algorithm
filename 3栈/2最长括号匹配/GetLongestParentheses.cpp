#include <iostream>
#include <cassert>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;

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

int GetLongestParentheses(string &str){
	int size = str.length();
	Stack<int> s(size);
	int answer = 0;//最终解
	int start = -1;//左括号的前一个位置
	for(int i = 0; i < size; i++){
		if(str[i] == '('){
			s.push(i);
		}
		else{	//p[i] == ')'
			if(s.empty()){
				start = i;
			}
			else{
				s.pop();
				if(s.empty()){
					answer = max(answer, i - start);
				}else{
					answer = max(answer, i - s.top());
				}
			}
		}
	}
	return answer;
}

int main(){
	string str;
	cout << "输入由'('和')'构成的括号串:";
	cin >> str;
	int result = GetLongestParentheses(str);
	cout << "最长匹配括号子串长度:" << result << endl;
	return 0;
}

