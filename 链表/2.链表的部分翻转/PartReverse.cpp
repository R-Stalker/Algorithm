#include <iostream>
using std::cin;
using std::cout;
using std::endl;

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
	//插入
	bool insert(Node<Type> *node, int index){
		if(head == NULL){
			if(index != 0){
				return false;
			}
			head = node;
			return false;
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
	//删除
	bool delete_node(int index){
		if(head == NULL){
			return false;
		}
		Node<Type> *current_node = head;
		if(index == 0){
			head = head->next;
			delete current_node;
			return true;
		}
		int count = 0;
		while(current_node->next != NULL && count < index - 1){
			current_node = current_node->next;
			count++;
		}
		if(count == index - 1 && current_node->next != NULL){
			Node<Type> *delete_node = current_node->next;
			current_node->next = delete_node->next;
			delete delete_node;
			return true;
		}
		return false;
	}
	//遍历输出
	void output(){
		Node<Type> *current_node = head;
		while(current_node != NULL){
			cout << current_node->data << " ";
			current_node = current_node->next;
		}
		cout << endl;
	}
	//部分翻转
	bool PartReverse(int from, int to){
		if(head == NULL){
			return false;
		}
		Node<Type> *phead = new Node<Type>(-1);
		phead->next = head;
		Node<Type> *current_node = phead;
		int count = -1;
		while(current_node->next != NULL && count < from - 1){
			current_node = current_node->next;
			count++;
		}
		if(count == from - 1){
			Node<Type> *pre_node = current_node;
			current_node = current_node->next;
			for(int i = 0; i < to - from + 1; i++){
				Node<Type> *next_node = current_node->next;
				current_node->next = pre_node->next;
				pre_node->next = current_node;
				current_node = next_node;
			}
			//将翻转的部分的尾部和后面的链表连接
			while(pre_node->next != pre_node){
				pre_node = pre_node->next;
			}
			pre_node->next = current_node;
			head = phead->next;
			return true;
		}
		return false;
	}
};

int main(){
	LinkedList<int> linkedlist;
	cout << "请输入链表的长度:";
	int m;
	cin >> m;
	cout << "请输入" << m << "个数字，之间用空格隔开：";
	for(int i = 0; i < m; i++){
		int num;
		cin >> num;
		Node<int> *node = new Node<int>(num);
		linkedlist.insert(node, i);
	}
	linkedlist.output();
	int start, end;
	cout << "请输入希望翻转部分的起始下标和终止下表，用空格隔开：";
	cin >> start >> end;
	linkedlist.PartReverse(start, end);
	linkedlist.output();
	return 0;
}








