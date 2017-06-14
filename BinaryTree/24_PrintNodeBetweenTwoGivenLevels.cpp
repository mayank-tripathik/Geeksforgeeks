/*
 * Given a binary tree and two level numbers ‘low’ and ‘high’, print nodes from level low to level high.[inclusive both]
 * We can use level order traversal to loop through line by line, and print the nodes at certain level only if its level 
 * lies between the given range
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
void inorder(TreeNode *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->value<<" ";
	inorder(root->right);
}


void printNodesBetweenGivenLevels(TreeNode* root, int level1, int level2){
	if(root==NULL)
		return;
	queue<TreeNode*> q;
	q.push(root);
	// Level is intially zero
	int level=0;
	while(!q.empty()){
		int n=q.size();
		// Increment the level
		level++;
		// if current level exceed the maxlevel, brek the loop
		if(level>level2)
			break;
		// Else remove all nodes at the current level. There are n nodes at this level
		while(n--){
			TreeNode* parent=q.front();
			q.pop();
			// The removed node should only be print if its level is greater than or equal to
			// min level. Note that it can't exceeds max level as the check above would have broken
			// th loop
			if(level>=level1)
				cout<<parent->value<<" ";
			// Push left and right child if exists
			if(parent->left)
				q.push(parent->left);
			if(parent->right)
				q.push(parent->right);
		}
		// Print new line only if level is printed in above while condition
		if(level>=level1)
			cout<<endl;
	}
}

int main(){
	TreeNode *root=new TreeNode(20);
	root->left=new TreeNode(8);
	root->right=new TreeNode(22);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(12);
	root->right->left=new TreeNode(7);
	root->right->right=new TreeNode(9);
	root->left->right->left=new TreeNode(10);
	root->left->right->right=new TreeNode(14);
	root->right->right->right=new TreeNode(23);
	int level1=2;
	int level2=3;
	printNodesBetweenGivenLevels(root,level1,level2);
}
