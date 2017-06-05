/*
 * Given a binary tree and some key, find the level of key, if key is found. Else return 0
 * Recursion can be used on both subtrees, by passing increasing level in each recursive call
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

int getLevelHelper(TreeNode* root, int key, int level){
	// if root is null, mean key not found, return 0
	if(root==NULL)
		return 0;
	// If key is found, return current level
	if(root->value==key){
		return level;
	}
	// Else first check left subtree, if returned level is 0, then only search in right subtree
	int lev=getLevelHelper(root->left,key,level+1);
	if(lev!=0)
		return lev;
	return getLevelHelper(root->right,key,level+1);
}

int getLevel(TreeNode* root, int key){
	// start with level 1, the level of the root
	int level=1;
	return getLevelHelper(root,key,level);

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
	cout<<getLevel(root,2)<<endl;
}
