#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void Unit(vector<string> &result, const vector<string> &prefix, const vector<string> &suffix){
	vector<string>::const_iterator ip, is;
	for(ip = prefix.begin(); ip != prefix.end(); ip++){
		for(is = suffix.begin(); is != suffix.end(); is++){
			result.push_back("");
			string &r = result.back();
			r += "(";
			r += *ip;
			r += ")";
			r += *is;
		}
	}
}

vector<string> AllParentheses(int n){
	if(n == 0){
		return vector<string>(1, "");
	}
	if(n == 1){
		return vector<string>(1, "()");
	}
	vector<string> prefix, suffix, result;
	for(int i = 0; i < n; i++){
		prefix = AllParentheses(i);
		suffix = AllParentheses(n-i-1);
		Unit(result, prefix, suffix);
	}
	return result;
}

//Catalan数
void GetCatalan(int *p_catalan, int N){
    p_catalan[0] = 1;
    p_catalan[1] = 1;
    int i, j;
    int c;
    for(i = 2; i <= N; i++){
        p_catalan[i] = 1;
        c = 0;
        for(j = 0; j < i; j++){
            c += p_catalan[j] * p_catalan[i-j-1];
        }
        p_catalan[i] = c;
    }
}

int main(){
	int n;
	cout << "请输入有几对括号:";
	cin >> n;
	int *catalan = new int[n+1];
	GetCatalan(catalan, n);
	cout << "共有" << catalan[n] << "种配对方式:" << endl;
	vector<string> result = AllParentheses(n);
	for(int i = 0; i < (int)result.size(); i++){
		cout << i+1 << ":" << result[i] << endl;
	}
	return 0;
}
