/*
 * Given two linked lists sorted in increasing order. 
 * Merge them such a way that the result list is in decreasing order (reverse order).
 * Examples:
     1. Input:  a: 5->10->15->40
        b: 2->3->20 
     Output: res: 40->20->15->10->5->3->2
     2. Input:  a: NULL
        b: 2->3->20 
     Output: res: 20->3->2
 * Two solution can be 1) Reverse two list and then merge them using merging two sorted list operation. 2) Or by first merging
 * two sorted list and then reversing them
 * But both require two traversals of list
 * We can do it in one traversal initializing result list as empty and then by comparing elements from both lists and moving 
 * the smaller one to front of the list
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

node* mergeSortedListInReverseOrder(node* head1, node* head2){
	// Initialize the answer list as NULL
	node *head=NULL;
	// While two list has any nodes
	while(head1 || head2){
		// This pointer will point to smaller node of the two(if both exists), otherwise the one which exists
		// and will be further added to the head
		node* temp;
		// if both list have elements and node of first list is smaller or we have second list empty, in both
		// cases node of first list should be added to front of result list
		if((head1 && head2 && (head1->value < head2->value)) || (head2==NULL)){
			temp=head1;
			head1=head1->next;
		}
		// otherwise node of second list must be either smaller or node of first list doesn't exists, both cases
		// results into addition of node of second list to front of result list
		else{
			temp=head2;
			head2=head2->next;
		}
		// moving temp to front and updating head of result list
		temp->next=head;
		head=temp;
	}
	// return head of result list
	return head;

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
	print(list1);
	print(list2);
	node* head=mergeSortedListInReverseOrder(list1,list2);
	print(head);
}
