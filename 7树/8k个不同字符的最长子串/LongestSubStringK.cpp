#include <iostream>
#include <map>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::max;

int LongestSubStringK(const char *str, int size, int k){
	if(size <= 0){
		return 0;
	}
	map<char, int> wd;
	int left = 0;
	int mx = 0;
	for(int right = 0; right < size; right++){
		wd[str[right]]++;
		//cout << str[right] << endl;
		while((int)wd.size() > k){
            //cout << str[left] << endl;
			wd[str[left]]--;
			if(wd[str[left]] == 0){
				wd.erase(str[left]);
			}
			left++;
		}
		mx = max(right - left + 1, mx);
	}
	return mx;
}

int LongestSubStringK2(const char *str, int size, int k, int &from, int &to){
    if(size <= 0){
        return 0;
    }
    map<char, int> wd;
    int left = 0;
    int mx = 0;
    for(int right = 0; right < size; right++){
        wd[str[right]]++;
        while( (int)wd.size() > k ){
            wd[str[left]]--;
            if(wd[str[left]] == 0){
                wd.erase(str[left]);
            }
            left++;
        }
        if(mx < right - left + 1){
            mx = right - left + 1;
            from = left;
            to = right;
        }
    }
    return mx;
}

int main(){
	char s[] = "abcceceba";
	cout << LongestSubStringK(s, sizeof(s)/sizeof(char), 3) << endl;
	int from, to;
	LongestSubStringK2(s, sizeof(s)/sizeof(char), 3, from, to);
	for(int i = from; i <= to; i++){
        cout << s[i] << " ";
	}
	return 0;
}
