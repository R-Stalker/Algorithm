#include <iostream>
using std::endl;
using std::cout;

class Node{
public:
	int data;
	Node *next;
	Node(int input_data){
		data = input_data;
		next = NULL;
	}
};

Node* Merge(Node *p1, Node *p2){
	if(p1 == NULL){
		return p2;
	}
	if(p2 == NULL){
		return p1;
	}
	Node *head = NULL;
	if(p1->data < p2->data){
        head = p1;
        head->next = Merge(p1->next, p2);
	}else{
        head = p2;
        head->next = Merge(p1, p2->next);
	}
	return head;
}

void Print(Node *head){
	Node *cur = head;
	while(cur){
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main(){
	int a[] = {1, 4, 5, 7, 9};
	int b[] = {2, 3, 6, 8, 10};
	Node *p1 = new Node(a[0]);
	Node *p2 = new Node(b[0]);
	Node *p1_cur = p1;
	Node *p2_cur = p2;
	for(int i = 1; i < (int)(sizeof(a)/sizeof(int)); i++){
		Node *new_node = new Node(a[i]);
		p1_cur->next = new_node;
		p1_cur = p1_cur->next;
	}
	for(int i = 1; i < (int)(sizeof(b)/sizeof(int)); i++){
		Node *new_node = new Node(b[i]);
		p2_cur->next = new_node;
		p2_cur = p2_cur->next;
	}
	Print(p1);
	Print(p2);

	Print(Merge(p1, p2));
	return 0;
}
