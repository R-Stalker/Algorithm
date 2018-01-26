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
	//前序遍历
	void PreOrder(){
		cout << data << " ";
		if(lchild != NULL){
			lchild->PreOrder();
		}
		if(rchild != NULL){
			rchild->PreOrder();
		}
	}

	//方法1：已知后序遍历、中序遍历求前序遍历（建立对应二叉树）
	Node* PostIn2PreBuild(const string &post_str, const string &in_str, int len){
		Node *p = new Node(post_str[len-1] - '0');
		int pos = in_str.find(post_str[len-1]);
		if(pos > 0){
			p->lchild = PostIn2PreBuild(post_str.substr(0, pos), in_str.substr(0, pos), pos);
		}
		if(len - pos - 1 > 0){
			p->rchild = PostIn2PreBuild(post_str.substr(pos, len - pos - 1), in_str.substr(pos+1), len - pos - 1 );
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
	//前序遍历
	void BTPreOrder(){
		root->PreOrder();
	}

	//for 方法1
	BinaryTree(const string &pre_str, const string &in_str, int len){
		root = root->PostIn2PreBuild(pre_str, in_str, len);
	}
};

//方法2: 已知后序遍历、中序遍历求前序遍历（不建树直接得前序遍历序列）
void PostIn2Post(const string &post_str, const string &in_str,  int len, char *pre_str, int &index){
    if(len <= 0){
        return;
    }
    if(len == 1){
        pre_str[index] = post_str[0];
        index++;
        return;
    }
    char root = post_str[len - 1];
    int pos = in_str.find(root);
    pre_str[index] = root;
    index++;
    PostIn2Post(post_str.substr(0, pos), in_str, pos, pre_str, index);
    PostIn2Post(post_str.substr(pos, len-pos-1), in_str.substr(pos+1), len-pos-1, pre_str, index);
}

int main(){
	string post_str = "965843721";
    string in_str = "963548127";
    BinaryTree binarytree(post_str, in_str, in_str.length());
    cout << "方法1：" << endl;
    cout << "前序遍历结果:";
    binarytree.BTPreOrder();
    cout << endl;

    cout << "--------------------------------------------" << endl;
    cout << "方法2：" << endl;
    cout << "前序遍历结果:";
    int len = in_str.length();
    char *pre_str = new char[len];
    int index = 0;
    PostIn2Post(post_str, in_str, len, pre_str, index);
    for(int i = 0; i < len; i++){
        cout << pre_str[i] << " ";
    }
    delete[] pre_str;
	return 0;
}
