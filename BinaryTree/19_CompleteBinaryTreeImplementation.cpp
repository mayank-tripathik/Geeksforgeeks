/*
 * A complete binary tree is a binary tree where each level ‘l’ except the last has 2^l nodes and the nodes at the last level 
 * are all left aligned. Complete binary trees are generally represented using arrays. The array representation is better 
 * because it doesn’t contain any empty slot.
 * Problem is to implement linked representation of complete binary tree. Here Linked mean a non-array representation where 
 * left and right pointers(or references) are used to refer left and right children respectively.
 * To create a linked complete binary tree, we need to keep track of the nodes in a level order fashion such that the next 
 * node to be inserted lies in the leftmost position. A queue data structure can be used to keep track of the inserted nodes. 
 * Following is way to implement complete binary tree.
 */

#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
	int value;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(int x){
		value=x;
		left=right=NULL;
	}
	
};

class CompleteBinaryTree{
	TreeNode* root;
	queue<TreeNode*> q;
public:
	CompleteBinaryTree(){
		root=NULL;
	}
	// We will use queue to keep track of full nodes. New node will be made right or left child of that node
	// which is the oldest non full node. In this way we can keep the complete binary tree property maintained
	void insert(int x){
		// create new node with value x
		TreeNode* temp=new TreeNode(x);
		// If queue is empty, make new node as root and enqueue it
		if(q.empty()){
			root=temp;
			q.push(root);
		}
		// Else refer to queue front element to decide where to put the new node
		else{
			// Retrieve the front element
			TreeNode* parent=q.front();
			// If front node has no left child, make new node as left child of front node
			// and enqueue it new node 
			if(!parent->left){
				parent->left=temp;
				q.push(parent->left);
			}
			// If control is here, means left child of front node is filled
			// Hence fill right child and pop the front element as it is a full node now
			else{
				parent->right=temp;
				q.push(parent->right);
				q.pop();
			}
		}
	}
	void inorderHelper(TreeNode* temp){
		if(temp==NULL)
			return;
		inorderHelper(temp->left);
		cout<<temp->value<<" ";
		inorderHelper(temp->right);
	}
	void inorder(){
		cout<<"Inorder Traversal:\n";
		inorderHelper(root);
		cout<<endl;
	}
	void levelOrder(){
		cout<<"Level order traversal\n";
		if(root==NULL)
			return;
		queue<TreeNode*> que;
		que.push(root);
		while(!que.empty()){
			int n=que.size();
			while(n--){
				TreeNode* parent=que.front();
				que.pop();
				cout<<parent->value<<" ";
				if(parent->left)
					que.push(parent->left);
				if(parent->right)
					que.push(parent->right);
			}
			cout<<endl;
		}
		
	}

};

int main(){
	CompleteBinaryTree tree;
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		tree.insert(x);
	}
	tree.inorder();
	tree.levelOrder();
	return 0;
}
