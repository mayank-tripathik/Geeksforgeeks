/*
 * Problem: Given an array or string , reverse it.
 * Two pointers, low and end can be used to successively swap the elements in iterative approach
 * Similarly a recursive formulation is also possible
 * Compleixty: O(n)
 */

#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void reverseArrayIterative(vector<int> &arr){
	for(int i=0,j=arr.size()-1;i<j;i++,j--){
		swap(arr[i],arr[j]);
	}
	print(arr);
}


void reverseArrayRecursiveHelper(vector<int> &arr,int low,int high){
	if(low>=high)
		return;
	else{
		swap(arr[low],arr[high]);
		reverseArrayRecursiveHelper(arr,low+1,high-1);
	}
}

void reverseArrayRecursive(vector<int> &arr){
	reverseArrayRecursiveHelper(arr,0,arr.size()-1);
	print(arr);
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
		reverseArrayIterative(arr);
		//reverseArrayRecursive(arr);
	}
}
