/*
 * Given two linked list, check if both are identical
 * Two Linked Lists are identical when they have same data and arrangement of data is also same. 
 * For example Linked lists a (1->2->3) and b(1->2->3) are identical.
 * Following is a recursive way of checking if lists are identical
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

bool identical(node* head1, node *head2){
	// If both lists are NULL, return true
	if(head1==NULL && head2==NULL)
		return true;
	// If one of the list is NULL and other is not NULL, return false;
	if((head1==NULL || head2==NULL))
		return false;
	// If no list is NULL, but the value of current node doesn't matches return false
	if(head1->value!=head2->value)
		return false;
	// At this point, all condition are satisfied therefore recur for further nodes
	else
		return identical(head1->next,head2->next);
}

int main(){
	int n,m;
	cin>>n;
	node *list1=NULL,*list2=NULL;
	while(n--){
		int x;
		cin>>x;
		list1=pushFront(list1,x);
	}
	cin>>m;
	while(m--){
		int x;
		cin>>x;
		list2=pushFront(list2,x);
	}
	print(list1);
	print(list2);
	if(identical(list1,list2))
		cout<<"Lists are identical\n";
	else
		cout<<"List are not identical\n";
}
