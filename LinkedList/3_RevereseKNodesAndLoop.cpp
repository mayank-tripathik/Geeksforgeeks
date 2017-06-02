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
		if(head==NULL){
			cout<<"List is empty\n";
			return;
		}
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
		nxt=current;
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
	void reverseIterativeK(int k){
		ListNode* temp=head;
		// rear and newrear is used to keep track of rear of previous list and rear of current list
		// 1<--2<--3-->4-->5-->6. In this scenario rear is 1 and newrear will be 4
		// rear of previous list is used to attach the head of next reverse list to previous list
		ListNode* previous,*current,*nxt,*rear,*newrear;
		current=head;
		rear=current;
		nxt=head;
		int counter=0;
		while(nxt){
			counter++;
			previous=NULL;
			newrear=current;
			while(k && nxt){
				nxt=current->next;
				current->next=previous;
				previous=current;
				current=nxt;
				k--;
			}
			k=3;
			if(counter==1){
				head=previous;
				rear->next=NULL;
			}
			else{
				rear->next=previous;
				rear=newrear;
			}
			//print();
		}
	}
	void createLoop(){
		ListNode *rear=head;
		while(rear->next!=NULL)
			rear=rear->next;
		ListNode* temp=head->next->next;
		rear->next=head;

	}
	bool hasLoop(){
		ListNode* slow,*fast;
		slow=fast=head;
		bool loop=false;
		while(fast && fast->next){
			slow=slow->next;
			fast=fast->next->next;
			if(slow->value==fast->value){
				loop=true;
				break;
			}
		}
		return loop;
	}
};
int main(){
	LL mylist;
	mylist.pushFront(9);
	mylist.pushFront(8);
	mylist.pushFront(7);
	mylist.pushFront(6);
	mylist.pushFront(5);
	mylist.pushFront(4);
	mylist.pushFront(3);
	mylist.pushFront(2);
	mylist.pushFront(1);
	mylist.print();
	//mylist.reverseIterative();
	//mylist.print();
	//mylist.reverseRecursive();
	//mylist.print();
	//mylist.reverseIterativeK(3);
	//mylist.print();
	mylist.createLoop();
	if(mylist.hasLoop())
		cout<<"List has loop\n";
	else
		cout<<"List has no loop\n";

}
