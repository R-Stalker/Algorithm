#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool CanPostOrder(const int *a, int size){
	if(size <= 1){
		return true;
	}
	int root = a[size-1];
	int n_left = 0;
	while(n_left < size-1){
		if(a[n_left] > root){
			break;
		}
		n_left++;
	}
	int n_right = size-2; //size-1是根
	while(n_right >= 0){
		if(a[n_right] < root){
			break;
		}
		n_right--;
	}
	if(n_right != n_left-1){//无法根据root分成两部分
		return false;
	}
	return CanPostOrder(a, n_left) //左子树
			&& CanPostOrder(a+n_left, size-n_left-1); //右子树
}

int main(){
	int a[] = {5,4,3,2,1};
	bool b = CanPostOrder(a, sizeof(a)/sizeof(int));
	cout << b << endl;
	return 0;
}
