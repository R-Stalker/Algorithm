/*
汉诺塔
*/

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

void MoveOne(char from, char to){
	cout << from << "->" << to << endl;
}

void Move(char from, char to, char aux, int n){
	if(n == 1){
		MoveOne(from, to);
		return ;
	}
	Move(from, aux, to, n-1);
	MoveOne(from, to);
	Move(aux, to, from, n-1);
}

/*给定从小到大n个盘子散乱位于a,b,c三个柱子上
判断该状态是否是这n个盘子从a借助b移动到c的必经状态
如果是，返回是第几个状态，如果不是，返回-1
*/
int Calc(const char *str, int size, char from, char to, char aux){
	if(size == 0){
		return 0;
	}
	if(str[size-1] == aux){
		return -1;
	}
	if(str[size-1] == to){
		int n = Calc(str, size-1, aux, to, from);
		if(n == -1){
			return -1;
		}
		return (1 << (size -1)) + n;
	}
	return Calc(str, size - 1, from, aux, to); //str[size-1] == from
}


int main(){
	int n = 5;
	Move('a', 'c', 'b', n);

	char str[] = "ABC";
	cout << Calc(str, 3, 'A', 'C', 'B') << endl;
	strcpy(str, "AAC");
	cout << Calc(str, 3, 'A', 'C', 'B') << endl;
	return 0;
}

