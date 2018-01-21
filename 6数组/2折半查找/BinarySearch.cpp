#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int BinarySearch(const int *array, int size, int key){
	int from = 0;
	int to = size - 1;
	int index;
	bool find = false;
	while(from <= to){
		index = (from + to) / 2;
		if(array[index] == key){
			find = true;
			break;
		}
		if(array[index] > key){
			to = index - 1;
		}else{
			from = index + 1;
		}
	}
	if(find){
		return index;
	}
	return -1;
}

int main(){
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int result = BinarySearch(a, 10, 8);
	if(result != -1){
		cout << result << endl;
	}else{
		cout << "can not find" << endl;
	}
	
	return 0;
}