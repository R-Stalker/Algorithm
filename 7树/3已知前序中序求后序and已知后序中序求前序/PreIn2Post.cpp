#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;


class Node{
public:
	int data;
	Node *lchild;
	Node *rchild;
	Node(int input_data){
		data = input_data;
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

	//方法1：已知前序遍历、中序遍历求后序遍历（建立对应二叉树）
	Node* PreIn2PostBuild(const string &pre_str, const string &in_str, int len){
		Node *p = new Node(pre_str[0] - '0');
		int pos = in_str.find(pre_str[0]);
		if(pos > 0){
			p->lchild = PreIn2PostBuild(pre_str.substr(1, pos), in_str.substr(0, pos), pos);
		}
		if(len - pos - 1 > 0){
			p->rchild = PreIn2PostBuild(pre_str.substr(pos+1), in_str.substr(pos+1), len - pos - 1 );
		}
		return p;
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
	//后序遍历
	void BTPostOrder(){
		root->PostOrder();
	}

	//for 方法1
	BinaryTree(const string &pre_str, const string &in_str, int len){
		root = root->PreIn2PostBuild(pre_str, in_str, len);
	}
};

//方法2: 已知前序遍历、中序遍历求后序遍历（不建树直接得后序遍历序列）
void PreIn2Post(const string &pre_str, const string &in_str,  int len, char *post_str, int &index){
    if(len <= 0){
        return;
    }
    if(len == 1){
        post_str[index] = pre_str[0];
        index++;
        return;
    }
    char root = pre_str[0];
    int pos = in_str.find(root);
    PreIn2Post(pre_str.substr(1, pos), in_str, pos, post_str, index);
    PreIn2Post(pre_str.substr(pos+1), in_str.substr(pos+1), len-pos-1, post_str, index);
    post_str[index] = root;
    index++;
}

int main(){
	string pre_str = "136945827";
    string in_str = "963548127";
    BinaryTree binarytree(pre_str, in_str, in_str.length());
    cout << "方法1：" << endl;
    cout << "后序遍历结果:";
    binarytree.BTPostOrder();
    cout << endl;

    cout << "--------------------------------------------" << endl;
    cout << "方法2：" << endl;
    cout << "后序遍历结果:";
    int len = in_str.length();
    char *post_str = new char[len];
    int index = 0;
    PreIn2Post(pre_str, in_str, len, post_str, index);
    for(int i = 0; i < len; i++){
        cout << post_str[i] << " ";
    }
    cout << endl;
    delete[] post_str;
	return 0;
}
