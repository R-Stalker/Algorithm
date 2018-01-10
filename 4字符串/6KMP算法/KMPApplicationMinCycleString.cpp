

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;


int MinCycleString(const char *p){
	int nLen = (int)strlen(p);
	if(nLen == 0){
		return -1;
	}
	int *next = new int[nLen];//模仿KMP求"伪next"
	next[0] = -1; //哨兵：串首标志
	int k = -1;
	int j = 0;
	while (j < nLen - 1){
		if( (k == -1) || (p[j+1] == p[k]) ){
			++k;
			++j;
			next[j] = k;
		}else{
			k = next[k];
		}
	}
	next[0] = 0; //恢复成逻辑上的0

	int nLast = next[nLen - 1];
	delete[] next;
	if(nLast == 0){
		return -1;
	}
	if(nLen % (nLen-nLast) == 0){
		return nLen-nLast;
	}
	return -1;
}

int main(){
	const char *p = "abcabcabcabcabcabc";
	cout << MinCycleString(p) << endl;
	return 0;
}
