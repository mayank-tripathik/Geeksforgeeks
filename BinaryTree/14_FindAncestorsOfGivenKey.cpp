/*
 * Given a binary tree, print the ancestors of the given key
 * Following is a recursive way of finding ancestors
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

bool getAncestors(TreeNode* root, int key){
	// if root is null, mean key not found, return 0
	if(root==NULL)
		return false;
	// If key is found, return current true
	if(root->value==key){
		return true;
	}
	// If key is found in the right subtree of left subtree of this node, then print this node
	if(getAncestors(root->left,key) || getAncestors(root->right,key)){
		cout<<root->value<<endl;
		return true;
	}
	return false;
}

int main(){
	TreeNode *root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(6);
	root->right->right=new TreeNode(8);
	//root->right->right=new TreeNode(8);
	getAncestors(root,8);
}
