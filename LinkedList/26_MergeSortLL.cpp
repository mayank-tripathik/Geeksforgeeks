/*
 * Given two numbers in the form of linked list, create a new linked list sum , that contains sum of these two numbers
 * For simple representation complexity is O(max(m,n)) where m and n are the size of lists
 */

#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int value;
	node * next;
public:
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

node* mergeTwoSortedList(node *head1, node *head2){
	node *head=new node(1);
	head->next=NULL;
	node *rear=head;
	while(head1 && head2){
		if(head1->value<head2->value){
			rear->next=head1;
			head1=head1->next;
		}
		else{
			rear->next=head2;
			head2=head2->next;
		}
		rear=rear->next;
	}
	rear->next=head1?head1:head2;
	return head->next;
}

void divideIntoHalf(node* head, node **front, node** back){
	node *prevSlow=NULL;
	node *slow=head;
	node* fast=head;
	while(fast && fast->next){
		prevSlow=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	*front=head;
	*back=slow;
	prevSlow->next=NULL;
}

void mergeSort(node** list){
	node *head=*list;
	if(head==NULL || head->next==NULL)
		return;
	node *front,*back;
	divideIntoHalf(head,&front,&back);
	cout<<front->value<<" "<<back->value<<endl;
	mergeSort(&front);
	mergeSort(&back);
	*list=mergeTwoSortedList(front,back);
}
int main(){
	int n;
	cin>>n;
	node *list=NULL;
	while(n--){
		int x;
		cin>>x;
		list=pushFront(list,x);
	}
	print(list);
	mergeSort(&list);
	print(list);
}
