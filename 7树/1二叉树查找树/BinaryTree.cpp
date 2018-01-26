#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template <typename Type> class Node{
public:
	Type data;
	Node<Type> *lchild, *rchild, *father;
	Node(Type _data, Node<Type> *_father = NULL){
		data = _data;
		lchild = NULL;
		rchild = NULL;
		father = _father;
	}
	~Node(){
		if(lchild != NULL){
			delete lchild;
		}
		if(rchild != NULL){
			delete rchild;
		}
	}
	//插入
	void insert(Type value){
		if(value == data){
			return;
		}else if(value > data){
			if(rchild == NULL){
				rchild = new Node<Type>(value, this);
			}else{
				rchild->insert(value);
			}
		}else{
			if(lchild == NULL){
				lchild = new Node<Type>(value, this);
			}else{
				lchild->insert(value);
			}
		}
	}
	//查找
	Node<Type>* search(Type value){
		if(data == value){
			return this;
		}else if(value > data){
			if(rchild == NULL){
				return NULL;
			}else{
				return rchild->search(value);
			}
		}else{
			if(lchild == NULL){
				return NULL;
			}else{
				return lchild->search(value);
			}
		}
	}


	//查找前驱结点
	Node<Type>* predecessor(){
		Node<Type> *temp = lchild;
		while(temp != NULL && temp->rchild != NULL){
			temp = temp->rchild;
		}
		return temp;
	}

	//查找后继结点
	Node<Type>* successor(){
		Node<Type> *temp = rchild;
		while(temp != NULL && temp->lchild != NULL){
			temp = temp->lchild;
		}
		return temp;
	}
	//删除结点(有0或1个孩子)
	void remove_node(Node<Type> *delete_node){
		Node<Type> *temp = NULL;
		if(delete_node->lchild != NULL){
			temp = delete_node->lchild;
			temp->father = delete_node->father;
		}
		if(delete_node->rchild != NULL){
			temp = delete_node->rchild;
			temp->father = delete_node->father;
		}
		if(delete_node->father->lchild == delete_node){
			delete_node->father->lchild = temp;
		}else{
			delete_node->father->rchild = temp;
		}
		delete_node->lchild = NULL;
		delete_node->rchild = NULL;
		delete delete_node;
	}
	//完整删除方法
	bool delete_tree(Type value){
		Node<Type> *delete_node, *current_node;
		current_node = search(value);
		if(current_node == NULL){
			return false;
		}
		if(current_node->lchild != NULL){
			delete_node = current_node->predecessor();
		}else if(current_node->rchild != NULL){
			delete_node = current_node->successor();
		}else{
			delete_node = current_node;
		}
		current_node->data = delete_node->data;
		remove_node(delete_node);
		return true;
	}

	//中序遍历
	void output(){
		if(lchild != NULL){
			lchild->output();
		}
		cout << data << " ";
		if(rchild != NULL){
			rchild->output();
		}
	}

};

template <typename Type> class BinaryTree{
private:
	Node<Type> *root;
public:
	BinaryTree(){
		root = NULL;
	}
	~BinaryTree(){
		delete root;
	}
	void insert(Type value){
		if(root == NULL){
			root = new Node<Type>(value);
		}else{
			root->insert(value);
		}
	}
	bool find(Type value){
		if(root == NULL){
			return false;
		}
		if(root->search(value) == NULL){
			return false;
		}else{
			return true;
		}
	}
	//删除方法
	bool delete_tree(Type value){
		if(root == NULL){
			return false;
		}
		return root->delete_tree(value);
	}

	void output(){
		root->output();
	}
};

int main(){
	BinaryTree<int> binarytree;
	int arr[10] = { 8, 9, 10, 3, 2, 1, 6, 4, 7, 5 };
	for(int i = 0; i < 10; i++){
		binarytree.insert(arr[i]);
	}
	binarytree.output();
	cout << endl;
	int value;
	cin >> value;
	if(binarytree.find(value)){
		cout << "search success!" << endl;
	}else{
		cout << "search failed!" << endl;
	}
	cin >> value;
	if(binarytree.delete_tree(value)){
		cout << "delete success!" << endl;
	}else{
		cout << "delete failed!" << endl;
	}
	binarytree.output();
	return 0;
}
