#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//记录起点和终点
int MaxSubArray(const int *a, int size, int &from, int &to){
	if(!a || (size <= 0)){
		from = to = -1;
		return 0;
	}
	from = to = 0;
	int sum = a[0];
	int result = sum;
	int from_new; //新的子数组起点
	for(int i = 1; i < size; i++){
		if(sum > 0){
			sum += a[i];
		}else{
			sum = a[i];
			from_new = i;
		}
		if(result < sum){
			result = sum;
			from = from_new;
			to = i;
		}
	}
	return result;
}


int main(){
	int a[] = {1,-2,3,10,-4,7,2,-5};
	//求得子数组
	int from, to;
	int result = MaxSubArray(a, sizeof(a)/sizeof(int), from, to);
	cout << "最大值为："<< result << endl;
	cout << "子数组下标为" << from << "-->" << to << endl;
	cout << "取得最小值的子数组为：";
	for(int i = from; i <= to; i++){
        cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
