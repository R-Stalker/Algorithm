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
	//遍历
	void output(){
		Node<Type> *current_node = head;
		while(current_node != NULL){
			cout << current_node->data << " ";
			current_node = current_node->next;
		}
		cout << endl;
	}
	//插入
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
	Node<Type>* GetHead(){
		return head;
	}
};

//两个链表相加
	LinkedList<int>* LinkedListAdd(LinkedList<int> &l1, LinkedList<int> &l2){
		Node<int> *p1 = l1.GetHead();
		Node<int> *p2 = l2.GetHead();
		LinkedList<int> *sum = new LinkedList<int>();
		int data;
		int carry = 0;//进位
		int index = 0;
		while(p1 != NULL && p2 != NULL){
			data = p1->data + p2->data + carry;
			carry = data / 10;
			data = data % 10;
			Node<int> *new_node = new Node<int>(data);
			sum->insert(new_node, index);
			index++;
			p1 = p1->next;
			p2 = p2->next;
		}
		//处理较长的链
		if(p1 != NULL){
			while(p1 != NULL){
                data = p1->data + carry;
                carry = data / 10;
                data = data % 10;
                Node<int> *new_node = new Node<int>(data);
                sum->insert(new_node, index);
                index++;
                p1 = p1->next;
			}
		}else{
			while(p2 != NULL){
                data = p2->data + carry;
                carry = data / 10;
                data = data % 10;
                Node<int> *new_node = new Node<int>(data);
                sum->insert(new_node, index);
                index++;
                p2 = p2->next;
			}
		}
		//处理可能的进位
		if(carry != 0){
			Node<int> *new_node = new Node<int>(carry);
			sum->insert(new_node, index);
			index++;
		}
		return sum;
	}

int main(){
	LinkedList<int> L1, L2;
	int m, n, num;
	cout << "请输入第一个整数的位数：";
	cin >> m;
	cout << "接下来请输入整数的每一位数字，并用空格隔开：";
	for(int i = 0; i < m; i++){
		cin >> num;
		Node<int> *new_node = new Node<int>(num);
		L1.insert(new_node, 0);
	}

	cout << "请输入第二个整数的位数：";
	cin >> n;
	cout << "接下来请输入整数的每一位数字，并用空格隔开：";
	for(int i = 0; i < n; i++){
		cin >> num;
		Node<int> *new_node = new Node<int>(num);
		L2.insert(new_node, 0);
	}
    L1.output();
    L2.output();
	LinkedList<int> *sum = LinkedListAdd(L1, L2);
	sum->output();
    return 0;
}
