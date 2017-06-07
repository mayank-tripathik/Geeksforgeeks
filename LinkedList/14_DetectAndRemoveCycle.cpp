/*
 * Given a linked list with cycle, write a program to detect and remove cycle in linked list
 * Floyd cycle detection algorithm can be used to detect cycle,and then can be removed by finding the start of the cycle
 * start of the cycle can be found by placing slow pointer at head and fast pointer at meet point and then moving both 
 * by one step. They meet at the start of the cycle
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
node* createCycle(node* head){
	node *temp=head;
	node *temp1=temp->next;
	while(temp->next)
		temp=temp->next;
	temp->next=temp1;
	cout<<"cycle is creayed from "<<temp->value<<" to "<<temp->next->value<<endl;
	return head;
}

// this function will check if cycle exists, if not exist, it return false
// Otherwise it returns true and breaks the cycle
bool detectAndRemoveLoop(node *head)
{
	if(head==NULL)
		return false;
	// Slow and fast pointers, where slow moves by one step and fast moves by two steps
	node *slow = head;
    node *fast = head->next;
    // check for loop, loop exists if slow is equal to fast at any point
    while(fast && fast->next){
    	if(slow==fast)
    		break;
    	slow=slow->next;
    	fast=fast->next->next;
    }
    //Loop detecting condition check 
    if(slow == fast)
    {
    	// Make slow pointer pointing to head and now move both pointer
    	slow=head;
    	// If slow is equal to fast->next, means slow is the starting point of loop 
    	while(slow!=fast->next){
    		slow=slow->next;
    		fast=fast->next;
    	}
    	// Make fast->next, which is pointing to slow here to NULL to break the loop
    	fast->next=NULL;
    	return true;
    }
    else
    	return false;
}

int main(){
	int n,k;
	cin>>n;
	node *list=NULL;
	while(n--){
		int x;
		cin>>x;
		list=pushFront(list,x);
	}
	print(list);
	list=createCycle(list);
	cout<<detectAndRemoveLoop(list)<<endl;
	print(list);
}
