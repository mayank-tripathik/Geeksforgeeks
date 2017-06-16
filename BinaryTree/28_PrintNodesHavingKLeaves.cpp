/*
 * Given a binary tree and a integer value K, the task is to find all nodes in given binary tree having K leaves in subtree 
 * rooted with them.
 * Here any node having K leaves means sum of leaves in left subtree and in right subtree must be equal to K. 
 * So to solve this problem we use Postorder traversal of tree. 
 * First we calculate leaves in left subtree then in right subtree and if sum is equal to K, then print current node. 
 * In each recursive call we return sum of leaves of left subtree and right subtree to it’s ancestor.
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

int printNodesWithKLeaves(TreeNode *root, int k)
{
	// if root is empty return 0
	if(root==NULL)
		return 0;
	// Else if current node's left and right child is empty, this is a leaf node
	// hence count it and return 1
	if(root->left==NULL && root->right==NULL)
		return 1;
	// count total leaves rooted at the subtree by recursively calling left and right subtrees
	// and adding them
	int totalLeaves=printNodesWithKLeaves(root->left,k)+printNodesWithKLeaves(root->right,k);
	// If total leaves becomes equal to k, print node's value
	if(totalLeaves==k)
		cout<<root->value<<" ";
	// return total leaves present at this subtree to its ancestor
	return totalLeaves;
}

int main(){
	TreeNode *root=new TreeNode(20);
	root->left=new TreeNode(9);
	root->right=new TreeNode(49);
	root->left->left=new TreeNode(5);
	root->left->right=new TreeNode(12);
	root->right->left=new TreeNode(23);
	root->right->right=new TreeNode(52);
	int k=2;
	printNodesWithKLeaves(root,k);
}
