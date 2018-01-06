/*
有序链表去除所有重复元素
(该算法删前面)
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
	void RemoveAllRepeatElement(){
		if(head == NULL){
            return;
		}
		//为了开头就重复的情况，定义一个新节点指向链表
		Node<Type> *phead = new Node<Type>(-1);
		phead->next = head;

		Node<Type> *pre_node = phead;
		Node<Type> *current_node = pre_node->next;
		bool bDup;
		Node<Type> *next_node;
		while(current_node != NULL){
            bDup = false;
            next_node = current_node->next;
            while(next_node != NULL && (current_node->data == current_node->next->data)){
                pre_node->next = next_node;
                delete current_node;
                current_node = next_node;
                next_node = current_node->next;
                bDup = true;
            }
            if(bDup){
                pre_node->next = next_node;
                delete current_node;
            }else{
                pre_node = current_node;
            }
            current_node = next_node;
		}
		//把真实的链表头部赋值给head
		head = phead->next;
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
	linkedlist.RemoveAllRepeatElement();
	linkedlist.output();
    return 0;
}








