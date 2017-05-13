/*
 * Problem : Given an array of numbers, segregate even and odd such that even comes first
 * Similar to problem of segregating array of 0s and 1s
 * Maintain two indices, left and right, and swap numbers accordingly so that even comes first and odd last
 * TC: O(n)
 */

#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr, int low, int high){
	for(int i=low;i<=high;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void segregateEvenAndOdd(vector<int> &arr){
	int i=0;
	int j=arr.size()-1;
	print(arr,0,arr.size()-1);
	while(i<j){
		while(i<arr.size() && arr[i]%2==0)
			i++;
		while(j>=0 && arr[j]%2!=0)
			j--;
		if(i<j){
			swap(arr[i],arr[j]);
			i++;
			j--;
		}
	}
	print(arr,0,arr.size()-1);
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
		segregateEvenAndOdd(arr);
	}
	return 0;
}
