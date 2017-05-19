/*
* Problem: Given an array of n distinct integers sorted in ascending order, find Fixed Point in the array, if exist, else return -1
* Fixed Point in an array is an index i such that arr[i] is equal to i. Note that integers in array can be negative. 
* Linear Solution is simple but O(n)
* We can solve it in O(logn) by slight modification in binary search where we check for arr[mid] and mid and then go to left 
* or right accordingly
* TC: O(logn)
*/

#include<bits/stdc++.h>
using namespace std;

int fixedPoint(vector<int> &arr, int low, int high){
	if(low>high)
		return -1;
	int mid=(low+high)/2;
	if(arr[mid]<mid)
		return fixedPoint(arr,mid+1,high);
	else if(arr[mid]>mid)
		return fixedPoint(arr,low,mid-1);
	else
		return mid;
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
		cout<<fixedPoint(arr,0,n-1)<<endl;

	}
}
