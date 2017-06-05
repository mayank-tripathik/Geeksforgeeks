/*
 * Given a tree, create double tree for it
 * In Double tree ,a new duplicate for each node should be created, and inserted the as the left child of the original node.
 * Example : 

             1
          /   \
        2      3
      /  \
    4     5

	is changed to

	               1
	             /   \
	           1      3
	          /      /
	        2       3
	      /  \
	     2    5
	    /    /
	   4   5
	  /   
	 4    

 * Double tree can be create in any tree traversal order in same complexity
 * Following is preorder way to create double t
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

// This function will create double tree in the preorder way
// note that double tree can be created in other orders too
void createDoubleTree(TreeNode* root){
	// root is NULL, nothing to do
	if(root==NULL)
		return;
	// Create a duplicate of current node value
	TreeNode* duplicate=new TreeNode(root->value);
	// Store left and right subtree of current node, so that we can recur it later
	TreeNode *leftSubTree=root->left;
	TreeNode *rightSubTree=root->right;
	// Set duplicate left as left of current node
	duplicate->left=leftSubTree;
	// set left of current node as duplicate node
	root->left=duplicate;
	// recur for left and right subtree of root through stored pointers previously
	createDoubleTree(leftSubTree);
	createDoubleTree(rightSubTree);
}

int main(){
	TreeNode *root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(8);
	inorder(root);
	cout<<endl;
	createDoubleTree(root);
	inorder(root);
}
