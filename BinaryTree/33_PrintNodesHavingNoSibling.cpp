/*
 * Given a Binary Tree, print all nodes that don’t have a sibling (a sibling is a node that has same parent. 
 * In a Binary Tree, there can be at most one sibling). Root should not be printed as root cannot have a sibling.
 * Another way of saying is that we need to print those nodes which are only child of their parent
 * We can do it using any traversal. Following is the preorder way coded
 * TC:O(n)
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

void printSingleChild(TreeNode* root)
{
	if(root==NULL)
		return;
	// if node has only left child, print its left child
	if(root->right==NULL && root->left!=NULL)
		cout<<root->left->value<<" ";
	// if node has only right child, print its right child
	if(root->left==NULL && root->right!=NULL)
		cout<<root->right->value<<" ";
	// recur for left and right subtrees
	printSingleChild(root->left);
	printSingleChild(root->right);
}

int main(){
	TreeNode *root=new TreeNode(8);
	root->left=new TreeNode(3);
	root->right=new TreeNode(10);
	root->left->left=new TreeNode(1);
	root->left->right=new TreeNode(6);
	root->right->right=new TreeNode(14);
	root->left->right->left=new TreeNode(4);
	root->left->right->right=new TreeNode(7);
	root->right->right->left=new TreeNode(13);
	printSingleChild(root);
}
