/*
 * Given a liked list and a key to be deleted. Delete last occurrence of key from linked. The list may have duplicates.
 * Examples:
       Input:   1->2->3->5->2->10, key = 2
       Output:  1->2->3->5->10 
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

// Following function used dummy node to ease the handle od edge cases i.e where last and first nodes are to be deleted
node* deleteLastOccurenceOfItem(node * head, int item){
	// create a dummynode and attach head of list to it
	node *dummyNode=new node(-1);
	dummyNode->next=head;
	// lastocc will point to the previous of last occurence of given item
	// nextOcc will help in finding next such lastOcc
	node* lastOcc,*nextOcc;
	// Intialization of both
	lastOcc=NULL;
	nextOcc=dummyNode;
	// While list has element
	while(nextOcc->next){
		// If value of next node is equal to given item, make it lastOcc, and check further
		if(nextOcc->next->value==item){
			lastOcc=nextOcc;
		}
		nextOcc=nextOcc->next;
	}
	// If lastOcc is NULL, means no such item is found
	if(lastOcc==NULL)
		cout<<"item not found\n";
	// Item found
	else{
		// since lastOcc points to the node to be deleted, store its next 
		node* temp=lastOcc->next;
		// make lastOcc point to next of next node
		lastOcc->next=temp->next;
		// If node to be deleted is head, make next of it the new head
		if(temp==head){
			head=head->next;
		}
		// delete temp
		delete(temp);
	}
	return head;
}

int main(){
	int n,item;
	cin>>n>>item;
	node *list=NULL;
	while(n--){
		int x;
		cin>>x;
		list=pushFront(list,x);
	}
	print(list);
	list=deleteLastOccurenceOfItem(list,item);
	print(list);
}
