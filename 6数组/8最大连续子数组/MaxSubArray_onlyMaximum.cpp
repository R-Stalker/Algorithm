#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::max;

int MaxSubarray(const int *a, int size){
	if(!a || (size <= 0)){
		return 0;
	}
	int sum = a[0]; //当前子串的和
	int result = sum; //当前找到的最优解
	for(int i = 1; i < size; i++){
		if(sum > 0){
			sum += a[i];
		}else{
			sum = a[i];
		}
		result = max(sum, result);
	}
	return result;
}

int main(){
	int a[] = {1,-2,3,10,-4,7,2,-5};
	int m = MaxSubarray(a, sizeof(a)/sizeof(int));
	cout << m << endl;
	return 0;
}
