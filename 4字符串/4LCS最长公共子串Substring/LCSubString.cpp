/*LCS最长公共子串*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void LCS(const char *str1, const char *str2, string & str){
    int size1 = (int)strlen(str1);
    int size2 = (int)strlen(str2);
    const char *s1 = str1 - 1;//为了写代码方便，从前一个位置开始
    const char *s2 = str2 - 1;

    vector<vector<int> > chess(size1+1, vector<int>(size2+1));
    //初始化二维数组
    for(int i = 0; i <= size1; i++){
        for(int j = 0; j <= size2; j++){
            chess[i][j] = 0;
        }
    }

    //算法开始
    int max_len = 0;
    int index_i, index_j;
    for(int i = 1; i <= size1; i++){
        for(int j = 1; j <= size2; j++){
            if(s1[i] == s2[j]){
                chess[i][j] = chess[i-1][j-1] + 1;
            }
            if(max_len < chess[i][j]){
                max_len = chess[i][j];
                index_i = i;
                index_j = j;
            }
        }
    }
    cout << "最长公共子串长度为:" << max_len << endl;
    //返回最长公共子串
    int i = index_i;
    int j = index_j;
    while(chess[i][j] != 0){
        str.push_back(s1[i]);
        i--;
        j--;
    }
    reverse(str.begin(), str.end());
}

int main(){
	const char* str1 = "ABCBADAB";
	const char* str2 = "BDCBADBA";
	string str;
	LCS(str1, str2, str);
	cout << str.c_str() << endl;    //LCS可能不唯一
	/*
	c_str是Borland封装的String类中的一个函数，它返回当前字符串的首字符地址。
	c_str函数的返回值是constchar*的，不能直接赋值给char*
	*/
	//cout << str << endl;
	return 0;
}
