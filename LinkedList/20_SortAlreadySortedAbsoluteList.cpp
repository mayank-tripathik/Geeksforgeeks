/*
 * Given a linked list which is sorted based on absolute values. Sort the list based on actual values.
 * Examples:
    1. Input :  1 -> -10 
    output: -10 -> 1
    2. Input : 1 -> -2 -> -3 -> 4 -> -5 
    output: -5 -> -3 -> -2 -> 1 -> 4 
    3. Input : -5 -> -10 
    Output: -10 -> -5
 * A simple solution can be traversing list and checking for each node. If it is out of order, place it at correct place.
 * This is nothin but insertion sort for linked list. TC:O(n^2)
 * Another solution is to sort the entire list,using merege sort: TC:(nlogn). 
 * Efficient solution: An important observation is, all negative elements are present in reverse order. 
 * So we traverse the list, whenever we find an element that is out of order, we move it to the front of linked list. 
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
node* reverse(node * head){
		node* temp=head;
		// Maintaining 3 pointers in list
		// 1-->2-->3, then previous points to 1, current points to 2 and next points to 3
		// This allows us to make line 1-->2 reverse with ease
		node* previous,*current,*nxt;
		// Initializing three pointers values
		previous=NULL;
		current=head;
		nxt=head;
		while(nxt){
			// nxt is always one step ahead to current
			nxt=current->next;
			// This will change 1-->2-->3 to 1<--2-->3
			// All three pointers are then moved further one by one in such a way that no link is broken
			current->next=previous;
			previous=current;
			current=nxt;
		}
		// At last, previous will point to last Node, hence make it as head
		return previous;
}

// Following function used two dummy node one for positive and negatives list
node* sortAlreadySortedOfAbsolutes(node * head){
	// Create dummy nodes
	node* dummyPositive=new node(1);
	node* dummyNegative=new node(-1);
	// positive and negative will traverse th epositive and negative list
	node *positive=dummyPositive,*negative=dummyNegative;
	// while list has elements
	while(head){
		// If element is +ve
		if(head->value>0){
			// append it to positive list
			positive->next=head;
			// advance positive
			positive=positive->next;
		}
		else{
			// append it to negative list
			negative->next=head;
			// advance negative
			negative=negative->next;
		}
		head=head->next;
	}
	positive->next=NULL;
	negative->next=NULL;
	// if dummynode negative has not null, means atleast one negative present
	if(dummyNegative->next){
		// store the head of negative list, this head will be tail when list is reverse, which will further help
		// in attaching positive list to it
		negative=dummyNegative->next;
		// reverse negative list
		dummyNegative->next=reverse(dummyNegative->next);
		// attach positive list to tail of negative list
		negative->next=dummyPositive->next;
	}
	// If list has atleast one negative element, head is attached to next of dummy ngative otherwise head is
	// attached to dummy positive
	head=dummyNegative->next?dummyNegative->next:dummyPositive->next;
	// return modified head
	return head;
}

node* sortAlreadySortedOfAbsolutesMethod2(node ** head){
	if(*head==NULL)
		return;
	// prev will always point to previous node of cuurent node
	// prev is intially first node, current second node
    node* prev = (*head);
    node* curr = (*head)->next;
    while (curr != NULL)
    {
    	// Since list is sorted in ascending order, if any case arise where current node value is less
    	// than previous node value means current node is negative
        if (curr->value < prev->value)
        {
        	// hence advance previous pointer to next of next node. Note that we have not lost the track
        	// of negative value node that has to be shifted to front. It is already stored in current
            prev->next = curr->next;
            // move current to front
            curr->next = (*head);
            // Make current new head
            (*head) = curr;
            // change current to previous, and current will be advances to next in the last statement(after else)
            curr = prev;
        }
        // else ust advance previous and current
        else
            prev = curr;
        curr = curr->next;
    }
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
	//list=sortAlreadySortedOfAbsolutesMethod2(list);
	sortAlreadySortedOfAbsolutesMethod2(&list);
	print(list);
}
