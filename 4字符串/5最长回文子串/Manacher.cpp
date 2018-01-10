/*
暴力法：时间复杂度为O(N^3)  / i:0...N    j:i...N   判断A[i...j]是否回文
中心法：时间复杂度为O(N^2) = O(2N-1) * O(N)
Manncher:时间复杂度为O(N)  /即改进的中心法,计算P[i]的时候，有可能通过P[0...i-1]，而不需重新计算，从而节省时间.
*/

#include <iostream>
#include <cstring>
#include <string>
using std::cout;
using std::endl;
using std::min;
using std::string;

void Manncher(char *s, int *P){
	int size = strlen(s);
	P[0] = 1;
	int id = 0;
	int mx = 1;
	for(int i = 1; i < size; i++){
		if(mx > i){
			P[i] = min(P[2*id-i], mx-i);
		}
		else{
			P[i] = 1;
		}
		for(; s[i+P[i]] == s[i-P[i]]; P[i]++);

		if(mx < i+P[i]){
			mx = i + P[i];
			id = i;
		}
	}
}

int main(){
	char str[] = {'1','2','2','1','2','3','3','2','1','2'};
	int size = sizeof(str)/sizeof(char);

	//为了方便，str转变为s,s为#1#2#2#1#2#3#2#1#3#2#
	char *s = new char[2*size+1];
	int index = 0;
	for(int i = 0; i < size; i++){
		s[index] = '#';
		s[index+1] = str[i];
		index += 2;
	}
	s[index] = '#';

	int *p = new int[index+1];
	Manncher(s, p);
	int maxp = 0;//从数组p中找到最长回文子串长度
	int mid = 0;//返回最长回文子串的中心
	for(int i = 0; i < index+1; i++){
		if(maxp < p[i]){
			maxp = p[i];
			mid = i;
		}
	}
	cout << "最长回文子串长度为：" << maxp - 1 << endl;
	string result;
	for(int i = mid - maxp + 2; i <= mid + maxp - 2; i = i+2){
		result.push_back(s[i]);
	}
	cout << "最长回文子串为：" << result << endl;
	return 0;
}
