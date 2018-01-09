//LIS的动态规划解法

#include <iostream>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int LIS(const int* p, int length, int *pre, int &nIndex){
	int *longest = new int[length];
	for(int i = 0; i < length; i++){
		longest[i] = 1;
		pre[i] = -1;
	}

	int nLis = 1;
	nIndex = 0;
	for(int i = 0; i < length; i++){
		for(int j = 0; j < i; j++){
			if(p[j] <= p[i]){
				if(longest[i] < longest[j]+1){
					longest[i] = longest[j]+1;
					pre[i] = j;
				}
			}
		}
		if(nLis < longest[i]){
			nLis = longest[i];
			nIndex = i;
		}
	}
	delete[] longest;
	return nLis;
}

void GetLIS(const int* array, const int *pre, int nIndex, vector<int> &lis){
	while(nIndex >= 0){
		lis.push_back(array[nIndex]);
		nIndex = pre[nIndex];
	}
	reverse(lis.begin(), lis.end());
}

void Print(int *p, int size){
	for(int i = 0; i < size; i++){
		cout << p[i] << '\t';
	}
	cout << endl;
}

int main(){
	int array[] = {1,4,5,6,2,3,8,9,10,11,12,12,1};
	int size = sizeof(array)/sizeof(int);
	int *pre = new int[size];
	int nIndex;
	int max = LIS(array, size, pre, nIndex);
	vector<int> lis;
	GetLIS(array, pre, nIndex, lis);
	delete[] pre;
	cout << max << endl;
	Print(&lis.front(), lis.size());
	return 0;
}
//LIS的动态规划解法

#include <iostream>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int LIS(const int* p, int length, int *pre, int &nIndex){
	int *longest = new int[length];
	for(int i = 0; i < length; i++){
		longest[i] = 1;
		pre[i] = -1;
	}

	int nLis = 1;
	nIndex = 0;
	for(int i = 0; i < length; i++){
		for(int j = 0; j < i; j++){
			if(p[j] <= p[i]){
				if(longest[i] < longest[j]+1){
					longest[i] = longest[j]+1;
					pre[i] = j;
				}
			}
		}
		if(nLis < longest[i]){
			nLis = longest[i];
			nIndex = i;
		}
	}
	delete[] longest;
	return nLis;
}

void GetLIS(const int* array, const int *pre, int nIndex, vector<int> &lis){
	while(nIndex >= 0){
		lis.push_back(array[nIndex]);
		nIndex = pre[nIndex];
	}
	reverse(lis.begin(), lis.end());
}

void Print(int *p, int size){
	for(int i = 0; i < size; i++){
		cout << p[i] << '\t';
	}
	cout << endl;
}

int main(){
	int array[] = {1,4,5,6,2,3,8,9,10,11,12,12,1};
	int size = sizeof(array)/sizeof(int);
	int *pre = new int[size];
	int nIndex;
	int max = LIS(array, size, pre, nIndex);
	vector<int> lis;
	GetLIS(array, pre, nIndex, lis);
	delete[] pre;
	cout << max << endl;
	Print(&lis.front(), lis.size());
	return 0;
}
