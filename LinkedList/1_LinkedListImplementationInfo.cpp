#include<iostream>
using namespace std;

class ListNode{
public:
	int value;
	ListNode* next;
public:
	ListNode(int x):value(x),next(NULL){}
};

class LinkedList{
	ListNode* head;
public:
	LinkedList():head(NULL){}
	void push_front(int x){
		ListNode* temp=new ListNode(x);
		temp->next=head;
		head=temp;
	}
	void print(){
		if(!head)
			cout<<"List is empty\n";
		else{
			ListNode* temp=head;
			while(temp){
				cout<<temp->value<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
	}
	int getSizeRecursiveHelper(ListNode*);
	int getSizeRecursive();
	int getSizeIterative();
	bool findElementRecursiveHelper(ListNode*,int);
	bool findElementRecursive(int);
	bool findElementIterative(int);
	void swapNodes(int, int);
	ListNode* getNthNodeIterative(int);
	ListNode* getNthNodeRecursiveHelper(ListNode*,int);
	ListNode* getNthNodeRecursive(int);
	void getMiddle();
	void getNthFromEnd(int);
	void deleteList();
	void numberOftimesElementOccurs();
};

int LinkedList::getSizeRecursiveHelper(ListNode* temp){
	if(!temp)
		return 0;
	else
		return (1+getSizeRecursiveHelper(temp->next));
}

int LinkedList::getSizeRecursive(){
	ListNode *temp=head;
	return getSizeRecursiveHelper(temp);
}

int LinkedList::getSizeIterative(){
	ListNode* temp=head;
	int size=0;
	while(temp){
		temp=temp->next;
		size++;
	}
	return size;
}

bool LinkedList::findElementRecursiveHelper(ListNode* temp, int x){
	if(!temp)
		return false;
	else if(temp->value==x)
		return true;
	else
		return findElementRecursiveHelper(temp->next,x);
}

bool LinkedList::findElementRecursive(int x){
	ListNode *temp=head;
	return findElementRecursiveHelper(temp,x);
}

bool LinkedList::findElementIterative(int x){
	ListNode* temp=head;
	while(temp){
		if(temp->value==x)
			return true;
		temp=temp->next;
	}
	return false;
}

ListNode* LinkedList::getNthNodeIterative(int N){
	ListNode* temp=head;
	while(N-- && temp){
		temp=temp->next;
	}
	return temp;
}

ListNode* LinkedList::getNthNodeRecursiveHelper(ListNode* temp,int N){
	if(!temp)
		return NULL;
	else if(N==0)
		return temp;
	else
		return getNthNodeRecursiveHelper(temp->next,N-1);
}

ListNode* LinkedList::getNthNodeRecursive(int N){
	return getNthNodeRecursiveHelper(head,N);
}
void LinkedList::getMiddle(){
	ListNode *slow=head,*fast=head;
	while(fast->next && fast->next->next){
		slow=slow->next;
		fast=fast->next->next;
	}
	if(!slow)
		cout<<"List Empty! No middle.\n";
	else
		cout<<"Middle element is:"<<slow->value<<endl;
}
void LinkedList::getNthFromEnd(int N){
	ListNode *slow=head,*fast=head;
	int n=N;
	while(N--){
		fast=fast->next;
	}
	while(fast){
		slow=slow->next;
		fast=fast->next;
	}
	cout<<n<<"th node from end:"<<slow->value<<endl;
}

void LinkedList::deleteList(){
	while(head){
		ListNode* temp=head;
		head=head->next;
		delete temp;
	}
}
int main(){
	LinkedList mylist;
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		mylist.push_front(x);
	}
	mylist.print();
	cout<<mylist.getSizeRecursive()<<endl;
	cout<<mylist.getSizeIterative()<<endl;
	cout<<mylist.findElementRecursive(3)<<endl;
	cout<<mylist.findElementIterative(12)<<endl;
	if(ListNode* found=mylist.getNthNodeIterative(2))
		cout<<"2nd node is:"<<found->value<<endl;
	else
		cout<<"2nd Index is out of bound/undeflow\n";
	if(ListNode* found=mylist.getNthNodeRecursive(6))
		cout<<"6th node is:"<<found->value<<endl;
	else
		cout<<"6th Index is out of bound/undeflow\n";
	mylist.getMiddle();
	mylist.getNthFromEnd(6);
	mylist.deleteList();
	mylist.print();

}
