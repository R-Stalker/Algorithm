#include <iostream>
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
	void output(){
		Node<Type> *current_node = head;
		while(current_node != NULL){
			cout << current_node->data << " ";
			current_node = current_node->next;
		}
		cout << endl;
	}
	void reverse(){
		if(head == NULL){
			return ;
		}
		Node<Type> *current_node, *next_node;
		current_node = head->next;
		head->next = NULL;
		while(current_node != NULL){
			next_node = current_node->next;
			current_node->next = head;
			head = current_node;
			current_node = next_node;
		}
	}
};

int main(){
    return 0;
}








