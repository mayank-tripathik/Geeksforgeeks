/*
 * Problem : Given an array,find k largest element in array
 * There are many efficient ways to solve this problem.
 * In below implimentation, a maxheap of all elements is first created. And then extract is called k times to get k top elements.
 * TC: O(n+klogn)
 */


#include<bits/stdc++.h>
using namespace std;

class maxHeap{
	vector<int> arr;
public:
	int parent(int i){
		return (i-1)/2;
	}
	int leftChild(int i){
		return 2*i+1;
	}
	int rightChild(int i){
		return 2*i+2;
	}
	void insert(int x){
		arr.push_back(x);
	}
	void heapify(int i){
		int maxChild=i;
		if(rightChild(i)<arr.size() && arr[leftChild(i)]<arr[rightChild(i)])
			maxChild=rightChild(i);
		else if(leftChild(i)<arr.size())
			maxChild=leftChild(i);
		if(arr[maxChild]>arr[i]){
			swap(arr[i],arr[maxChild]);
			heapify(maxChild);
		}
	}
	void build(){
		for(int i=arr.size()/2;i>=0;i--){
			heapify(i);
		}
	}
	void print(){
		for(int i=0;i<arr.size();i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	int extract(){
		int temp=arr[0];
		swap(arr[0],arr[arr.size()-1]);
		arr.pop_back();
		heapify(0);
		return temp;
	}
};

void kLargestELementInArray(int n){
	maxHeap heap;
	int k;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		heap.insert(x);
	}
	cin>>k;
	heap.build();
	heap.print();
	cout<<"Top k elements are:"<<endl;
	for(int i=0;i<k;i++){
		cout<<heap.extract()<<endl;
	}
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		kLargestELementInArray(n);
	}
}
