/*
 * Given an array of 0s and 1s, segregate o and 1 so that 0 appears first and 1s at last
 * Easily segrgated by counting 0s or 1s, but that requires two passes
 * Can be segregated in one travserse by maintaining two index,left and right and swapping accordingly
 * TC: O(n)
 */

#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr, int low, int high){
	for(int i=low;i<=high;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void segregateZeroesandOnes(vector<int> &arr){
	int leftIndex,rightIndex;
	int n=arr.size();
	leftIndex=0;
	rightIndex=arr.size()-1;
	while(leftIndex<rightIndex){
		while(leftIndex<n && arr[leftIndex]==0)
			leftIndex++;
		while(rightIndex>=0 && arr[rightIndex]==1)
			rightIndex--;
		if(leftIndex<rightIndex)
			swap(arr[leftIndex],arr[rightIndex]);
	}
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<"Before segregation:\n";
		print(arr,0,n-1);
		segregateZeroesandOnes(arr);
		cout<<"After segregation:\n";
		print(arr,0,n-1);
	}
}
