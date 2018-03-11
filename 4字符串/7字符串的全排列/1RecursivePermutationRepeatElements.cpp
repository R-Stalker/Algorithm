//时间复杂度f(n)=n^2+n[f(n-1)]≈(n+1)!

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::swap;

void Print(const int* a, int size){
	for(int i = 0; i < size; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}

bool IsDuplicate(const int *a, int n, int t){
	while(n < t){
		if(a[n] == a[t]){
			return false;
		}
		n++;
	}
	return true;
}

void Permutation(int *a, int size, int n){
	if(n == size - 1){
		Print(a, size);
		return;
	}
	for(int i = n; i < size; i++){
		if(!IsDuplicate(a, n, i)){ //a[i]是否与[n,i)重复
			continue;
		}
		swap(a[i], a[n]);
		Permutation(a, size, n+1);
		swap(a[i], a[n]);
	}
}

int main(){
	int a[] = {1,2,2,4};
	Permutation(a, sizeof(a)/sizeof(int), 0);
	return 0;
}
