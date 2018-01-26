#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::reverse;

struct HuffmanNode{
	int nWeight;
	int nParent;
	int nLeft;
	int nRight;
};


void CalcFrequency(const char *str, int *pWeight){
	while(*str){
		pWeight[*str]++;
		str++;
	}
}

void CalcExistChar(int *pWeight, int N, vector<int> &pChar){
	int j = 0;
	for(int i = 0; i < N; i++){
		if(pWeight[i] != 0){
			pChar.push_back(i);
			if(j != i){
				pWeight[j] = pWeight[i];
			}
			j++;
		}
	}
}

void SelectNode(const HuffmanNode *pHuffmanTree, int n, int &s1, int &s2){
	s1 = -1;//无效值
	s2 = -1;
	int nMin1 = -1; //无效值
	int nMin2 = -1;
	for(int i = 0; i < n; i++){
		if( (pHuffmanTree[i].nParent == 0) && (pHuffmanTree[i].nWeight > 0) ){
			if( (s1 < 0) || (nMin1 > pHuffmanTree[i].nWeight) ){
				s2 = s1;
				nMin2 = nMin1;
				s1 = i;
				nMin1 = pHuffmanTree[s1].nWeight;
			}else if ( (s2 < 0) || (nMin2 > pHuffmanTree[i].nWeight) ){
				s2 = i;
				nMin2 = pHuffmanTree[s2].nWeight;
			}
		}
	}
}



void HuffmanCoding(int *pWeight, int N, vector<vector<char> > &code){
	if (N <= 0){
		return;
	}
	int m = 2 * N - 1;//N个结点的Huffman树需要2N-1个结点
	HuffmanNode *pHuffmanTree= new HuffmanNode[m];
	int s1, s2;

	int i;
	//建立叶子结点
	for(i = 0; i < N; i++){
		pHuffmanTree[i].nWeight = pWeight[i];
	}
	//每次选择权值最小的两个结点，建树
	for(i = N; i < m; i++){
		SelectNode(pHuffmanTree, i, s1, s2);
		pHuffmanTree[s1].nParent = pHuffmanTree[s2].nParent = i;
		pHuffmanTree[i].nLeft = s1;
		pHuffmanTree[i].nRight = s2;
		pHuffmanTree[i].nWeight = pHuffmanTree[s1].nWeight + pHuffmanTree[s2].nWeight;
	}

	//根据建好的Huffman树从叶子到根计算每个叶结点的编码
	int node, nParent;
	for(i = 0; i < N; i++){
		vector<char> &cur = code[i];
		node = i;
		nParent = pHuffmanTree[node].nParent;
		while(nParent != 0){
			if(pHuffmanTree[nParent].nLeft == node){
				cur.push_back('0');
			}else{
				cur.push_back('1');
			}
			node = nParent;
			nParent = pHuffmanTree[node].nParent;
		}
		reverse(cur.begin(), cur.end());
	}
}


void PrintCode(char c, vector<char> &code){
	cout << (int)c << "  " << c << ":   ";
	for(vector<char>::iterator it = code.begin(); it != code.end(); it++){
		cout << *it;
	}
	cout << endl;
}

void Print(vector<vector<char> > &code, vector<int> &pChar ){
	int size = (int)code.size();
	for(int i = 0; i < size; i++){
		PrintCode(pChar[i], code[i]);
	}
}

int main(){
	const int N = 256;
	char str[] = "when I was young I'd listen to the radio\
				waiting for my favorite songs\
				when they played I'd sing along,\
				it make me smile.\
				those were such happy times and not so long ago\
				how i wondered where they'd gone.\
				but they're back again just like a long lost friend\
				all the songs I love so well.\
				every shalala every wo'wo\
				still shines.\
				every shine-a-ling-a-ling \
				that they're starting\
				to sing so fine";
	int pWeight[N] = {0};
	CalcFrequency(str, pWeight);
	pWeight['\t'] = 0;
	vector<int> pChar;
	CalcExistChar(pWeight, N, pChar);
	int N2 = (int)pChar.size();
	vector<vector<char> > code(N2);
	HuffmanCoding(pWeight, N2, code);
	Print(code, pChar);
	return 0;
}
