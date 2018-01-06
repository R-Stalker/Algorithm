#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::swap;

template <typename Type> class Node{
public:
	Type data;
	Node<Type> *next;
	Node(Type _data){
		data = _data;
		next = NULL;
	}
};

template <typename Type> class LinkedList{
private:
	Node<Type> *head;
public:
	LinkedList(){
		head = NULL;
	}
	~LinkedList(){
		Node<Type> *current_node = head;
		while(current_node != NULL){
			Node<Type> *delete_node = current_node;
			current_node = current_node->next;
			delete delete_node;
		}
	}
	bool insert(Node<Type> *node, int index){
		if(head == NULL){
			if(index != 0){
				return false;
			}
			head = node;
			return true;
		}
		if(index == 0){
			node->next = head;
			head = node;
			return true;
		}
		Node<Type> *current_node = head;
		int count = 0;
		while(current_node->next != NULL && count < index - 1){
			current_node = current_node->next;
			count++;
		}
		if(count == index - 1){
			node->next = current_node->next;
			current_node->next = node;
			return true;
		}
		return false;
	}
	void output(){
		Node<Type> *current_node = head;
		while(current_node != NULL){
			cout << current_node->data << " ";
			current_node = current_node->next;
		}
		cout << endl;
	}

	Node<Type>* Gethead(){
		return head;
	}
	int GetLength(){
		int len = 0;
		Node<Type> *current_node = head;
		while(current_node != NULL){
			current_node = current_node->next;
			len++;
		}
		return len;
	}
};

Node<int>* FindFirstCommonNode(LinkedList<int> &A, LinkedList<int> &B){
		Node<int> *pA = A.Gethead();
		Node<int> *pB = B.Gethead();
		int len_A = A.GetLength();
		int len_B = B.GetLength();
		if(len_A > len_B){
			swap(pA, pB);
			swap(len_A, len_B);
		}
		//空转len_B-len_A次
		for(int i = 0; i < len_B - len_A; i++){
			pB = pB->next;
		}
		//齐头并进
		while(pA != NULL){
			if(pA == pB){
				return pA;
			}
			pA = pA->next;
			pB = pB->next;
		}
		return NULL;
}

int main(){
	LinkedList<int> A, B;
	int m;
	cin >> m;
	//模拟两个有交点的链表
	for(int i = 0; i < m; i++){
		int n;
		cin >> n;
		Node<int> *node = new Node<int>(n);
		A.insert(node, i);
	}
	cout << "第一个链表：";
	A.output();
	Node<int> *pA = A.Gethead();
	pA = pA->next;
	B.insert(pA->next, 0);
	cout << "第二个链表：";
	B.output();


	Node<int> *result = FindFirstCommonNode(A, B);
	if(result != NULL){
		cout << "第一个公共节点的值为:   " << result->data << endl;
	}else{
		cout << "无公共节点。" << endl;
	}
	return 0;
}
