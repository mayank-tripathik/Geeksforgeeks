/*
 * Given a singly linked list of characters, write a function that returns true if the given list is palindrome, else false.
 * We can use stack to check palindrome by first pushing all elements. We will then traverse the list again. 
 * For every visited node, pop a node from stack and compare data of popped node with currently visited node.
 * If all nodes matched, then return true, else false.
 * This will take O(n) TC, but also requires extra O(n) space
 * We can check palindrome in O(n) TC, and O(1) extra space also
 * This method takes O(n) time and O(1) extra space.
 * Idea is to get the middle of the linked list. Then Reverse the second half of the linked list.
 * Check if the first half and second half are identical.
 * At last we will construct the original linked list by reversing the second half again and attaching it back to the first half
 * To divide the list in two halves,we can use slow and fast pointer method
 * When number of nodes are even, the first and second half contain exactly half nodes. The challenging thing in this method is 
 * to handle the case when number of nodes are odd. We don’t want the middle node as part of any of the lists as we are going 
 * to compare them for equality. For odd case, we use a separate variable ‘midnode’. 
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

// Usual reverse function that returns the new head after reversing the list
node* reverse(node* head){
	node* temp=head;
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

// Function that compare if two equal size lists are same i.e correponding elements are equal
bool compareString(node* head1, node* head2){
	while(head1 && head2){
		if(head1->value!=head2->value)
			return false;
		head1=head1->next;
		head2=head2->next;
	}
	return true;
}

// function that returns true is list is a palindrome
bool isPalindrome(node* head){
	// list is empty or has one element, it is palindrome
	if(head==NULL || head->next==NULL)
		return true;
	// usual slow and fast pointers to find out the middle
	// prevSlow will point to middle of linked list, used to attach second half list later with the first half
	node* slow,*fast,*prevSlow,*middle=NULL;
	slow=fast=head;
	prevSlow=NULL;
	while(fast && fast->next){
		prevSlow=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	// At this point, slow is pointing to middle element, prevSlow is pointing to node behind slow
	// What fast is pointing to depends on whether list length was odd or even. 
	// For odd length linked list, fast points to last element. In case of even length list, it points to NULL
	// So if we check if fast is not NULL, we are sure list is even odd length
	// If list is odd length, middle element need not to be compared. so we store it in pointer named middle and
	// advance slow pointer which is pointing to middle to next element
	if(fast!=NULL){
		middle=slow;
		slow=slow->next;
	}
	// prevSlow's next is made NULL, so that two list are now well seperated for comparison
	prevSlow->next=NULL;
	// last half of list is reversed
	slow=reverse(slow);
	// two list are compared to see if their corresponding elements are equal,and store the result in 
	// boolean varible
	bool palindrome=compareString(head,slow);
	// Steps now are aimed at storing the original list
	slow=reverse(slow);
	// both list are ready to merge again, we just need to check if middle element has to attached too
	if(middle){
		// attach next of middle to slow
		middle->next=slow;
		// attach first half to middle
		prevSlow->next=middle;
	}
	// if middle is NULL, means list was even, hence just attach first half to second half
	else
		prevSlow->next=slow;
	// return result
	return palindrome;
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
	if(isPalindrome(list))
		cout<<"List is a palindrome\n";
	else
		cout<<"List is not a palindrome\n";
}
