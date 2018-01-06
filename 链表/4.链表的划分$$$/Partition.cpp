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
			current_node -> next = node;
			return true;
		}
		return false;
	}
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
		if(current_node->next != NULL && count == index - 1){
			Node<Type> *delete_node = current_node->next;
			current_node->next = delete_node->next;
			delete delete_node;
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
	void Partition(Type key){
		if(head == NULL){
			return;
		}
		//两个链表的头指针
		Node<Type> *p1_head = new Node<Type>(-1);
		Node<Type> *p2_head = new Node<Type>(-2);

		Node<Type> *current_node = head;

		//两个链表的尾指针
		Node<Type> *p1 = p1_head;
		Node<Type> *p2 = p2_head;
		while(current_node != NULL){
			if(current_node->data < key){
				p1->next = current_node;
				p1 = current_node;
			}else{
				p2->next = current_node;
				p2 = current_node;
			}
			current_node = current_node->next;
		}
		p1->next = p2_head->next;
		p2->next = NULL;
		head = p1_head->next;
		delete p1_head;
		delete p2_head;
	}
};

int main(){
	LinkedList<int> linkedlist;
	int m;
	cout << "请输入链表长度：";
	cin >> m;
	cout << "请输入链表元素，每个元素用空格隔开:";
	for(int i = 0; i < m; i++){
		int num;
		cin >> num;
		Node<int> *new_node = new Node<int>(num);
		linkedlist.insert(new_node, i);
	}
	linkedlist.output();
	int key_n;
	cout << "请输入划分元素的大小:";
	cin >> key_n;
	linkedlist.Partition(key_n);
	linkedlist.output();
	return 0;
}






