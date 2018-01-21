#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

//绝对众数：个数大于一半的众数
int FindAbsoluteMode(int *a, int size){
	int count = 0;
	int m = a[0];
	for(int i = 0; i < size; i++){
		if(count == 0){
			m = a[i];
			count = 1;
		}
		else if(m == a[i]){
			count++;
		}else{
			count--;
		}
	}
	return m;
}

//假设寻找个数大于N/k的众数，加入k=3，空间复杂度O(k)，时间复杂度O(N)
int FindMode(const int *a, int size, vector<int> &mode){
	int m, n;//候选值
	int cm = 0, cn = 0;
	for(int i = 0; i < size; i++){
		if(cm == 0){
			m = a[i];
			cm = 1;
		}else if(cn == 0){
			n = a[i];
			cn = 1;
		}else if(a[i] == m){
			cm++;
		}else if(a[i] == n){
			cn++;
		}else{ //同时删除a[i],m,n;
			cm--;
			cn--;
		}
	}
	cm = cn = 0;
	for(int i = 0; i < size; i++){
		if(a[i] == m){
			cm++;
		}else if(a[i] == n){
			cn++;
		}
	}
	if(cm > size/3){
		mode.push_back(m);
	}
	if(cn > size/3){
		mode.push_back(n);
	}
	return 0;
}

int main(){
	int a[] = {8,8,1,1,1,8,1,1,6,1,8};
	int m = FindAbsoluteMode(a, sizeof(a)/sizeof(int));
	cout << m << endl;
	int b[] = {1,2,3,2,5,2,2,3,3,2,3};
	vector<int> mode;
	FindMode(b, sizeof(b)/sizeof(int), mode);
	for(int i = 0; i < mode.size(); i++){
		cout << mode[i] << " ";
	}
	cout << endl;
	return 0;
}
