#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::swap;

void Holland(int *a, int length){
	int begin = 0;
	int current = 0;
	int end = length - 1;
	while(current <= end){
		if(a[current] == 2){
			swap(a[current],a[end]);
			end--;
		}else if(a[current] == 1){
			current++;
		}else{ //if(a[current] == 0)
			//1.或者用更直接的判断if(a[current]!=a[begin])
			//2.因为不等的次数远远大于相等的次数，可以直接删去该判断
			if(current != begin){
				swap(a[current],a[begin]);
			}
			begin++;
			current++;
		}
	}
}

int main(){
	int a[] = {1,2,0,0,1,2,2,1,1,0,0,2,1,2,1};
	Holland(a, sizeof(a)/sizeof(int));
	for(int i = 0; i < sizeof(a)/sizeof(int); i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
