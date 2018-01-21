#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::swap;

int FirstMissNumber(int *a, int size){
	a--; //从1开始数
	int i = 1;
	while (i <= size){
		if(a[i] == i){
			i++;
		}else if( (a[i] < i) || (a[i] > size) || (a[i] == a[a[i]]) ){
			a[i] = a[size];
			size--;
		}else{ //if(a[i] > i)
			swap(a[a[i]], a[i]);
		}
	}
	return i;
}

int main(){
	int a[] = {3,5,1,2,-3,7,4,8};
	int m = FirstMissNumber(a, sizeof(a)/sizeof(int));
	cout << m << endl;
	return 0;
}
