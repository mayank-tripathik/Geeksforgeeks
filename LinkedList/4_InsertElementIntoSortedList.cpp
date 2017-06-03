/*
 * Given a sorted linked list, insert the new element such that list remains sorted
 * Tc: O(n)
 */

#include<iostream>
#include<cstdlib>
using namespace std;
struct ListNode{
	int value;
	ListNode* next;
};

ListNode* newNode(int x){
	ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
	temp->next=NULL;
	temp->value=x;
	return temp;
}

ListNode* pushFront(ListNode* head,int x){
	ListNode* temp=newNode(x);
	temp->next=head;
	head=temp;
	return head;
}
void print(ListNode* head){
	cout<<"List:";
	ListNode* temp=head;
	while(temp){
		cout<<temp->value<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

ListNode* InsertElementInSortedList(ListNode*head, int x){
	ListNode* previous,*current;
	// previous will always point to a node previous to current node
	previous=NULL;
	current=head;
	ListNode* node=newNode(x);
	while(current){
		// If current node has value greater than x, means new node has to be inserted behind it
		if(current->value>x){
			// if previous is not null, simply insert the new node between previous and current
			if(previous){
				node->next=current;
				previous->next=node;
				return head;
			}
			// If previous is null, means new node has to be inserted at the begining 
			// therefore alter the head after insertion
			else{
				node->next=head;
				head=node;
				return head;
			}
		}
		// if current node is less than x, keep shifting previous and current
		else{
			previous=current;
			current=current->next;
		}
	}
	// If control reaches at this point means node has to be inserted at the last, therefore
	// insert at last using previous
	previous->next=node;
	return head;
}
int main(){
	ListNode* head=newNode(9);
	head=pushFront(head,8);
	head=pushFront(head,6);
	head=pushFront(head,4);
	head=pushFront(head,3);
	head=pushFront(head,2);
	print(head);
	head=InsertElementInSortedList(head,10);
	print(head);

}
