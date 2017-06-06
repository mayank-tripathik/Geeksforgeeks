/*
 * Given a binary tree, check whether it is full or not
 * A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes. 
 * Conversely, there is no node in a full binary tree, which has one child node. 
 * We can use above information to check if any condtion is violated.
 * Both recursive and iterative solution works in O(n)
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

bool isFullBinaryTreeHelper(TreeNode* root){
	// If both left and right child of current node are NULL, then tree rooted at current is a binary tree
	if(root->left==NULL && root->right==NULL)
		return true;
	// If one of the child is NULL and other is not, it is not a full binary tree hence return false
	if(root->left==NULL || root->right==NULL)
		return false;
	// Otherwise check recursively in both left and right subtrees and ensure both satisfies the above properties
	return (isFullBinaryTreeHelper(root->left) && isFullBinaryTreeHelper(root->right));
}

bool isFullBinaryTreeRecursive(TreeNode* root){
	// if tree is empty, it is afull binary tree, if not empty call recursive function
	if(root==NULL)
		return true;
	else
		return isFullBinaryTreeHelper(root);
}

// Iterative solution works by checking at each stage whether current node has both children, or no children
// or one children, if it has only one, false is return immediately, otherwise process continues
bool isFullBinaryTreeIterative(TreeNode* root){
	if(!root)
		return true;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode* parent=q.front();
		q.pop();
		if(parent->left==NULL && parent->right==NULL)
			continue;
		else if(parent->left==NULL || parent->right==NULL)
			return false;
		else{
			q.push(parent->left);
			q.push(parent->right);
		}
	}
	return true;
}

int main(){
	TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(8);
	root->right=new TreeNode(2);
	root->left->left=new TreeNode(3);
	root->left->right=new TreeNode(5);
	//root->right->left=new TreeNode(2);
	root->right->right=new TreeNode(23);
	if(isFullBinaryTreeIterative(root))
		cout<<"Tree is full binary tree\n";
	else
		cout<<"Tree is not a full binary tree\n";
}
