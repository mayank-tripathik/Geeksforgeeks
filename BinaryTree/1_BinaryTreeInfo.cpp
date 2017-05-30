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

void iterativeInorder(node *root){
	stack<node *> s;
	node *current=root;
	while(current || !s.empty())
	{
		// Traverse to extreme left, by pushing every node encountered on the way
		if(current)
		{
			s.push(current);
			current=current->left;
		}
		// if we are at extreme left, pop node from stack and print its value, and make current as its right subtree
		// if rightsubtree is null, above if(current) loop will not execute, resulting into another pop and so on.
		else
		{
			node *temp=s.top();
			cout<<temp->value<<" ";
			s.pop();
			current=temp->right;
		}
	}
}

void preorder(node *root){
	if(root==NULL)
		return;
	cout<<root->value<<" ";
	preorder(root->left);
	preorder(root->right);
}

void iterativePreorder(node *root){
	stack<node *> s;
	s.push(root);
	while(!s.empty()){
		node *temp=s.top();
		s.pop();
		cout<<temp->value<<" ";
		if(temp->right)
			s.push(temp->right);
		if(temp->left)
			s.push(temp->left);
	}
}

void postorder(node *root){
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->value<<" ";
}

void iterativePostorder(node *root){
	stack<node*> s1,s2;
	s1.push(root);
	while(!s1.empty()){
		node *temp=s1.top();
		if(temp->left || temp->right){
			if(!s2.empty() && s1.top()==s2.top()){
				s1.pop();
				s2.pop();
				cout<<temp->value<<" ";
			}
			else{
				if(temp->right)
					s1.push(temp->right);
				if(temp->left)
					s1.push(temp->left);
				s2.push(temp);
			}
		}
		else{
			s1.pop();
			cout<<temp->value<<" ";
		}
	}
}

void iterativePostorder(node *root){
	stack<node*> s1,s2;
	s1.push(root);
	while(!s1.empty()){
		node *temp=s1.top();
		s1.pop();
		if(temp->left)
			s1.push(temp->left);
		if(temp->right)
			s1.push(temp->right);
		s2.push(temp);
	}
	while(!s2.empty()){
		cout<<s2.top()->value<<" ";
		s2.pop();
	}
}

void iterativePostorder(node* root)
{
	if(root==NULL)
		return;
	stack<node *> s;
	do{
		while(root){
			if(root->right){
				s.push(root->right);
				//cout<<root->right->value<<" is pushed\n";
			}
			s.push(root);
			//cout<<root->value<<" is pushed\n";
			root=root->left;
		}
		root=s.top();
		s.pop();
		//cout<<root->value<<" is popped\n";
		if(root->right && !s.empty() && s.top()==root->right){
			//cout<<(s.top())->value<<" is popped\n";
			s.pop();
			s.push(root);
			//cout<<root->value<<" is pushed\n";
			root=root->right;
		}
		else{
			cout<<root->value<<" ";
			//cout<<"root is set as null\n";
			root=NULL;
		}
	}while(!s.empty());
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
	node *binaryTree=new node(1);
	binaryTree->left=new node(2);
	binaryTree->right=new node(3);
	binaryTree->left->left=new node(4);
	binaryTree->left->right=new node(5);
	//binaryTree->right->left=new node(5);
	binaryTree->right->right=new node(7);
	binaryTree->left->right->right=new node(8);
	//allTraversals(binaryTree);
	//cout<<"Tree size:"<<sizeOfTree(binaryTree)<<endl;
	//iterativePreorder(binaryTree);
	//iterativeInorder(binaryTree);
	iterativePostorder(binaryTree);
}
