/*
 * Rearrange a linked list in such a way that all odd position nodes are together and all even positions node are together
 * Examples:
    Input:   1->2->3->4
    Output:  1->3->2->4
    Input:   10->22->30->43->56->70
    Output:  10->30->56->22->43->70
 * Next node of odd(if exist) will be even node, and vice verse. Thus we can alternatively connect them.
 * Below program maintains two pointers ‘odd’ and ‘even’ for current nodes at odd and even positions respectively. 
 * We also store first node of even linked list so that we can attach the even list at the end of odd list after all 
 * odd and even nodes are connected together in two different lists.
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

node* segregateOddAndEvenNodes(node* head){
	if(head==NULL || head->next==NULL)
		return head;
	// odd and even will traverse odd and even list respectively
	// while even head will be head to even list, which is used in attaching odd list to even later
	node* odd,*even,*evenHead;
	// initialzing both odd and even pointer to intial odd and even place nodes i.e 1st and 2nd nodes repectively
	odd=head;
	even=evenHead=head->next;
	// while list has even nodes or next to even node exists
	while(even && even->next){
		// make next of odd to next of even
		odd->next=even->next;
		// advance odd pointer 
		odd=odd->next;
		// make next of even to next of odd
		even->next=odd->next;
		// advance even pointer
		even=even->next;
	}
	// At this point odd points to last node of odd list, hence attach it to even list through head of even list
	odd->next=evenHead;
	//return modified head
	return head;

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
	list=segregateOddAndEvenNodes(list);
	print(list);
}
