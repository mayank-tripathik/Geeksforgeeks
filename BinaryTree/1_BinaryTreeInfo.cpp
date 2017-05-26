#include<bits/stdc++.h>
using namespace std;

//Structure of a tree node
struct node{
	int value;
	node *left;
	node *right;
	node(){}
	node(int x){
		value=x;
		left=NULL;
		right=NULL;
	}
};

//Three type of DFS travsersals in a tree
void inorder(node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->value<<" ";
	inorder(root->right);
}
void preorder(node *root){
	if(root==NULL)
		return;
	cout<<root->value<<" ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(node *root){
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->value<<" ";
}

// BFS traversal of tree aka Level order traversal. Print all tree nodes level by level
void levelOrderTraversal(node *root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *temp=q.front();
		cout<<temp->value<<" ";
		q.pop();
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
}

// Level order traversal line by line where nodes of each level are seperately maintained
void levelOrderTraversalByLine(node *root){
	queue<node *> q;
	q.push(root);
	// Maintain number of nodes at the current level
	int nodeAtCurrentLevel;
	while(!q.empty()){
		//Number of nodes at current level will keep changing
		nodeAtCurrentLevel=q.size();
		//To print all nodes at the current level
		while(nodeAtCurrentLevel--){
			node *temp=q.front();
			q.pop();
			cout<<temp->value<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		//After this, only nodes at the next level will remain in the queue
		cout<<endl;
	}
}

//Function to print all type of traversals
void allTraversals(node *binaryTree){
	cout<<"inorder traversal:\n";
	inorder(binaryTree);
	cout<<endl;
	cout<<"preorder traversal:\n";
	preorder(binaryTree);
	cout<<endl;
	cout<<"postorder traversal:\n";
	postorder(binaryTree);
	cout<<endl;
	cout<<"level order traversal:\n";
	levelOrderTraversal(binaryTree);
	cout<<endl;
	cout<<"level order traversal line by line:\n";
	levelOrderTraversalByLine(binaryTree);
	cout<<endl;
}

// Calculating Tree size using one of the tree traversals (inorder here)
// Static is used so that variable value is maintained over recursive calls
// int sizeOfTree(node *root){
// 	static int size=0;
// 	if(root==NULL)
// 		return 0;
// 	sizeOfTree(root->left);
// 	size++;
// 	sizeOfTree(root->right);
// 	return size;
// }

//Recursive method for calculating size of the tree
int sizeOfTree(node *root){
	if(root==NULL)
		return 0;
	else
		return sizeOfTree(root->left)+sizeOfTree(root->right)+1;
}


int main(){
	//node *binaryTree=newNode(11);
	node *binaryTree=new node(11);
	binaryTree->left=new node(2);
	binaryTree->right=new node(3);
	binaryTree->left->left=new node(12);
	binaryTree->left->right=new node(10);
	binaryTree->right->left=new node(5);
	binaryTree->right->right=new node(4);
	allTraversals(binaryTree);
	cout<<"Tree size:"<<sizeOfTree(binaryTree)<<endl;
}
