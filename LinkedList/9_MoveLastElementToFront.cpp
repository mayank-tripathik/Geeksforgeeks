/*
 * Given a singly linked list, move last node to front
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

class llist{
	node *head;
public:
	llist(){
		head=NULL;
	}
	void pushFront(int x){
		node* temp=new node(x);
		temp->next=head;
		head=temp;
	}
	void moveLastElementToFront(){
		// If list has one element or no element at all, nothing to do
		if(head==NULL || head->next==NULL)
			return;
		// rear element will be moved to second last element
		node *rear=head;
		while(rear->next->next){
			rear=rear->next;
		}
		// rear is now at second last element, store element next to it
		node* temp=rear->next;
		// Make second last element pointing to NULL
		rear->next=NULL;
		// Move rear to first and make it head
		temp->next=head;
		head=temp;
	}
	void print(){
		cout<<"List:";
		node* temp=head;
		while(temp){
			cout<<temp->value<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
};
int main(){
	int n;
	cin>>n;
	llist l;
	while(n--){
		int x;
		cin>>x;
		l.pushFront(x);
	}
	l.print();
	l.moveLastElementToFront();
	l.print();
	return 0;
}
