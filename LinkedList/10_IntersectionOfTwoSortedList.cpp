/*
 * Given two lists sorted in increasing order, create and return a new list representing the intersection of the two lists. 
 * The new list should be made with its own memory — the original lists should not be changed.
 * Example, let the first linked list be 1->2->3->4->6 and second linked list be 2->4->6->8, 
 * Then intersection list will be 2->4->6.
 * Following are th iterative and recursive solution
 * Complexity:O(n)
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

node* intersectionOfListIterative(node *current1, node *current2){
	node *intersect=NULL;
	node *current=intersect;
	while(current1 && current2){
		if(current1->value==current2->value){
			node *temp=new node(current1->value);
			if(current==NULL){
				intersect=current=temp;
			}
			else{
				current->next=temp;
				current=current->next;
			}
			current1=current1->next;
			current2=current2->next;
		}
		else if(current1->value<current2->value){
			current1=current1->next;
		}
		else{
			current2=current2->next;
		}
	}
	return intersect;
}

node* intersectionOfListRecursive(node *a, node *b)
{
    if (a == NULL || b == NULL)
        return NULL;
    if (a->value < b->value)
        return intersectionOfListRecursive(a->next, b);
    if (a->value > b->value)
        return intersectionOfListRecursive(a, b->next);
    node *temp = new node(a->value);
    temp->next = intersectionOfListRecursive(a->next, b->next);
    return temp;
}

int main(){
	int n,m;
	cin>>n;
	node *list1=NULL,*list2=NULL;
	while(n--){
		int x;
		cin>>x;
		list1=pushFront(list1,x);
	}
	cin>>m;
	while(m--){
		int x;
		cin>>x;
		list2=pushFront(list2,x);
	}
	print(list1);
	print(list2);
	node *intersect=intersectionOfListIterative(list1,list2);
	node *intersect=intersectionOfListRecursive(list1,list2);
	print(intersect);
	return 0;
}

