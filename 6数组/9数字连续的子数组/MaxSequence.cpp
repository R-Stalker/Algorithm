/*这里的空间复杂度为O(1)*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int MaxSequence(const int *a, int size){
	int m = 1;
	int p = 1;
	for(int i = 1; i < size; i++){
		if(a[i] - a[i-1] == 1){
			p++;
			if(m < p){
				m = p;
			}
		}else{
            p = 1;
		}
	}
	return m;
}

//返回子数组
int MaxSequenceSubArray(const int *a, int size, int &from, int &to){
    if(!a || (size <= 0)){
        from = to = -1;
        return 0;
    }
    from = to = 0;
    int p = 1;
    int m = 1;
    for(int i = 1; i < size; i++){
		if(a[i] - a[i-1] == 1){
			p++;
			if(m < p){
				m = p;
				to = i;
			}
		}else{
            p = 1;
		}
	}
	from = to - m + 1;
	return m;
}

int main(){
	int a[] = {1,2,3,34,56,57,58,59,60,61,99,121};

	int result1 = MaxSequence(a, sizeof(a)/sizeof(int));
	cout << result1 << endl;

	//返回子数组
	int from, to;
	int result2 = MaxSequenceSubArray(a, sizeof(a)/sizeof(int), from, to);
	cout << result2 << endl;
	cout << "子数组下标：" << from << "->" << to << endl;
	return 0;
}
