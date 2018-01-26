#include <iostream>
#include <string>
#include <stdlib.h>
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::swap;

template <typename Type> class Node{
public:
    Type data;
    Node<Type> *lchild, *rchild;
    Node(Type _data){
        data = _data;
        lchild = NULL;
        rchild = NULL;
    }
    ~Node(){
        if(lchild != NULL){
            delete lchild;
        }
        if(rchild != NULL){
            delete rchild;
        }
    }
	void preorder(){
        cout << data;
		if(lchild != NULL){
            lchild->preorder();
        }
        if(rchild != NULL){
            rchild->preorder();
        }
    }
    void inorder(){
        if(lchild != NULL){
            lchild->inorder();
        }
        cout << data;
        if(rchild != NULL){
            rchild->inorder();
        }
    }
    void postorder(){
        if(lchild != NULL){
            lchild->postorder();
        }
        if(rchild != NULL){
            rchild->postorder();
        }
        cout << data;
    }
    //已知前序中序建树
    Node* build(const string &pre_str, const string &in_str, int len){
        Node *p = new Node(pre_str[0]);
        int pos = in_str.find(pre_str[0]);
        if(pos > 0){
            p->lchild = build(pre_str.substr(1,pos), in_str.substr(0,pos), pos);
        }
        if(len - pos - 1 > 0){
            p->rchild = build(pre_str.substr(pos+1), in_str.substr(pos+1), len-pos-1);
        }
        return p;
    }
	//方法1：重新建一个镜像树
    Node* build_mirror(Node *r){
        Node *p = new Node(r->data);
        if(r->lchild != NULL){
            p->rchild = build_mirror(r->lchild);
        }
        if(r->rchild != NULL){
            p->lchild = build_mirror(r->rchild);
        }
        return p;
    }
	//方法2：直接翻转原树
	void ReverseBinaryTree(Node<Type> *p_root){
		if(p_root){
			swap(p_root->lchild, p_root->rchild);
			ReverseBinaryTree(p_root->lchild);
			ReverseBinaryTree(p_root->rchild);
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
    BinaryTree(const string &pre_str, const string &in_str, int len){
        root = root->build(pre_str, in_str, len);
    }
    BinaryTree(Node<Type> *r){
        root = r;
    }
    Node<Type>* build_mirror(){
        return root->build_mirror(root);
    }
    void preorder(){
        root->preorder();
    }
	void inorder(){
		root->inorder();
	}
	void postorder(){
        root->postorder();
	}
    Node<Type>* get_root(){
        return root;
    }
	void ReverseBinaryTree(){
		root->ReverseBinaryTree(root);
	}
};

int main(){
    string pre_str, in_str;
    cin >> pre_str;
    cin >> in_str;
    //根据前序、中序建立该二叉树
    BinaryTree<char> binarytree(pre_str, in_str, in_str.length());
    cout << "-----------------------------------" << endl;
    binarytree.postorder();
	cout << endl;
	//方法1：重新建一个
	cout << "-----------------------------------" << endl;
	cout << "方法1：" << endl;
	BinaryTree<char> mirror_binarytree(binarytree.build_mirror());
	mirror_binarytree.preorder();
	cout << endl;
	mirror_binarytree.inorder();
	cout << endl;
	mirror_binarytree.postorder();
	cout << endl;
	//方法2：直接翻转原树
	cout << "-----------------------------------" << endl;
	cout << "方法2：" << endl;
	binarytree.ReverseBinaryTree();
	binarytree.preorder();
	cout << endl;
	binarytree.inorder();
	cout << endl;
	binarytree.postorder();
	cout << endl;
    return 0;
}










