/*
 * Given a linked list, reverse it.
 * Both iterative and recursive version are O(n) TC 
 */

#include<iostream>
using namespace std;
class ListNode{
public:
	int value;
	ListNode* next;
public:
	ListNode(int x):value(x),next(NULL){}
};
class LL{
	ListNode* head;
	public:
	LL():head(NULL){}
	void pushFront(int x){
		ListNode* temp=new ListNode(x);
		temp->next=head;
		head=temp;
	}
	void print(){
		cout<<"List: ";
		ListNode* temp=head;
		while(temp){
			cout<<temp->value<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	// Iterative version of list reverse
	void reverseIterative(){
		ListNode* temp=head;
		// Maintaining 3 pointers in list
		// 1-->2-->3, then previous points to 1, current points to 2 and next points to 3
		// This allows us to make line 1-->2 reverse with ease
		ListNode* previous,*current,*nxt;
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
		head=previous;
	}
	// Recursive version of reverse list
	void reverseRecursiveHelper(ListNode* root){
		// If list has one node, make it head and return
		if(root->next==NULL){
			head=root;
			return;
		}
		else{
			// call reverse recursively (till one node left)
			reverseRecursiveHelper(root->next);
			// Suppose 1-->2-->3-->4, then at this point root is pointing to 3 after returning from base case
			// Hence 3->next->next=4->next will result into 1-->2-->3<--4
			root->next->next=root;
			// Make 3->next NULL. This process will eventually leads to NULL<--1<--2<--3<--4.
			root->next=NULL;
		}
	}
	void reverseRecursive(){
		if(!head)
			return;
		ListNode* root=head;
		reverseRecursiveHelper(root);
	}
};
int main(){
	LL mylist;
	mylist.pushFront(6);
	mylist.pushFront(9);
	mylist.pushFront(1);
	mylist.pushFront(8);
	mylist.pushFront(4);
	mylist.print();
	mylist.reverseIterative();
	mylist.print();
	mylist.reverseRecursive();
	mylist.print();

}
