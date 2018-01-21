#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::min;


//不考虑返回子数组
int MinSubArray_result(const int *a, int size){
	int *sum = new int[size+1];//sum[i]:a[0...i-1]的和
	sum[0] = 0;
	for(int i = 0; i < size; i++){
		sum[i + 1] = sum[i] + a[i];
	}
	sort(sum, sum+size+1);
	int difference = abs(sum[1] - sum[0]);
	int result = difference;
	for(int i = 1; i < size; i++){
		difference = abs(sum[i+1] - sum[i]);
		result = min(difference, result);
	}
	delete[] sum;
	return result;
}

int main(){
	int a[] = {1,-2,3,10,-4,7,2,-5};
	//只求最小值
	int result = MinSubArray_result(a, sizeof(a)/sizeof(int));
	cout << "最小值为："<< result << endl;
	return 0;
}
