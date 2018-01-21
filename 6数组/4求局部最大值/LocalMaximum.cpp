#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int LocalMaximum(const int *a, int size){
	int left = 0;
	int right = size - 1;
	int mid;
	while(left < right){
		mid = (left + right) / 2;
		if(a[mid] > a[mid+1]){//mid一定小于size-1
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	return a[left];
}

int main(){
	int a[] = {1,2,7,0,3,6,5,4};
	cout << LocalMaximum(a, sizeof(a)/sizeof(int)) << endl;
	return 0;
}
