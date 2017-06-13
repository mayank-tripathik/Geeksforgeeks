/*
 * Given a binary tree, check whether it is a mirror of itself.
 * For example, this binary tree is symmetric:

           1
         /   \
        2     2
       / \   / \
      3   4 4   3

      But the following is not:

          1
         / \
        2   2
         \   \
         3    3
* Th program for checking is symmetricity is similar to program for checking if two trees are mirror of each other. Here we
* are just checking if tree is mirror image of itself. So we can pass the two subtrees of root to a function that checks if 
* two trees are mirror of each other. Here that function is named as checkSymmetricity
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

bool checkSymmetricity(TreeNode* leftSubtree, TreeNode* rightSubtree){
	// If the corresponding nodes are NULL, they are symmetric
	if(leftSubtree==NULL && rightSubtree==NULL)
		return true;
	// if only one of them is NULL, they are not symmetric
	else if(leftSubtree==NULL || rightSubtree==NULL)
		return false;
	// If control reaches here means two subtrees are not null, so the two subtrees will be mirror
	// image of each other if the value at their root is same and the corresponding subtree rooted at them is the mirror
	// image of each other
	return((leftSubtree->value==rightSubtree->value) &&
		checkSymmetricity(leftSubtree->left,rightSubtree->right)&&
	checkSymmetricity(leftSubtree->right, rightSubtree->left));
}

bool isSymmetricTree(TreeNode* root){
	// if tree is NULL, it is symmetric
	if(root==NULL)
		return true;
	// else check if right and left subtree are mirror images of each other
	else
		return checkSymmetricity(root->left,root->right);
}

int main(){
	TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(2);
	root->right=new TreeNode(2);
	root->left->left=new TreeNode(3);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(5);
	root->right->right=new TreeNode(3);
	root->left->left->right=new TreeNode(4);
	root->right->right->left=new TreeNode(4);
	if(isSymmetricTree(root))
		cout<<"Tree is a Symmetric Tree\n";
	else
		cout<<"Tree is not a Symmetric Tree\n";
}
