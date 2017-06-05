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
        if(head==NULL || head->next==NULL)
            return;
		node *rear=head;
		while(rear->next->next){
			rear=rear->next;
		}
		node* temp=rear->next;
		rear->next=NULL;
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
