/*
 * Given a linked list of 0s, 1s and 2s, sort it.
 * We can solve it using two approaches, either by counting or by pointer manipulation
 * Counting method is good if we are allowed to change the node's values. One drawback is it traverses list twice, but is simple.
 * Pointer manipulation is tricky, but is efficient. It traverses list once only and is preferred if we are not allowed to
 * change value of nodes. Dummy nodes are used to handle edge cases i.e if 0 or 1 are not present at all
 * TC: O(n) both
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


// Count number of 0,1 and 2s and then populate them from start of list
node* sortOneZeroTwoCounting(node *head){
	node*temp=head;
	int countZero=0,countOne=0,countTwo=0;
	while(head){
		if(head->value==0)
			countZero++;
		else if(head->value==1)
			countOne++;
		else if(head->value==2)
			countTwo++;
		head=head->next;
	}
	head=temp;
	while(countZero--){
		temp->value=0;
		temp=temp->next;
	}
	while(countOne--){
		temp->value=1;
		temp=temp->next;
	}
	while(countTwo--){
		temp->value=2;
		temp=temp->next;
	}
	return head;
}

// This method uses three pointers, each to 0,1 and 2 respectively
// When it encounters 0,1 or 2 it accordingly append it to respective pointer using their rear pointers
// Dummy pointers are used to ease the cases where some element are not present at all
node* sortOneZeroTwoPointerManipulation(node* head){
	// Three dummy nodes, which will be later deleted, acts as a heads of three lists of 0s,1s and 2s
	// If their next is NULL at then end, we can be sure that there are no elements of their type
	// For exaplme if oneDummy's next is NULL at the end, it means no value of 1 is present in LL
	node* zeroDummy=new node(0);
	node* oneDummy=new node(0);
	node* twoDummy=new node(0);
	// The three rear pointer, always points to end of corresponding values list
	// They are used to add nodes to corresponding list as current is traversed
	node *zeroRear=zeroDummy, *oneRear=oneDummy, *twoRear=twoDummy;
	// Used to traverse the whole list
	node *curr=head;
	while(curr)
	{
		// If current is 0, add it to zero list using rear pointer of zero list
		if(curr->value == 0)
		{
			zeroRear->next = curr;
			zeroRear = zeroRear->next;
		}
		// If current is 1, add it to one list using rear pointer of one list
		else if(curr->value == 1)
		{
			oneRear->next = curr;
			oneRear = oneRear->next;
		}
		// If current is 2, add it to two list using rear pointer of two list
		else
		{
			twoRear->next = curr;
			twoRear = twoRear->next;
		}
		// advance current pointer to next element
		curr = curr->next;
	}
	// make next pointer of one list to point to next pointer of dummy list
	// if there would have been no 1, oneRear would be same as oneDummy and its next would be pointing to next
	// of twoDummy. If there would have been no 2, next of twoDummy would be NULL, and NULL would be assigned
	// to last node of 1, which is fine
	oneRear->next = twoDummy->next;
	// make last node of two list pointing to NULL.
	twoRear->next = NULL;
	// if one list has no one, that is oneDummy next value is NULL, point next of lastnode of zero list
	// to firstnode of two list, otherwise point it to first node of one list
	zeroRear->next = (oneDummy->next) ? (oneDummy->next): (twoDummy->next);
	// new head is next of zerodummy
	head = zeroDummy->next;
	// delete dummy nodes
	delete zeroDummy;
	delete oneDummy;
	delete twoDummy;
	return head;
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
	list=sortOneZeroTwoPointerManipulation(list);
	print(list);
}
