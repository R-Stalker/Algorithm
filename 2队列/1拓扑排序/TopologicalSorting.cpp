#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template <typename Type> class Queue{
private:
	Type *data;
	int length, head, tail;
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

void TopologicalSorting(const int &n, int **graph){

	//用indegree[n]存储每个节点的入度
	int *indgree = new int[n];
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < n; j++){
			sum += graph[j][i];
		}
		indgree[i] = sum;
	}
	Queue<int> queue(n);//保存入度为0的节点：还可以用栈，也可以随机取
	for(int i = 0; i < n; i++){
		if(indgree[i] == 0){
			queue.push(i);
		}
	}
	int cnt = 0; //当前拓扑排序列表中有多少节点
	int *toposort = new int[n];
	int cur; //当前入度为0的节点
	while(!queue.empty()){
		cur = queue.front();
		queue.pop();
		toposort[cnt] = cur;
		cnt++;
		for(int i = 0; i < n; i++){
			if(graph[cur][i] != 0){
				indgree[i]--;
				if(indgree[i] == 0){
					queue.push(i);
				}
			}
		}
	}
	cout << "======================" << endl;
	cout << "一种可能的拓扑排序结果为：";
	for(int i = 0; i < n; i++){
		cout << toposort[i] << " ";
	}
	cout << endl;
}

int main(){
	cout << "请输入该有向无环图共有多少节点：";
	int n;
	cin >> n;
	int **graph = new int*[n];
	for(int i = 0; i < n; i++){
		graph[i] = new int[n];
	}
	cout << "输入该有向无环图的邻接矩阵n*n：";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> graph[i][j];
		}
	}
	TopologicalSorting(n, graph);
	return 0;
}
