//非递归

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

void Reverse(int *from, int *to){
	int t;
	while(from < to){
		t = *from;
		*from = *to;
		*to = t;
		from++;
		to--;
	}
}

bool GetNextPermutation(int *a, int size){
	//后找
	int i = size - 2;
	while((i >= 0) &&(a[i] >= a[i+1])){
		i--;
	}
	if(i < 0){
		return false;
	}

	//小大
	int j = size - 1;
	while(a[j] <= a[i]){
		j--;
	}

	//交换
	swap(a[j], a[i]);

	//翻转
	Reverse(a+i+1, a+size-1);
	return true;
}

int main(){
	int a[] = {1,2,2,4};
	int size = sizeof(a)/sizeof(int);
	Print(a, size);
	while(GetNextPermutation(a, size)){
		Print(a, size);
	}
	return 0;
}
