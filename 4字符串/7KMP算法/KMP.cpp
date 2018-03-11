/*
KMP算法
*/

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

void GetNext(const char *p, int next[]){
	int nLen = (int)strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while( j < nLen - 1){
		//此刻，k即next[j-1]，且p[k]表示前缀，p[j]表示后缀
		//注：k==-1表示未找到k前缀与k后缀相等，首次分析可先忽略
		if(k == -1 || p[j] == p[k])
		{
			++j;
			++k;
			next[j] = k;
		}
		else	//p[j]与p[k]失配，则继续递归计算前缀p[next[k]]
		{
			k = next[k];
		}
	}
}

//优化的next
void GetNext2(const char* p,int next[])
{
	int nLen = (int)strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < nLen - 1)
	{
		if(k == -1 || p[j] == p[k])
		{
			++j;
			++k;
			if(p[j] == p[k])
				next[j] = next[k];
			else
				next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

int KMP(const char *g_pattern, const char *g_s, int g_next[]){
	int ans = -1;
	int n = strlen(g_s);
	int i = 0;
	int j = 0;
	int pattern_len = strlen(g_pattern);
	while(i < n){
		if(j == -1 || g_s[i] == g_pattern[j]){
			++i;
			++j;
		}else{
			j = g_next[j];
		}
		if(j == pattern_len){
			ans = i - pattern_len;
			break;
		}
	}
	return ans;
}

int main(){
	const char *g_s = "abcdefghijk";
	const char *g_pattern = "efg";
	int *next = new int[strlen(g_pattern)];
	GetNext2(g_pattern, next);
	int result = KMP(g_pattern, g_s, next);
	cout << result << endl;
	return 0;
}
