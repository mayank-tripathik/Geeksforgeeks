#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void getKLargestUsingMaxHeap(){
	int n,k;
	cin>>n>>k;
	// Max heap
	priority_queue<int> pq;
	// push all the element to the maxheap
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		pq.push(x);
	}
	// pop k elements from the maxheap to get k largest elements
	while(k--){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}

void getKLargestUsingMinHeap(){
	// Min heap
	priority_queue<int,vector<int>,greater<int> > pq;
	int n,k;
	cin>>n>>k;
	// Insert first k elements in min heap
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		pq.push(x);

	}
	// Now for remaining elements, do as follows
	for(int i=k+1;i<=n;i++){
		int x;
		cin>>x;
		// if element is greater than top element of min heap (top element of min heap is the current smallest
		// element among the k element), then this element should replace the top element. Hence pop the heap
		// and push the new element, if element is not greater simply ignore it.
		if(x>pq.top()){
			pq.pop();
			pq.push(x);
		}
	}
	// pop the heap and print elements. Elements will be printed in ascending order
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		getKLargestEfficient();
	}
	return 0;
}
