/*
 * Given a linked list of co-ordinates where adjacent points either form a vertical line or a horizontal line. 
 * Delete points from the linked list which are in the middle of a horizontal or vertical line.
 * Examples:
    Input:  (0,10)->(1,10)->(5,10)->(7,10)
                                  |
                                (7,5)->(20,5)->(40,5)
    Output: Linked List should be changed to following
        (0,10)->(7,10)
                  |
                (7,5)->(40,5) 
    
    The given linked list represents a horizontal line from (0,10) 
    to (7, 10) followed by a vertical line from (7, 10) to (7, 5), 
    followed by a horizontal line from (7, 5) to (40, 5).

    Input:     (2,3)->(4,3)->(6,3)->(10,3)->(12,3)
    Output: Linked List should be changed to following
        (2,3)->(12,3) 
    There is only one vertical line, so all middle points are removed.
 * We can see if three consecutive points has either same x values, or same y values, middle point is retundant in segments
 * We can keep removing such middle nodes by traversing list.
 * TC:O(n)
 */

#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int x;
	int y;
public:
	node * next;
	node(int _x, int _y){
		x=_x;
		y=_y;
		next=NULL;
	}
};

node* pushFront(node *head,int x, int y){
	node* temp=new node(x,y);
	temp->next=head;
	head=temp;
	return head;
}

void print(node *head){
	cout<<"List:";
	node* temp=head;
	while(temp){
		cout<<temp->x<<","<<temp->y<<"  ";
		temp=temp->next;
	}
	cout<<endl;
}

node* deleteRetundantMiddle(node* head){
	// if list has either no element or one element, nothing to do
	if(head==NULL || head->next==NULL)
		return head;

	// first will point to first of the line type(vertical or horizontal)
	node* first=head;
	// middle will point to next of first
	node *middle=first->next;
	// current will take account each node after middle, to check whether node pointed by middle
	// has to be deleted
	node* current=middle->next;
	while(current){
		// if three consecutive pointers make either horizontal line or vertical, middle one is always
		// retundant
		if((first->x==middle->x && middle->x==current->x) || (first->y==middle->y && middle->y==current->y)){
			// delete middle node and advance middle and current pointers(done by statements after else)
			first->next=current;
			delete(middle);
		}
		// else advance all three pointers to next places
		else
			first=middle;
		middle=current;
		current=current->next;
	}
	// return modified list
	return head;
}
int main(){
	int n;
	cin>>n;
	node *list=NULL;
	while(n--){
		int x,y;
		cin>>x>>y;
		list=pushFront(list,x,y);
	}
	print(list);
	list=deleteRetundantMiddle(list);
	print(list);
}
