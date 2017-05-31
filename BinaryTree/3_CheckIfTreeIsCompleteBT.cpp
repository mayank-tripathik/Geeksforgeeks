#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int value;
	TreeNode *left;
	TreeNode *right;
};

TreeNode* newNode(int x){
	TreeNode* temp=(TreeNode*)malloc(sizeof(TreeNode));
	temp->left=temp->right=NULL;
	temp->value=x;
	return temp;
}

bool isCompleteBinaryTree(TreeNode *root){
	queue<TreeNode*> q;
	q.push(root);
	// This variable will be set true when a non full node is encountered
	// A full node means it has both children, left and right
	// In complete binary tree, after a non full node, no node should have children(means following nodes must be leaf)
	// so this variable is set as soon as one non full node is encountered to further check if any node with children is 
	// encountered or not
	bool noMoreChild=false;
	while(!q.empty()){
		TreeNode* parent=q.front();
		q.pop();
		// if left child of parent is present, then only process
		if(parent->left){
			// if a node is occuring after a non full node but has left children, means not complete binary tree
			if(noMoreChild)
				return false;
			else{
				// if node has left child push it into queue
				q.push(parent->left);
				// if a node has right child also push it too
				if(parent->right){
					q.push(parent->right);
				}
				// if a node who has left child but not has right child means it is first non full node, hence 
				// variable is set true, means furthur node should have no child i.e should be leaf
				else
					noMoreChild=true;
			}
		}
		// if left child not present but right child present, means not complete binary tree
		else if(parent->right)
			return false;
	}
	return true;
}
int main(){
	TreeNode* root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->right=newNode(4);
	root->right->right=newNode(5);
	root->right->left=newNode(6);
	if(isCompleteBinaryTree(root))
		cout<<"It is a complete binary tree\n";
	else
		cout<<"Not a complete binary tree\n";
}
