#include <iostream>
#include <stdlib.h>
#include <limits.h>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;



template <typename Type> class Node{
public:
	Type data;
	Node *lchild, *rchild, *father;
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

	//中序
	void InOrder(){
		if(lchild != NULL){
			lchild->InOrder();
		}
		cout <<	data << " ";
		if(rchild != NULL){
			rchild->InOrder();
		}
	}
	//前序
	void PreOrder(){
		cout <<	data << " ";
		if(lchild != NULL){
			lchild->PreOrder();
		}
		if(rchild != NULL){
			rchild->PreOrder();
		}
	}
	void ChangeValue(){
        data = rand() % 100;
	}

    bool LargestBSTSub(Node<Type>* &p_root, int &n_min, int &n_max, int &n_count, int &n_number, Node<Type>* &p_node){
        n_count = 0;
        if(!p_root){
            return true;
        }
        int n_min1 = INT_MAX, n_min2 = INT_MAX;
        int n_max1 = INT_MIN, n_max2 = INT_MIN;
        int c1, c2;
        if(!LargestBSTSub(p_root->lchild, n_min1, n_max1, c1, n_number, p_node)){
            return false;
        }
        if(!LargestBSTSub(p_root->rchild, n_min2, n_max2, c2, n_number, p_node)){
            return false;
        }
        if((p_root->data < n_max1) || (p_root->data > n_min2)){
            return false;
        }
        n_count = c1 + c2 + 1;
        n_min = min(n_min1, p_root->data);
        n_max = max(n_max2, p_root->data);
        if(n_count > n_number){
            n_number = n_count;
            p_node = p_root;
        }
        return true;
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
	void ChangeValue(){
		root->ChangeValue();
	}
	void InOrder(){
		root->InOrder();
	}
	void PreOrder(){
		root->PreOrder();
	}
	bool LargestBSTSub(Node<Type>* &p_root, int &n_min, int &n_max, int &n_count, int &n_number, Node<Type>* &p_node){
        if(root == NULL){
            return true;
        }
        else{
            root->LargestBSTSub(p_root, n_min, n_max, n_count, n_number, p_node);
        }
        return false;
	}
	Node<Type>* GetRoot(){
        return root;
	}
};


int main(){
	BinaryTree<int> binarytree;
	for(int i = 0; i < 10; i++){
		binarytree.insert( rand() % 100 );
	}
	binarytree.ChangeValue();
	binarytree.InOrder();
	cout << endl;
	binarytree.PreOrder();
    cout << endl;

    int n_min, n_max, n_count;
    int n_number = 0;
    Node<int> *p_node;
    Node<int> *p_root = binarytree.GetRoot();
    binarytree.LargestBSTSub(p_root, n_min, n_max, n_count, n_number, p_node);
	cout << p_node->data << '\t' << n_number << endl;
	return 0;
}
