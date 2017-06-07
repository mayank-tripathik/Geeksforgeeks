/*
 * Given a binary tree with one extra field called next that points to inorder successor of it. Populate it so that every node
 * next field point to their inorder successor
 *  What is inorder successor?
    Suppose binary tree is
              10
            /   \
          8      12
        /
      3
    Then inorder successor of 3 is 8, 8 is 10, 10 is 12 and so on.
 * similarly we can have inorder predeccsor
 * We can use inorder traversal to populate the next field by just keep tracking previously visited node, & make next of current
 * node being visited pointing to it
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
	TreeNode* next;
public:
	TreeNode(int x){
		value=x;
		left=right=next=NULL;
	}
	
};

void inorder(TreeNode* root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->value<<" ";
	if(root->next)
		cout<<root->next->value<<endl;
	else
		cout<<"-1\n";
	inorder(root->right);
}

// We can populate the inorder successor using inorder traversal by keeping track of the previous node visited
// We can then set previous node's next to current node to set inorder successor
// Reference to previous is used to avoid static variable
void populateInorderSuccessor(TreeNode* root, TreeNode** previous){
	if(root==NULL)
		return;
	populateInorderSuccessor(root->left,previous);
	// If previous is not NULL,then point its next pointer to current node being visited
	if(*previous)
	{
		(*previous)->next=root;
		*previous=root;
	}
	// If previous is NULL, means it is the bottom leftmost node, hence make it previous
	else
		*previous=root;
	populateInorderSuccessor(root->right,previous);
}

// Similarly we can point each node's next pointer to inorder predeccessor
void populateInorderPredecessor(TreeNode* root, TreeNode** previous){
	if(root==NULL)
		return;
	populateInorderPredecessor(root->left,previous);
	// If previous is not NULL,then point its next pointer to current node being visited
	if(*previous)
	{
		root->next=(*previous);
		*previous=root;
	}
	// If previous is NULL, means it is the bottom leftmost node, hence make it previous
	else
		*previous=root;
	populateInorderPredecessor(root->right,previous);
}

int main(){
	TreeNode *root=new TreeNode(26);
	root->left=new TreeNode(10);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(6);
	root->right->left=new TreeNode(2);
	root->right->right=new TreeNode(5);
	inorder(root);
	cout<<endl;
	TreeNode* previous=NULL;
	populateInorderPredecessor(root,&previous);
	inorder(root);
}
