/*
 * Given two numbers in the form of linked list, create a new linked list sum , that contains sum of these two numbers
 * For simple representation complexity is O(max(m,n)) where m and n are the size of lists
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

node* reverseList(node* head){
	if(!head)
		return NULL;
	node* previous,*current,*nxt;
	previous=NULL;
	current=head;
	nxt=head;
	while(nxt){
		nxt=current->next;
		current->next=previous;
		previous=current;
		current=nxt;
	}
	return previous;
}

node* pushBack(node* rear, int sum){
	node* temp=new node(sum);
	rear->next=temp;
	rear=rear->next;
	return rear;
}

// This function will add number represted by list in this form
// Input:
//   First List: 7->5->9->4->6  // represents number 64957
//   Second List: 8->4 //  represents number 48
// Output
//   Resultant list: 5->0->0->5->6  // represents number 65005
node* addListSimple(node* head1, node* head2){
	node* sumHead=NULL,*sumRear;
	int carry=0;
	while(head1 || head2){
		int a=0,b=0;
		if(head1){
			a=head1->value;
			head1=head1->next;
		}
		if(head2){
			b=head2->value;
			head2=head2->next;
		}
		int sum=a+b+carry;
		carry=sum/10;
		sum=sum%10;
		if(sumHead==NULL){
			node* temp=new node(sum);
			sumHead=sumRear=temp;
		}
		else{
			sumRear=pushBack(sumRear,sum);
		}
	}
	if(carry)
		sumRear=pushBack(sumRear,carry);
	return sumHead;
}

node* addListComplex(node* head1, node* head2){
	node *temp1=head1,*temp2=head2;
	head1=reverseList(head1);
	head2=reverseList(head2);
	node* sumHead=addListSimple(head1,head2);
	head1=reverseList(temp1);
	head2=reverseList(temp2);
	return sumHead;
}

int main(){
	int n,m;
	cin>>n>>m;
	node *list1=NULL,*list2=NULL;
	while(n--){
		int x;
		cin>>x;
		list1=pushFront(list1,x);
	}
	while(m--){
		int x;
		cin>>x;
		list2=pushFront(list2,x);
	}
	node* sum=addListSimple(list1,list2);
	print(list1);
	print(list2);
	print(sum);
}
