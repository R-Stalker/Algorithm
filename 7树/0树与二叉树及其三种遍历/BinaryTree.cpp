#include <iostream>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::pair;
using std::make_pair;

class Node{
public:
	int data;
	Node *lchild, *rchild;
	Node(int input_data){
		data = input_data;
		lchild = NULL;
		rchild = NULL;
	}
	~Node(){
		if(rchild != NULL){
			delete rchild;
		}
		if(lchild != NULL){
			delete lchild;
		}
	}
	//前序遍历(递归)
	void PreOrder(){
		cout << data << " ";
		if(lchild != NULL){
			lchild->PreOrder();
		}
		if(rchild != NULL){
			rchild->PreOrder();
		}
	}

	//中序遍历
	void InOrder(){
		if(lchild != NULL){
			lchild->InOrder();
		}
		cout << data << " ";
		if(rchild != NULL){
			rchild->InOrder();
		}
	}
	//后序遍历
	void PostOrder(){
		if(lchild != NULL){
			lchild->PostOrder();
		}
		if(rchild != NULL){
			rchild->PostOrder();
		}
		cout << data << " ";
	}
};

class BinaryTree{
private:
	Node *root;
public:
	BinaryTree(){
		root = NULL;
	}
	~BinaryTree(){
		delete root;
	}

	void build_demo(){
		root = new Node(4);
		root->lchild = new Node(2);
		root->rchild = new Node(6);
		root->lchild->lchild = new Node(1);
		root->lchild->rchild = new Node(3);
		root->rchild->lchild = new Node(5);
		root->rchild->rchild = new Node(7);
	}

	//前序遍历
	void BTPreOrder(){
		root->PreOrder();
	}
	//中序遍历
	void BTInOrder(){
		root->InOrder();
	}
	//后序遍历
	void BTPostOrder(){
		root->PostOrder();
	}

    //前序遍历(非递归)
	void BTPreOrder1(){
		if(!root){
			return;
		}
		stack<Node*> s;
		s.push(root);
		Node *pCur;
		while(!s.empty()){
			pCur = s.top();
			s.pop();
			cout << pCur->data << " ";
			if(pCur->rchild){
				s.push(pCur->rchild);
			}
			if(pCur->lchild){
				s.push(pCur->lchild);
			}
		}
	}
	//中序遍历(非递归)方法1
	void BTInOrder1(){
        stack<Node*> s;
        Node *pCur = root;
        while(pCur || !s.empty()){
            while(pCur){//找最左孩子
                s.push(pCur);
                pCur = pCur->lchild;
            }
            if(!s.empty()){
                pCur = s.top();//访问左孩子为空的结点
                s.pop();
                cout << pCur->data << " ";
                pCur = pCur->rchild;//转向右孩子
            }
        }
	}
	//中序遍历(非递归)方法2
	void BTInOrder2(){
        if(!root){
            return;
        }
        stack<pair<Node*, int> > s;
        s.push(make_pair(root, 0));
        int times;
        Node *pCur;
        while(!s.empty()){
            pCur = s.top().first;
            times = s.top().second;
            s.pop();
            if(times == 0){//第一次压栈
                if(pCur->rchild){
                    s.push(make_pair(pCur->rchild, 0));
                }
                s.push(make_pair(pCur, 1));//第二次压栈
                if(pCur->lchild){
                    s.push(make_pair(pCur->lchild, 0));
                }
            }else{
                cout << pCur->data << " ";
            }
        }
	}
    //后序遍历(非递归)
	void BTPostOrder1(){
        if(!root){
            return;
        }
        stack<pair<Node*, int> > s;
        s.push(make_pair(root, 0));
        int times;
        Node *pCur;
        while(!s.empty()){
            pCur = s.top().first;
            times = s.top().second;
            s.pop();
            if(times == 0){//第一次压栈
                s.push(make_pair(pCur, 1));//第二次压栈
                if(pCur->rchild){
                    s.push(make_pair(pCur->rchild, 0));
                }
                if(pCur->lchild){
                    s.push(make_pair(pCur->lchild, 0));
                }
            }else{
                cout << pCur->data << " ";
            }
        }
	}

};


int main(){
	BinaryTree binarytree;
	binarytree.build_demo();
	cout << "先序遍历递归方法：";
	binarytree.BTPreOrder();
	cout << endl;
	cout << "先序遍历非递归方法：";
	binarytree.BTPreOrder1();
	cout << endl;
	cout << "-------------------------------" << endl;
	cout << "中序遍历递归方法：";
	binarytree.BTInOrder();
	cout << endl;
	cout << "中序遍历非递归方法1：";
	binarytree.BTInOrder1();
	cout << endl;
	cout << "中序遍历非递归方法2：";
	binarytree.BTInOrder2();
	cout << endl;
	cout << "-------------------------------" << endl;
	cout << "后序遍历递归方法: ";
	binarytree.BTPostOrder();
	cout << endl;
	cout << "后序遍历非递归方法: ";
	binarytree.BTPostOrder1();
	cout << endl;
	return 0;
}
