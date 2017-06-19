/*
 * Given a Binary Tree you need to find maximum value which you  can get by subtracting value of node B from value of node A, 
 * where A and B are two nodes of the binary tree and A is an ancestor of B . 
 * we can do preorder traversal, and pass the maximum number obtained till now to the children and keep on updating the 
 * maximum difference found till now. (similar to what we do in arrays. instead of maintaining both max and min, just maintain
 * max. We will automatically get largest diff wherever min will occur)
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

void setMaxMin(TreeNode* child, int *maxDiff, int maxValue){
	if(child==NULL)
		return;
    // if difference between max value so obtained and this node vale is greater than our
    // current maximum difference, update current maximum difference
	if(maxValue-(child->value) > *maxDiff)
		*maxDiff=maxValue-(child->value);
	// update current maximum if this node's value is greater than current maximum
	if(child->value > maxValue)
		maxValue=child->value;
    // recur for left and right subtrees
	setMaxMin(child->left,maxDiff,maxValue);
	setMaxMin(child->right, maxDiff,maxValue);
}

int calMaxDiff(TreeNode* root)
{
	if(root==NULL)
		return INT_MAX;
	if(root->left==NULL && root->right==NULL)
		return root->value;
    // initialize maximum value in tree as root value
	int maxValue=root->value;
    // initialize maximum difference obtained as minimum integer value
	int maxDiff=INT_MIN;
    // set maximum difference considering leftsubtree
	setMaxMin(root->left, &maxDiff,maxValue);
    // resetting max value as root
	maxValue=root->value;
    // updating max difference by considering right subtree
	setMaxMin(root->right,&maxDiff,maxValue);
    //return maximum difference obtained
	return maxDiff;
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
	cout<<calMaxDiff(root);
}
