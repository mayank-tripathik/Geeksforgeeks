/*
 * Given an unsorted LL, remove duplicates from it
 * Solution: Brute force. O(n^2). Pick each element one by one and remove if nodes who have the same value.
 * Use hashing. Hash each unvisited value. If any node is found who has already visited value i.e its value is present
 * in hash, remove it. TC:O(n). Auxillary Space:O(n)
 * We can also use merge sort to first sort LL and then use O(n) algo for checking duplicates in sorted list. TC:O(nlogn)
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

class llist{
	node *head;
	public:
	llist(){
		head=NULL;
	}
	void pushFront(int x){
		node* temp=new node(x);
		temp->next=head;
		head=temp;
	}
	void removeDuplicatesFromUnSortedBruteForce(){
		if(!head)
			return;
		// pick pointer picks each node one by one, and traverse will check if value repeates
		// from the next node onwards
		node *pick,*traverse;
		pick=head;
		while(pick){
			// Stroing pick's node value as current value
			int currentValue=pick->value;
			traverse=pick;
			// This loop runs the number of times as many nodes after the pick node
			while(traverse->next){
				// If nodes after pick node has value currentValue, delete them
				if(traverse->next->value==currentValue){
					node *temp=traverse->next;
					traverse->next=traverse->next->next;
					delete(temp);
				}
				// Otherwise move the traverse pointer to check further nodes
				else{
					traverse=traverse->next;
				}
			}
			// Here it is sure that currentValue will not repeat in the whole list
			// advances pick pointer to pick next value
			pick=pick->next;
		}
	}
	void removeDuplicatesFromUnSortedByHashing(){
		if(!head)
			return;
		// current pointer acts as a previous to the node who value may have to be deleted(if has repeated value)
		node *current;
		current=head;
		unordered_set<int> hash;
		// Push the first value in hash
		hash.insert(current->value);
		while(current->next){
			// Value stores the value of a node for whom check has to be made if value is repeated
			// If it value is repeated, it should have existed in the map
			int value=current->next->value;
			// Check if value is already existed in map
			// If so delete it
			if(hash.find(value)!=hash.end()){
				node* temp=current->next;
				current->next=current->next->next;
				delete(temp);
			}
			// otherwise push the value in map
			// and advances the current pointer
			else{
				hash.insert(value);
				current=current->next;
			}
		}
	}
	void print(){
		cout<<"List:";
		node* temp=head;
		while(temp){
			cout<<temp->value<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
};
int main(){
	int n;
	cin>>n;
	llist l;
	while(n--){
		int x;
		cin>>x;
		l.pushFront(x);
	}
	l.print();
	l.removeDuplicatesFromUnSortedBruteForce();
	l.removeDuplicatesFromUnSortedByHashing();
	l.print();
	return 0;
}
