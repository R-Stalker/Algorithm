
#include <iostream>
#include <cmath>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::sort;
using std::min;

struct Node{
    int value;
    int index;
};

//需要考虑返回子数组,我的第一反应是建一个结构体数组
void MinSubArray(const int *a, int size){
	Node sum[size+1];
	sum[0].index = -1;//初始化
	sum[0].value = 0;
	int i;
	for(i = 0; i < size; i++){ //sum[i]:a[0...i-1]的和
        sum[i+1].value = sum[i].value + a[i];
        sum[i+1].index = i;
	}

    cout << "排序前:" << endl;
	for(int i = 0; i <= size; i++){
        cout << sum[i].index << "->" << sum[i].value << " ";
	}
	cout << endl;
	//冒泡排序
	for(int m = 0; m < size; m++){
		for(int n = 1; n <= size - m; n++){
			if(sum[n-1].value > sum[n].value){
				swap(sum[n-1], sum[n]);
			}
		}
	}

	cout << "排序后:" << endl;
	for(int i = 0; i <= size; i++){
        cout <<sum[i].index << "->" << sum[i].value << " ";
	}
	cout << endl;

	int difference = abs(sum[1].value - sum[0].value);
	int result = difference;
	int from = 0;
	int to = -1;
	for(i = 1; i < size; i++){
		difference = abs(sum[i+1].value - sum[i].value);
		if(result > difference){
			result = difference;
			from = sum[i].index + 1;
			to = sum[i+1].index;
		}
	}
	cout << "最小值为："<< result << endl;
	cout << "子数组下标为" << from << "--->" << to << endl;
	cout << "取得最小值的子数组为：";
	for(int i = from; i <= to; i++){
        cout << a[i] << " ";
	}
	cout << endl;
}

int main(){
	int a[] = {1,-2,3,10,-4,7,2,-5};
	//求得子数组
	MinSubArray(a, sizeof(a)/sizeof(int));
	return 0;
}
