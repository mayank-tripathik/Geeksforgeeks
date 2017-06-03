/*
 * Find a point where two singly linked lists meet
 * TC: O(n). Extra space:O(1)
 */

#include<iostream>
#include<cstdlib>
using namespace std;
struct ListNode{
	int value;
	ListNode* next;
};

ListNode* newNode(int x){
	ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
	temp->next=NULL;
	temp->value=x;
	return temp;
}

ListNode* pushFront(ListNode* head,int x){
	ListNode* temp=newNode(x);
	temp->next=head;
	head=temp;
	return head;
}
void print(ListNode* head){
	cout<<"List:";
	ListNode* temp=head;
	while(temp){
		cout<<temp->value<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

// In case of lists having unequal length, this function will be envoked which works by skipping
// extra nodes in longer lists and then making comparisons
ListNode* checkCommon(ListNode *longer, ListNode* smaller, ListNode* difference){
	int count=0;
	// This will count how long is longer list than smaller list
	// Once we get this count, we will skip those nodes at starting on traversing longer list later
	while(difference){
		count++;
		difference=difference->next;
	}
	// Skip count number of nodes
	// This will effectively makes length of both list equal
	while(count--)
		longer=longer->next;
	// Now compare values of both till they get equal, otherwise lists has no intersection points
	while(longer && smaller){
		if(longer->value==smaller->value)
			return longer;
		longer=longer->next;
		smaller=smaller->next;
	}
	return NULL;
}

// This function will return answer if list are of equal length, otherwise it will calculate
// the differences in length of two list and makes use of above funtion to return answer
ListNode* findIntersection(ListNode* head1, ListNode* head2){
	ListNode* temp1,*temp2;
	temp1=head1;
	temp2=head2;
	// Move pointers of both list till one list is empty
	while(temp1 && temp2){
		// While traversing, return if intersection node is found
		if(temp1->value==temp2->value)
			return temp1;
		temp1=temp1->next;
		temp2=temp2->next;
	}
	// Means first list is longer than second as temp1 pointer yet not reaches NULL
	if(temp1)
		return checkCommon(head1,head2,temp1);
	// Means second list is longer than first as temp2 pointer yet not reaches NULL
	else
		return checkCommon(head2,head1,temp2);
}
int main(){
	int n,m;
	cin>>n>>m;
	ListNode* head1=NULL,*head2=NULL;
	while(n--){
		int x;
		cin>>x;
		head1=pushFront(head1,x);
	}
	while(m--){
		int x;
		cin>>x;
		head2=pushFront(head2,x);
	}
	print(head1);
	print(head2);
	ListNode* intersectionPoint=findIntersection(head1,head2);
	if(intersectionPoint)
		cout<<"IntersectionPoint is:"<<intersectionPoint->value<<endl;
	else
		cout<<"No intersection\n";

}
