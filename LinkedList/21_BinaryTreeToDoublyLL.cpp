/*
 * Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
 * The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. 
 * The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
 * The first node of Inorder traversal (left most node in BT) must be head node of the DLL.
 * We add nodes at the beginning of current linked list and update head of the list using pointer to head pointer. 
 * Since we insert at the beginning, we need to process leaves in reverse order. 
 * For reverse order, we first traverse the right subtree before the left subtree. i.e. do a reverse inorder traversal.
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


void treeToLinkedList(TreeNode* root, TreeNode **prev){
	// If tree is empty, return
	if(root==NULL){
		return;
	}
	// Move to right subtree
	treeToLinkedList(root->right,prev);
	// make right of previous point to previous
	root->right = *prev;
	// If previous is not NULL, then root is set as left of previous
    if (*prev != NULL)
        (*prev)->left = root;
    // set root as new previous
    *prev = root;
    // move to left now
	treeToLinkedList(root->left,prev);
}

void printList(TreeNode* root){
	cout<<"List\n";
	while(root){
		cout<<root->value<<" ";
		root=root->right;
	}
}
int main(){
	TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(12);
	root->right=new TreeNode(15);
	root->left->left=new TreeNode(25);
	root->left->right=new TreeNode(30);
	root->right->right=new TreeNode(36);
	root->left->right->left=new TreeNode(10);
	root->left->right->right=new TreeNode(14);
	TreeNode *prev=NULL;
	inorder(root);
	cout<<endl;
	treeToLinkedList(root,&prev);
	//inorder(root);
	printList(prev);
}
