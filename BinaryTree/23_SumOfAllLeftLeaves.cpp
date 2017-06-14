/*
 * Given a Binary Tree, find sum of all left leaves in it.
 * We can use one extra pointer called parent that keeps track of the parent of the current node.
 * If current node being visited is leaf and is the left child of its parent we can include its value in sum
 * We will do the same process in all the subtrees recursively
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

int sumOfAllLeftLeavesHelper(TreeNode* root, TreeNode* parent){
	// If root is NULL, sum is zero
	if(root==NULL)
		return 0;
	// Else check if node is a leaf node(left and right child are NULL) and it is the left child of it is parent
	if(root->left==NULL && root->right==NULL && parent!=NULL && parent->left==root)
		return root->value;
	// Recur for left and right subtrees and add the sum so obtained and return
	return sumOfAllLeftLeavesHelper(root->left,root)+sumOfAllLeftLeavesHelper(root->right,root);
}

int sumOfAllLeftLeaves(TreeNode* root){
	// NULL indicates parent of the root of the tree
	return sumOfAllLeftLeavesHelper(root,NULL);
}

int main(){
	TreeNode *root=new TreeNode(20);
	root->left=new TreeNode(9);
	root->right=new TreeNode(49);
	root->left->left=new TreeNode(5);
	root->left->right=new TreeNode(12);
	root->right->left=new TreeNode(23);
	root->right->right=new TreeNode(52);
	root->left->right->right=new TreeNode(15);
	root->right->right->left=new TreeNode(50);
	cout<<sumOfAllLeftLeaves(root);
}
