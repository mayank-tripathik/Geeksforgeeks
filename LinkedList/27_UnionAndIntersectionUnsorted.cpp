/*
 * Given two Linked Lists, create union and intersection lists that contain union and intersection of the elements 
 * present in the given lists. Order of elments in output lists doesn’t matter.
 * Example:
   Input:
   List1: 10->15->4->20
   lsit2:  8->4->2->10
   Output:
   Intersection List: 4->10
   Union List: 2->8->20->4->15->10
* O(m*n) solution can be picking each element and see if it is present or not
* Better approach to use merge sort to first sort both list. Linearly scan both sorted lists to get the union and intersection. 
* Sorting take O(mLogm) time and O(nLogn) time for noth list. Last step takes O(m + n) time.
* Good method is to use hashing. 
* For Union (list1, list2), Initialize the result list as NULL and create an empty hash table. Traverse both lists one by one, 
* for each element being visited, look the element in hash table. If the element is not present, then insert the element to 
* result list. If the element is present, then ignore it.
* For Intersection (list1, list2), Initialize the result list as NULL and create an empty hash table. Traverse list1. 
* For each element being visited in list1, insert the element in hash table. Traverse list2, for each element being visited 
* in list2, look the element in hash table. If the element is present, then insert the element to result list. 
* If the element is not present, then ignore it.
* Following code implements the last approach
*  TC:O(m+n), Auxillary space:O(m or n)
*/

#include<iostream>
#include<stdlib.h>
#include <unordered_set>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void push(struct node** head_ref, int new_data);

struct node *getUnion(struct node *head1, struct node *head2)
{
	node* unionListHead=new node();
	node *unionList=unionListHead;
	unordered_set<int> hash;
	while(head1){
		hash.insert(head1->data);
		unionList->next=head1;
		unionList=unionList->next;
		head1=head1->next;
	}
	while(head2){
		if(hash.find(head2->data)==hash.end()){
			unionList->next=head2;
			unionList=unionList->next;
		}
		head2=head2->next;
	}
	return unionListHead->next;
}

node* getIntersection(node* head1, node* head2){
	node* intersectList=new node();
	node* current=intersectList;
	unordered_set<int> hash;
	while(head1){
		hash.insert(head1->data);
		head1=head1->next;
	}
	while(head2){
		if(hash.find(head2->data)!=hash.end()){
			current->next=head2;
			current=current->next;
		}
		head2=head2->next;
	}
	current->next=NULL;
	return intersectList->next;
}

void push (struct node** head_ref, int new_data)
{
	struct node* new_node =
	(struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}


void printList (struct node *node)
{
	while (node != NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
}


int main()
{
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	struct node* intersecn = NULL;
	struct node* unin = NULL;

	push (&head1, 20);
	push (&head1, 4);
	push (&head1, 15);
	push (&head1, 10);

	push (&head2, 11);
	push (&head2, 2);
	push (&head2, 4);
	push (&head2, 8);
	
	printf ("\n First list is \n");
	printList (head1);

	printf ("\n Second list is \n");
	printList (head2);
	
    //intersecn=getIntersection(head1,head2);
	//printf ("\n Intersection list is \n");
	//printList (intersecn);

	unin = getUnion (head1, head2);
	printf ("\n Union list is \n");
	printList (unin);

	return 0;
}
