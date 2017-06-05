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
	void printReverseHelper(node *temp){
		if(temp==NULL)
			return;
		else{
			printReverseHelper(temp->next);
			cout<<temp->value<<" ";
		}
	}
	void printReverse(){
		printReverseHelper(head);
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
	l.printReverse();
	return 0;
}
