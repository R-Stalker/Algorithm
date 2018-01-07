#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename Type> class Stack{
private:
    Type *elements;
    int top_index, max_size;
public:
    Stack(int input_length){
        elements = new Type[input_length];
        max_size = input_length;
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
    bool empty(){
        return top_index < 0;
    }
    void pop(){
        top_index--;
    }
    Type top(){
        assert(top_index >= 0);
        return elements[top_index];
    }
};

bool IsPossible(const char* strIn, const char* strOut){
	Stack<char> s(strlen(strIn));
	while(*strOut){
		if(!s.empty() && s.top() == *strOut){
			s.pop();
			strOut++;
		}else{
			if(*strIn == 0){
				return false;
			}
			s.push(*strIn);
			strIn++;
		}
	}
	return true;
}

int main(){
	char strIn[] = "ABCD";
	char strOut[] = "BDAC";
	bool b = IsPossible(strIn, strOut);
	if(b){
        cout << "可行" << endl;
	}else{
        cout << "不可能" << endl;
	}
	return 0;
}
