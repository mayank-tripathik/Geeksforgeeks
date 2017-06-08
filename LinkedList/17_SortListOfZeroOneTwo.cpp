/*
 * Given a linked list of 0s, 1s and 2s, sort it.
 * We can solve it using two approaches, either by counting or by pointer manipulation
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

// This method is easy, and very simple to implement even if 0 or 1 or 2 are not at all present in list
// Only drawback is that it traverses list twice
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

// This method uses three head pointers, each to 0,1 and 2 respectively
// When it encounters 0,1 or 2 it accordingly append it to respective pointer using their rear pointers
// One drawback is that in case of no 0 or 1, many edge cases are to be considered
// Benefit is that list is sorted in single traversal
node* sortOneZeroTwoPointerManipulation(node* head){
	node *oneHead,*twoHead,*zeroHead;
	node *oneRear,*twoRear,*zeroRear;
	oneHead=twoHead=zeroHead=NULL;
	oneRear=twoRear=zeroRear=NULL;
	while(head){
		cout<<head->value<<endl;
		if(head->value==1){
			if(oneHead==NULL){
				oneHead=oneRear=head;
				cout<<"onehead is set to:"<<head->value<<endl;
			}
			else{
				oneRear->next=head;
				oneRear=oneRear->next;
			}
		}
		else if(head->value==0){
			if(zeroHead==NULL){
				zeroHead=zeroRear=head;
				cout<<"zeroHead is set to:"<<head->value<<endl;
			}
			else{
				zeroRear->next=head;
				zeroRear=zeroRear->next;
			}
		}
		else if(head->value==2){
			if(twoHead==NULL){
				twoHead=twoRear=head;
				cout<<"twoHead is set to:"<<head->value<<endl;
			}
			else{
				twoRear->next=head;
				twoRear=twoRear->next;
			}
		}
		head=head->next;
	}
	if(zeroRear!=NULL)
		zeroRear->next=NULL;
	if(oneRear!=NULL)
		oneRear->next=NULL;
	if(twoRear!=NULL)
		twoRear->next=NULL;
	if(zeroRear)
		zeroRear->next=oneHead;
	if(oneRear)
		oneRear->next=twoHead;
	return zeroHead;
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
	list=sortOneZeroTwoCounting(list);
	print(list);
}
