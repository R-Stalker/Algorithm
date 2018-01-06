/*
有序链表去除重复元素,只保留一个
(该算法删后面)
*/
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
	void RemoveRepeatElement(){
		if(head == NULL){
			return;
		}
		Node<Type> *current_node = head;
		while(current_node->next != NULL){
			if(current_node->data == current_node->next->data){
				Node<Type> *delete_node = current_node->next;
				current_node->next = delete_node->next;
				delete delete_node;
			}else{
			    current_node = current_node->next;
			}
		}
	}
	void output(){
		Node<Type> *current_node = head;
		while(current_node != NULL){
			cout << current_node->data << " ";
			current_node = current_node->next;
		}
		cout << endl;
	}
};

int main(){
	LinkedList<int> linkedlist;
	cout << "输入该有序链表的元素个数：";
	int m;
	cin >> m;
	cout << "输入该有序链表,每个元素用空格隔开：";
	for(int i = 0; i < m; i++){
		int n;
		cin >> n;
		Node<int> *node = new Node<int>(n);
		linkedlist.insert(node, i);
	}
	linkedlist.output();
	linkedlist.RemoveRepeatElement();
	linkedlist.output();
    return 0;
}








