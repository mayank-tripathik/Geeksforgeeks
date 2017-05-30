#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
	int value;
	ListNode *next;
public:
	ListNode(int x){
		value=x;
		next=NULL;
	}
};

class LinkedList{
	ListNode *head;
public:
	LinkedList(){
		head=NULL;
	}
	void push_front(int x){
		ListNode *temp=new ListNode(x);
		temp->next=head;
		head=temp;
	}
	ListNode* getHead(){
		return head;
	}
	void printList(){
		cout<<"List is:";
		ListNode *temp=head;
		while(temp){
			cout<<temp->value<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
};

class TreeNode{
public:
	int value;
	TreeNode *left;
	TreeNode *right;
public:
	TreeNode(int x){
		value=x;
		left=right=NULL;
	}
};

class BinaryTree{
	TreeNode *root;
public:
	BinaryTree(){
		root=NULL;
	}
	void inorderHelper(TreeNode *head){
		if(head==NULL)
			return;
		inorderHelper(head->left);
		cout<<head->value<<" ";
		inorderHelper(head->right);
	}
	void inorder(){
		cout<<"Inorder traversal of tree:";
		inorderHelper(root);
		cout<<endl;
	}
	void setRoot(TreeNode *head){
		root=head;
	}
};


TreeNode* createBinaryTreeFromList(LinkedList head){
	ListNode *mylist=head.getHead();
	TreeNode *binaryTree;
	if(!mylist)
		return  binaryTree;
	// Set first node of linked list as root of tree
	binaryTree=new TreeNode(mylist->value);
	queue<TreeNode*> q;
	// pushing root of tree in queue
	q.push(binaryTree);
	// this loop will break when list has no more nodes to traverse
	while(1)
	{
		// pop from queue, this is the current parent
		TreeNode *t=q.front();
		q.pop();
		// advance head of linked list to next node
		mylist=mylist->next;
		// If next is not null, set it as left child of parent and push this left child into queue
		// If null means parent was last node in linked list, hence break the loop
		if(mylist){
			TreeNode *leftChild=new TreeNode(mylist->value);
			t->left=leftChild;
			q.push(leftChild);
		}
		else
			break;
		// Advance head to next node, if it is not null then this will be right child of parent
		// and push rightchild into the queue
		mylist=mylist->next;
		if(mylist){
			TreeNode *rightChild=new TreeNode(mylist->value);
			t->right=rightChild;
			q.push(t->right);
		}
		else
			break;
	}
	return binaryTree;
}

int main(){
	LinkedList mylist;
	mylist.push_front(29);
	mylist.push_front(36);
	mylist.push_front(30);
	mylist.push_front(25);
	mylist.push_front(15);
	mylist.push_front(12);
	mylist.push_front(10);
	mylist.printList();
	BinaryTree btree;
	TreeNode *root=createBinaryTreeFromList(mylist);
	btree.setRoot(root);
	btree.inorder();
}
