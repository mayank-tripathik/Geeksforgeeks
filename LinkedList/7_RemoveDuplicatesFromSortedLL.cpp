/*
 * Given a sorted linked list, delete the duplicates values
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
	void removeDuplicatesFromSorted(){
		if(!head)
			return;
		// previous points to a pointer previous to current
		node *previous,*current;
		previous=head;
		current=head->next;
		while(current){
			// If two successive nodes have equal value, delete the later(current here)
			if(previous->value==current->value){
				previous->next=current->next;
				delete(current);
				current=previous->next;
			}
			// Otherwise move forward both the pointers
			else{
				previous=current;
				current=current->next;
			}

		}
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
	l.removeDuplicatesFromSorted();
	l.print();
	return 0;
}
