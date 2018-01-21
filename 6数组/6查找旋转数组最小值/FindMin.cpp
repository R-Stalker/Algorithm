#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int FindMin(int *num, int size){
	int low = 0;
	int high = size - 1;
	int mid;
	while(low < high){
		mid = (high + low) / 2;
		if(num[mid] < num[high]){ //最小值在左侧
			high = mid;
		}else if(num[mid] > num[high]){//最小值在右侧
			low = mid + 1;
		}
	}
	return num[low];
}

int main(){
	int a[] = {4,5,6,7,1,2,3};
	int result = FindMin(a, sizeof(a)/sizeof(int));
	cout << result << endl;
	return 0;
}
