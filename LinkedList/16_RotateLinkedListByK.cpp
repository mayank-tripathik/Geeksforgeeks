/*
 * Given a singly linked list, rotate the linked list counter-clockwise by k nodes, Where k is a given positive integer. 
 * Example,Given Linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40. 
 * We need to change next of kth node to NULL, next of last node to previous head node, and finally change head to (k+1)th node. 
 * So we need to get hold of three nodes: kth node, (k+1)th node and last node.
 * Traverse the list from beginning and stop at kth node. Store pointer to kth node. We can get (k+1)th node using kthNode->next. 
 * Keep traversing till end and store pointer to last node also. Finally, change pointers as stated above.
 * TC:O(n)
 * Another method:-
	a) Reverse the linklist from 1 to K
	b) Reverse the linklist from K+1 to N
	c) And then reverse the whole Linklist.
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

node* rotateLinkedListByK(node* head, int k){
	// If list is empty or k is less than or equal to 0, do nothing
	if(head==NULL || k<=0)
		return head;
	// This pointer will store the address of kth node, and is also used to access (k+1)th node which will be new head
	node* newHeadPrevious=head;
	// This will cause skip of k nodes
	k=k-1;
	// move pointer to kth node
	while(newHeadPrevious && k--){
		newHeadPrevious=newHeadPrevious->next;
	}
	// if kth node is NULL or (k+1)th node is NULL, nothing to do
	if(newHeadPrevious->next==NULL || newHeadPrevious==NULL)
		return head;
	else{
		// This pointer will point to end of linked list, which we have to attach with current head
		node *rear=newHeadPrevious;
		// Move rear to end of linked list
		while(rear->next!=NULL)
			rear=rear->next;
		// point end of linked list to head
		rear->next=head;
		// (k+1)th node is the new head
		head=newHeadPrevious->next;
		// Make next value of kth node NULL
		newHeadPrevious->next=NULL;
		// return modified head
		return head;
	}

}

int main(){
	int n,k;
	cin>>n>>k;
	node *list=NULL;
	while(n--){
		int x;
		cin>>x;
		list=pushFront(list,x);
	}
	print(list);
	list=rotateLinkedListByK(list,k);
	print(list);
}
