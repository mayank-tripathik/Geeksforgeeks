/*
 * Given a binary tree, check if it is foldable or not
 * A tree is foldable if left and right subtree of tree are mirror images of each other
 * Following is a recursive an iterative way of finding if tree is foldable
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

bool isFoldableIterative(TreeNode* root){
	// Left queue stoes left subtree and right queue stores right subtree
	queue<TreeNode*> leftQ,rightQ;
	// Initially push the root in both of them
	leftQ.push(root);
	rightQ.push(root);
	// While both queue has elements
	while(!leftQ.empty() && !rightQ.empty()){
		// Pop elements from both queue, these elements will the corresponding mirror elements in
		// left and right subtrees
		TreeNode* leftParent=leftQ.front();
		leftQ.pop();
		TreeNode* rightParent=rightQ.front();
		rightQ.pop();
		// If one of them is NULL and other is not, means not mirror images
		if(leftParent!=NULL && rightParent==NULL || leftParent==NULL && rightParent!=NULL)
			return false;
		else{
			// Else if popped elements has both childs, push left and right child of both in following order
			if(leftParent!=NULL && rightParent!=NULL){
				leftQ.push(leftParent->left);
				leftQ.push(leftParent->right);
				rightQ.push(rightParent->right);
				rightQ.push(rightParent->left);

			}
		}
	}
	// If both queues are empty, then only they are foldable
	if(leftQ.empty() && rightQ.empty())
		return true;
	else
		return false;
}

bool isFoldableRecursiveHelper(TreeNode* leftSubtree, TreeNode* rightSubtree){
	// If both corresponding trees are NULL, then return tre 
	if(leftSubtree==NULL && rightSubtree==NULL)
		return true;
	// If one of them is NULL an other is not, return false;
	if(leftSubtree==NULL || rightSubtree==NULL)
		return false;
	// else check if recursion is true for corresponding subtrees for both left and right of subtrees
	return (isFoldableRecursiveHelper(leftSubtree->left, rightSubtree->right) && 
			isFoldableRecursiveHelper(leftSubtree->right, rightSubtree->left));
}

bool isFoldableRecursive(TreeNode* root){
	// If root is NULL, it is indeed foldable
	if(root==NULL)
		return true;
	else
		return isFoldableRecursiveHelper(root->left, root->right);
}

int main(){
	TreeNode *root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(8);
	//root->right->right=new TreeNode(8);
	if(isFoldableIterative(root))
		cout<<"Tree is foldable\n";
	else
		cout<<"Tree is not foldable\n";
}
