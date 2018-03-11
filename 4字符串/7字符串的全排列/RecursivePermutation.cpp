//时间复杂度O(n!)

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

void Permutation(int *a, int size, int n){
	if(n == size - 1){
		Print(a, size);
		return;
	}
	for(int i = n; i < size; i++){
		swap(a[i], a[n]);
		Permutation(a, size, n+1);
		swap(a[i], a[n]);
	}
}

int main(){
	int a[] = {1,2,3,4};
	Permutation(a, sizeof(a)/sizeof(int), 0);
	return 0;
}
