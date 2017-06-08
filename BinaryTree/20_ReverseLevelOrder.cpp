/*
 * Problem : Do reverse level order traversal of binary tree. What is reverse level order traversal?
 * In reverse level order traversal, we print last level first, then second last level, and so on. 
 * Like Level order traversal, every level is printed from left to right.
 * We will go in the usual level order traversal way, but since we have to print nodes in bottom up manner from left to right, 
 * we will push right child first and then left and also, instead of printing the node just after popping, we will push the 
 * node's value into stack, so that they can be printed in bottom up manner
 * TC:O(n)
 */

#include<bits/stdc++.h>
#include<queue>
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

void inorder(TreeNode *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->value<<" ";
	inorder(root->right);
}

void reverseLevelOrder(TreeNode* root){
	cout<<"Level order traversal\n";
	if(root==NULL)
		return;
	queue<TreeNode*> que;
	stack<int> s;
	que.push(root);
	while(!que.empty()){
		TreeNode* parent=que.front();
		que.pop();
		// Do not print, instead push the value in stack
		s.push(parent->value);
		// push the right child first and then left, so that left will be pushed later
		// and hence will be popped out first while printing (due to stack property)
		if(parent->right)
			que.push(parent->right);
		if(parent->left)
			que.push(parent->left);
	}
	// print stack elements
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}		
}

int main(){
	TreeNode *root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(6);
	root->right->right=new TreeNode(8);
	reverseLevelOrder(root);
}
