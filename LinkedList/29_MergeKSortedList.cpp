/*
 * Given K sorted linked lists of size N each, merge them and print the sorted output.
* Example:
  Input: k = 3, n =  4
  list1 = 1->3->5->7->NULL
  list2 = 2->4->6->8->NULL
  list3 = 0->9->10->11
  Output: 
  0->1->2->3->4->5->6->7->8->9->10->11
 * A Simple Solution is to initialize result as first list. Now traverse all lists starting from second list. 
 * Insert every node of currently traversed list into result in a sorted way. Time complexity of this solution is O(N2) 
 * where N is total number of nodes, i.e., N = kn.
 * Another sol: Create new array of size n*k and sort it using merge sort. TC: O(nk Lognk)
 * A Better solution is to use Min Heap based solution which is discussed here for arrays. Time complexity of this 
 * solution would be O(nk Log k)
 * Following program is the implementation divide and Conquer approach. This approach doesn’t require extra space for 
 * heap and works in O(nk Log k)
 * We already know that merging of two linked lists can be done in O(n) time and O(1) space (For arrays O(n) space is required). 
 * The idea is to pair up K lists and merge each pair in linear time using O(1) space. After first cycle, K/2 lists are left 
 * each of size 2*N. After second cycle, K/4 lists are left each of size 4*N and so on. We repeat the procedure until we have 
 * only one list left. 
 * TC :Time Complexity of above algorithm is O(nk logk) as outer while loop in function mergeKLists() runs log k times and 
 * every time we are processing nk elements. 
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

// Merge function for two sorted lists
node* mergeTwoSortedList(node* head1, node* head2){
	node* mergeHead=new node(1);
	node* mergeRear=mergeHead;
	while(head1 && head2){
		if(head1->value<head2->value){
			mergeRear->next=head1;
			head1=head1->next;
		}
		else{
			mergeRear->next=head2;
			head2=head2->next;
		}
		mergeRear=mergeRear->next;
	}
	mergeRear->next=head1?head1:head2;
	return mergeHead->next;
}

// Function that merge two list at a time using above subroutine.
node* mergeKSortedList(vector<node*> &arr, int k){
	// This variable keeps tracks of the index of the last unsorted list among the k lists
	int last=k-1;
	// Till all lists are sorted
	while (last != 0)
	{
    	// It picks two lists, one at the start index, and other at the last list which is unsorted
    	// and it keeps picking the two in similar manner till one list reamining (in case of odd numer of list)
    	// or no list remains(in case of even lists). In both cases, i < j when all two picks are done 
		int i = 0, j = last;
		while (i < j)
		{
        	// merge the two chosen lists using merge procedure for two lists, and assign their head to the first one
        	// In this way if there are k sublist in begining, after next iteration, first k/2 list will be the updated
        	// one, by merging them with last k/2 list;
			arr[i] = mergeTwoSortedList(arr[i], arr[j]);
			i++, j--;
            // When all two pairs of lists are sorted in one iteration, last is updated to half (j decremented in each
            // iteartion, hence number of list unmerged becomes half each time).
			if (i >= j)
				last = j;
		}
	}
    // first will the head eventually after whole merging process finished
	return arr[0];
}

int main(){
	// Number of lists
	int k;
	cin>>k;
    // Array of lists
	vector<node*> arr(k);
	for(int i=0;i<k;i++){
    	// Size of each list
		int n;
		cin>>n;
		while(n--){
			int x;
			cin>>x;
			cout<<x<<endl;
			arr[i]=pushFront(arr[i],x);
		}
	}
	for(int i=0;i<k;i++)
		print(arr[i]);
    // Merge all lists
	node* head=mergeKSortedList(arr, k );
	print(head);

	
}
