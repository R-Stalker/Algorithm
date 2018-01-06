#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;
const int N = 16;

template <typename Type> class Queue{
private:
	Type *data;
	int head, tail, length;
public:
	Queue(int input_length){
		data = new Type[input_length];
		length = input_length;
		head = 0;
		tail = -1;
	}
	~Queue(){
		delete[] data;
	}
	bool push(Type element){
		if(tail + 1 >= length){
			return false;
		}
		tail++;
		data[tail] = element;
		return true;
	}
	void pop(){
		head++;
	}
	void output(){
		int count = 0;
		for(int i = head; i <= tail; i++){
			if(count > 0){
				cout << " ";
			}
			cout << data[i];
			count++;
		}
		cout << endl;
	}
	Type front(){
		return data[head];
	}
	bool empty(){
		return head > tail;
	}
};


int FindShortestPathNumber(int G[N][N]){
	int step[N]; //每个结点第几步可以到达
	int stepNumber[N]; //到每个结点有几条路径
	memset(step, 0, sizeof(int)*N);
	memset(stepNumber, 0, sizeof(int)*N);
	stepNumber[0] = 1;
	Queue<int> q(N); //当前搜索结点
	q.push(0);
	int from, s;
	while(!q.empty()){
		from = q.front();
		q.pop();
		s = step[from] + 1;
		for(int i = 1; i < N; i++){//0是起点不遍历
			//连通
			if(G[from][i] == 1){
				//i尚未可达或发现更快的路（后者权值不同才可能）
				if(step[i] == 0 || step[i] > s){
					step[i] = s;
					stepNumber[i] = stepNumber[from];
					q.push(i);
				}
				//发现相同长度的路径
				else if(step[i] == s){
					stepNumber[i] += stepNumber[from];
				}
			}
		}
	}
	return stepNumber[N-1];
}

int main(){
	//无向连通图的邻接矩阵定义如下
	int G[N][N];
	memset(G, 0, sizeof(int)*N*N);
	G[0][1] = G[0][4] = 1;
	G[1][5] = G[1][0] = G[1][2] = 1;
	G[2][1] = G[2][6] = G[2][3] = 1;
	G[3][2] = G[3][7] = 1;
	G[4][0] = G[4][5] = 1;
	G[5][1] = G[5][4] = G[5][6] = G[5][9] = 1;
	G[6][2] = G[6][5] = G[6][7] = G[6][10] = 1;
	G[7][3] = G[7][6] = 1;
	G[8][9] = G[8][12] = 1;
	G[9][8] = G[9][13] = G[9][10] = 1;
	G[10][9] = G[10][14] = G[10][11] = 1;
	G[11][10] = G[11][15] = 1;
	G[12][8] = G[12][13] = 1;
	G[13][9] = G[13][12] = G[13][14] = 1;
	G[14][10] = G[14][13] = G[14][15] = 1;
	G[15][11] = G[15][14] = 1;


	cout << "最短路径一共有：" << FindShortestPathNumber(G) << " 条" << endl;
	return 0;
}
