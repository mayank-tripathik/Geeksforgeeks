/*
 * Given a linked list, write a function to reverse every k nodes (where k is an input to the function).
 * Example:
 *     Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
 *     Output:  3->2->1->6->5->4->8->7->NULL. 
 *     Inputs:   1->2->3->4->5->6->7->8->NULL and k = 5
 *     Output:  5->4->3->2->1->8->7->6->NULL.
 * Both recursive and iterative funtion can be used as follows
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

node* revereseLinkedListEachKIterative(node* head, int k){
	// This pointer is used to maintain rear of the previously reverse list
	// So that its next can be made pointed to head of current reversed list
	node *prevRear=NULL;
	// Three ususal pointers of reverse operation
	node *previous,*current,*nxt;
	nxt=current=head;
	while(nxt){
		// This will maintain rear of reversed list which if formed from reverse of current list
		// This pointer is later assigned to prevRear
		node *newRear=current;
		// Usual reverse operation, except one change of reversing nodes only upto k size
		previous=NULL;
		nxt=current;
		int groupSize=k;
		while(nxt && groupSize--){
			nxt=nxt->next;
			current->next=previous;
			previous=current;
			current=nxt;
		}
		// At this point previous will point to head of the sublist
		// Therefore make previous sublist rear pointer pointing to it, if it is not NULL
		if(prevRear)
			prevRear->next=previous;
		// If it is null, means it is the first sublist, hence make it previous as head of the whole list
		else
			head=previous;
		// change previous rear to currrent rear
		prevRear=newRear;

	 }
	return head;
}

node *revereseLinkedListEachKRecursive(node *head, int k)
{
    struct node* current = head;
    struct node* next = NULL;
    struct node* prev = NULL;
    int count = 0;   
     
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
     
    /* next is now a pointer to (k+1)th node 
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
    if (next !=  NULL)
       head->next = revereseLinkedListEachKRecursive(next, k); 
 
    /* prev is new head of the input list */
    return prev;
}

int main(){
	int n,k;
	cin>>n>>k;
	node *list=NULL;
	while(n--){
		int x;
		cin>>x;
		list=pushFront(list,x);
	}
	print(list);
	list=revereseLinkedListEachKRecursive(list,k);
	print(list);
	list=revereseLinkedListEachKIterative(list,k);
	print(list);
}
