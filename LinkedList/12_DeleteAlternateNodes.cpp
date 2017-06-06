/*
 * Given a Singly Linked List, starting from the second node delete all alternate nodes of it. 
 * Examples: if the given linked list is 1->2->3->4->5 then your function should convert it to 1->3->5
 * If the given linked list is 1->2->3->4 then convert it to 1->3.
 * Following are the recursive and iterative ways of deleting alternating nodes
 * TC:O(n)
 */

#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int value;
public:
	node * next;
	node(int x){
		value=x;
		next=NULL;
	}
};

node* pushFront(node *head,int x){
	node* temp=new node(x);
	temp->next=head;
	head=temp;
	return head;
}
void print(node *head){
	cout<<"List:";
	node* temp=head;
	while(temp){
		cout<<temp->value<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

node* deleteAlternateNodesIterative(node* head){
	node* current=head;
	// This loop runs while till list has one node or no node at all
	while(current && current->next){
		// Store node next to current node
		node* temp=current->next;
		// Make current's next pointer point to next of next node
		current->next=current->next->next;
		// delete current's next node
		delete(temp);
		// Advance current pointer
		current=current->next;
	}
	return head;
}

node* deleteAlternateNodesRecursive(node* head){
	// If one node or no node is remaining simply return head
	if(head==NULL || head->next==NULL)
		return head;
	// Else call recursively
	deleteAlternateNodesRecursive(head->next->next);
	// At this point delete node next to head and advance head
	node* temp=head->next;
	head->next=head->next->next;
	delete(temp);
	return head;
}

int main(){
	int n,m;
	cin>>n;
	node *list=NULL;
	while(n--){
		int x;
		cin>>x;
		list=pushFront(list,x);
	}
	print(list);
	list=deleteAlternateNodesIterative(list);
	print(list);
}
