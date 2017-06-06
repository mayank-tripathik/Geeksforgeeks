/*
 * Given a binary tree, find its minimum depth. 
 * The minimum depth is the number of nodes along the shortest path from root node down to the nearest leaf node.
 * For every node, wecan find the minimum depth of its left and right subtree. If one of the subtree is NULL, we can 
 * simply return the other one
 * WE can code the above observation in recursive code
 * TC:O(n)
 * Note that this approach runs for whole tree, even if shorteds leaf node is found much before
 * We can use iterative approach, where we do level order traversal and break as soon as we got a leaf node
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

int minDepthRecursive(TreeNode* root){
	// If tree is empty return 0
	if(root==NULL)
		return 0;
	// If node is a leaf node return 1
	if(root->left==NULL && root->right==NULL)
		return 1;
	// Else if node has only left child recur for it
	if(root->left && !root->right)
		return minDepthRecursive(root->left)+1;
	// Else if node has only right child recur for it
	if(!root->left && root->right)
		return minDepthRecursive(root->right)+1;
	// Else if node has both left and right child, recur for it and take minimum of them
	return min(minDepthRecursive(root->left),minDepthRecursive(root->right))+1;
}

int minDepthIterative(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);
	int depth=0;
	while(!q.empty()){
		depth++;
		int n=q.size();
		while(n--){
			TreeNode* parent=q.front();
			q.pop();
			if(parent->left==NULL && parent->right==NULL)
				return depth;
			if(parent->left)
				q.push(parent->left);
			if(parent->right)
				q.push(parent->right);
		}

	}
	return depth;
}

int main(){
	TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(8);
	root->right=new TreeNode(2);
	root->left->left=new TreeNode(3);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(4);
	root->right->left->right=new TreeNode(9);
	root->right->right=new TreeNode(23);
	cout<<minDepthIterative(root)<<endl;
}
