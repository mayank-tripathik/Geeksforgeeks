/*
 * You are given a Double Link List with one pointer of each node pointing to the next node just like in a single link list. 
 * The second pointer however CAN point to any node in the list and not just the previous node. 
 * Write a program in O(n) time to duplicate this list. That is, write a program which will create a copy of this list.
 * An O(n) space algorithm would be by storing the status of original list in array. Then creating new list using next pointers
 * and attaching this list to original list by modifying next pointer of original list. Random of clone list is then found using
 * transitive link structure formed. TC:O(n), but with extra space O(n)
 * Algorithm without extra space is implemented below
 * Create the copy of each node and insert it after original node in original list. Then modify random pointer of newly inserted
 * node using : original->next->random= original->random->next;
 * This works because original->next is nothing but copy of original and Original->random->next is nothing but copy of random.
 * Now restore the original and copy linked lists in this fashion in a single loop.
 * TC:O(n)
 */


#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int value;
public:
	node * next;
	node* random;
	node(int x){
		value=x;
		random=NULL;
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
		cout<<"Data:"<<temp->value<<" Random:"<<temp->random->value<<endl;
		temp=temp->next;
	}
	cout<<endl;
}

node* cloneLinkedList(node* head){
	// This pointer will give the head of the clonedlist
	node* clonedListHead=new node(1);
	// Help in traversing the cloned list
	node* clonedList=clonedListHead;
	// Used to traverse the given list
	node* temp=head;
	// make a clone of each node and attach it after the original node
	while(temp){
		node *newnode=new node(temp->value);
		newnode->next=temp->next;
		temp->next=newnode;
		temp=newnode->next;
	}
	// start from the list again, for each clone node adjust its random pointer using the random link of its
	// original node. 
	temp=head;
	while(temp){
		// if random pointer of original node is not empty, then only assign its value to cloned node's random
		// field, otherwise make it NULL
		temp->next->random=temp->random?temp->random->next:NULL;
		// Advance temp to next original node
		temp=temp->next->next;
	}
	// Again start from head and detatch the clone list from original list by using cloneList pointer
	temp=head;
	while(temp){
		clonedList->next=temp->next;
		clonedList=clonedList->next;
		temp->next=temp->next->next;
		temp=temp->next;
	}
	// Finish the cloneList by ending it with NULL
	clonedList->next=NULL;
	// return head of clone list
	return clonedListHead->next;
}

int main(){
	node* start = new node(1);
	start->next = new node(2);
	start->next->next = new node(3);
	start->next->next->next = new node(4);
	start->next->next->next->next = new node(5);
	start->random = start->next->next;
    // 2's random points to 1
	start->next->random = start;
    // 3's and 4's random points to 5
	start->next->next->random =start->next->next->next->next;
	start->next->next->next->random =start->next->next->next->next;
    // 5's random points to 2
	start->next->next->next->next->random = start->next;
	node *clonedList=cloneLinkedList(start);
	cout << "Original list : \n";
	print(start);
	cout << "\nCloned list : \n";
	print(clonedList);
}
