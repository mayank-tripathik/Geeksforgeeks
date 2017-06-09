/*
 * Given two linked lists, represented as linked lists (every character is a node in linked list). 
 * Write a function compare() that works similar to strcmp().
 * That is, it returns 0 if both strings are same, 1 if first linked list is lexicographically greater, and -1 
 * if second string is lexicographically greater.
 * TC:O(smaller(m,n))
 * Examples:
   Input: list1 = g->e->e->k->s->a
          list2 = g->e->e->k->s->b
   Output: -1
   Input: list1 = g->e->e->k->s->a
          list2 = g->e->e->k->s
   Output: 1
   Input: list1 = g->e->e->k->s
          list2 = g->e->e->k->s
   Output: 0
 */

#include<bits/stdc++.h>
using namespace std;
class node{
public:
	char value;
public:
	node * next;
	node(char x){
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

// Iterative implementation of compare string function
int compareStrings(node *head1, node *head2) {
	node *node1 = head1;
	node *node2 = head2;
	// Go till first mismatch between characters is found 
	while(node1 && node2) {
		if(node1->value < node2->value)
			return -1;
		else if(node1->value > node2->value)
			return 1;
		else {
			node1 = node1->next;
			node2 = node2->next;
		}		
	}
	// if strings are empty, return 0 
	if(!node1 && !node2)
		return 0;
	// else if first string has still some characters left, it is greater
	else if(!node1)
		return -1;
	// string2 is greater as it is not empty
	else
		return 1;
}

// Recursive implementation of compare string function
int compareStrings(node* head1,node* head2){
	// If both strings are empty, return true
	if(head1==NULL && head2==NULL)
		return 0;
	// if string1 is empty and string2 is not empty, string2 is greater
	else if(head1==NULL && head2!=NULL)
		return -1;
	// if string2 is empty and string1 is not empty, string1 is greater
	else if(head1!=NULL && head2==NULL)
		return 1;
	// If control is here means both string are not empty
	// if current character of string1 is greater than string2, string1 is greater
	else if(head1->value>head2->value) 
		return 1;
	// if current character of string2 is greater than string1, string2 is greater
	else if(head1->value<head2->value)
		return -1;
	// Means both current character is same, recur for next characters
	else
		return compareString(head1->next,head2->next);
}


int main(){
	int n,m;
	cin>>n>>m;
	node *list1=NULL,*list2=NULL;
	while(n--){
		char x;
		cin>>x;
		list1=pushFront(list1,x);
	}
	while(m--){
		char x;
		cin>>x;
		list2=pushFront(list2,x);
	}
	print(list1);
	print(list2);
	int returnValue=compareStrings(list1,list2);
	if(returnValue==0)
		cout<<"Strings are equal\n";
	else if(returnValue==1)
		cout<<"String1 is lexicographically greater than String2\n";
	else
		cout<<"String2 is lexicographically greater than String1\n";
}
