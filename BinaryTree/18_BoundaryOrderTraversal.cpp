/*
 * Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root
 * We break the problem in 3 parts:
    1. Print the left boundary in top-down manner.
    2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts:
    2.1 Print all leaf nodes of left sub-tree from left to right.
    2.2 Print all leaf nodes of right subtree from left to right.
    3. Print the right boundary in bottom-up manner.
 * We have to make sure that no node is printed more than once
 * For this we can print root once. Then we will print the left boundary(except the last leaf node) in top down manner. 
 * Then we will print all leaves. Then we will print right boundary(except the last leaf node) in bottom up manner
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

// Note that we can find leaves by using any traversal. Here we have used preorder 
void printLeaf(TreeNode* root){
	// if root is null, nothing to do
	if(root==NULL)
		return;
	// If node has no left and right child, means it is leaf, print it
	if(root->left==NULL && root->right==NULL){
		cout<<root->value<<" ";
		return;
	}
	// Else recur for left and right subtree to find leaves
	printLeaf(root->left);
	printLeaf(root->right);
}

void printRightBoundary(TreeNode* root){
	// if leaf is encountered, return from here
	if(root->left==NULL && root->right==NULL)
        return;
    // since we have to print right boundary in reverse, unlike leftboundary function we don't print node's
    // value here. Instead we recur until node next to leaf is encountered.
    // Recur for right if present
    if(root->right)
		printRightBoundary(root->right);
	// recur for left if right is not present
	else if(root->left)
		printRightBoundary(root->left);
	// now print node's value in bottom up manner
	cout<<root->value<<" ";
}

void printLeftBoundary(TreeNode* root){
	// if leaf encountered, don't print it return from here
    if(root->left==NULL && root->right==NULL)
        return;
    // else print node value
    cout<<root->value<<" ";
    // recur for root left if present
    if(root->left)
		printLeftBoundary(root->left);
	// if root left is not present recur for root right as right node will
	// be contribute to boundary
	else if(root->right)
		printLeftBoundary(root->right);
}

void boundaryTraversal(TreeNode *root)
{
	// if root is null, nothing to do
	if(root==NULL)
	    return;
	// print the root value
    cout<<root->value<<" ";
    // if root has left child, print left boundary
    if(root->left)
	    printLeftBoundary(root->left);
	// print all leaves on left and right subtree
	// note that we have not written simply printLeaves(root), becasue in case on single node
	// we would have root's value printed twice, one by above and one when printleaves is called
	printLeaf(root->left);
	printLeaf(root->right);
	// if root has right subtree print right boundary
	if(root->right)
		printRightBoundary(root->right);
}

int main(){
	TreeNode *root=new TreeNode(20);
	//root->left=new TreeNode(8);
	//root->right=new TreeNode(22);
	// root->left->left=new TreeNode(4);
	// root->left->right=new TreeNode(12);
	// root->right->right=new TreeNode(25);
	// root->left->right->left=new TreeNode(10);
	// root->left->right->right=new TreeNode(14);
	boundaryTraversal(root);
}
