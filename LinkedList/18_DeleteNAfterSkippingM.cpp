/*
 * Given a linked list and two integers M and N. 
 * Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same till end of the linked list.*
 * Dummy nodes is reduced to reduce the complexity of edge cases
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

node* deleteNAfterM(node* head, int N, int M){
	// dummynode is a dummy start node, if its next is NULL in the end, means nothing remaining in list
	node *dummyNode=new node(-1);
	dummyNode->next=head;
	// previous is initially dummynode
	node* previous=dummyNode;
	// current is initially head
	node* current=head;
	// while current is not NULL
	while(current){
		int skip=M;
		// skip M nodes or break if no node is remaining
		while(current && skip--){
			previous=current;
			current=current->next;
		}
		int toDelete=N;;
		// delete N nodes or break if node is remaining
		while(current && toDelete--){
			previous->next=current->next;
			delete(current);
			current=previous->next;
		}
	}
	// If next of dummyNode is NULL, means nothing remaining, hence return NULL
	if(dummyNode->next)
		return dummyNode->next;
	// else head will the next of dummynode
	else
		return NULL;
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
	int N,M;
	cin>>N>>M;
	print(list);
	//list=deleteNAfterM(list,N,M);
	deleteNAfterMRecursive(list,N,M);
	print(list);
}
