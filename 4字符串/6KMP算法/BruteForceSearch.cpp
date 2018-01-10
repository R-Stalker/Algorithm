/*
暴力法求解,时间复杂度O(m*n)
*/

#include <iostream>
#include <cstring>

using std::endl;
using std::cout;

//查找s中首次出现p的位置
int BruteForceSearch(const char *s, const char *p){
	int i = 0; //当前匹配到的待查串首位
	int j = 0; //模式串的匹配位置
	int size = (int)strlen(p);
	int nLast = (int)strlen(s) - size;
	while( (i <= nLast) && (j < size) ){
		if(s[i+j] == p[j]){ //若匹配，模式串匹配位置后移
			j++;
		}else{	//不匹配，则对比下一个位置，模式串回溯到首位
			i++;
			j = 0;
		}
	}
	if(j >= size){
		return i;
	}
	return -1;
}

int main(){
	const char *s = "abcdefg";
	const char *p = "cde";
	cout << BruteForceSearch(s, p);
	return 0;
}


