/*
 * Given a binary tree, print nodes of extreme corners of each level but in alternate order.
 * Example, assuming root at level 1, we should print extreme right value of level 1, then extreme left value of level 2
 * then extreme right of third level and so on
 * The idea is to traverse tree level by level. For each level, we count number of nodes in it and print its leftmost or 
 * the rightmost node based on value of a Boolean flag, which indicates whether level is odd or even
 * We dequeue all nodes of current level and enqueue all nodes of next level and invert value of Boolean flag when switching 
 * levels.
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

void printExtremeNodesAlternatively(TreeNode* root)
{
	// If tree is empty, nothing to print
	if(root==NULL)
		return;
	queue<TreeNode*> q;
    // Insert first node in queue
	q.push(root);
    // This flag indicates if level is even or not. False value indicates level is odd
    // It is toggled after traversal of each level so that we can use it to decide which node
    // to print : extreme right or extreame left. As mentioned in question, if we assume root at level 1
    // we have to print extreme left node at even level and extreme right node at odd level
	bool evenLevel=false;
    // Typical level order traversal implementation
	while(!q.empty()){
		int nodesAtThisLevel=q.size();
        // This variable is used to track which node we are printing. Depending upon whether level is odd
        // or even we can print the extreme left or extreme right node
		int k=nodesAtThisLevel;
		while(k--){
			TreeNode* parent=q.front();
			q.pop();
			if(evenLevel && k==nodesAtThisLevel-1)
				cout<<parent->value<<" ";
			if(!evenLevel && k==0)
				cout<<parent->value<<" ";
			if(parent->left)
				q.push(parent->left);
			if(parent->right)
				q.push(parent->right);
		}
        // Level toggled, so type of level changes for next level traversal
		evenLevel=!evenLevel;
	}
}

int main(){
	TreeNode *root=new TreeNode(4);
	root->left=new TreeNode(2);
	root->right=new TreeNode(-5);
	root->left->left=new TreeNode(-1);
	root->left->right=new TreeNode(3);
	root->right->left=new TreeNode(-2);
	root->right->right=new TreeNode(6);
	printExtremeNodesAlternatively(root);
}
