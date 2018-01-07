/*不使用栈，空间复杂度O(1)*/
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;

int GetLongestParentheses2(string &str){
	int size = str.length();
	int answer = 0; //最终解
	int deep = 0; //遇到了多少左括号
	int start = -1; //最深的(deep == 0时)左括号的位置
					//其实，为了方便计算长度，该变量是最深左括号的前一个位置
	for(int i = 0; i < size; i++){
		if(str[i] == '('){
			deep++;
		}
		else{
			deep--;
			if(deep == 0){
				answer = max(answer, i - start);
			}
			else if(deep < 0){ //说明右括号数目大于左括号，初始化为for循环前for循环前
				deep = 0;
				start = i;
			}
		}
	}

	deep = 0;//遇到了多少右括号
	start = size; //最深的(deep==0时)右括号的位置
					//其实，为了方便计算长度，该变量是最深右括号的后一个位置
	for(int i = size - 1; i >= 0; i--){
		if(str[i] == ')'){
			deep++;
		}
		else{
			deep--;
			if(deep == 0){
				answer = max(answer, start - i);
			}else if(deep < 0){ //说明左括号数目大于右括号，初始化为for循环前for循环前括号，初始化为for循环前for循环前
				deep = 0;
				start = i;
			}
		}
	}

	return answer;
}

int main(){
	string str;
	cout << "输入由'('和')'构成的括号串:";
	cin >> str;
	int result = GetLongestParentheses2(str);
	cout << "最长匹配括号子串长度:" << result << endl;
	return 0;
}
