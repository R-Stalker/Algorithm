#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

void ReverseString(string &s, int from, int to){
	while(from < to){
		char t = s[from];
		s[from] = s[to];
		s[to] = t;
		from++;
		to--;
	}
}

void LeftRotateString(string &s, int n, int m){
	m %= n;
	ReverseString(s, 0, m-1);
	ReverseString(s, m, n-1);
	ReverseString(s, 0, n-1);
}

int main(){
	string str;
	cout << "请输入字符串:";
	cin >> str;
	cout << "请输入左移位数:";
	int m;
	cin >> m;
	LeftRotateString(str, str.length(), m);
	cout << str << endl;
	return 0;
}
