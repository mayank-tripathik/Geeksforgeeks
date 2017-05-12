/*
 * Problem: Given an array arr[] of integers, find out the maximum difference between any two elements such that larger element 
 * appears after the smaller number in arr[].
 * Solution: Brute force approach: Two loops; pick one element and subtract it from elements right to it and take max : O(n^2)
 * Efficient Solution: Track current minimum while going from left to right and subtract it with current element to get current
 * difference. In this way keep track of maximum difference. 
 * TC: O(n)
 * Similarly we can solve it by tracking currentmax from right.
 */



#include<bits/stdc++.h>
using namespace std;

int maximumDifference(vector<int> &arr){
	int currentMin=arr[0];
	int maximumDifference=arr[1]-arr[0];
	for(int i=1;i<arr.size();i++){
		if(arr[i]-currentMin>maximumDifference){
			maximumDifference=arr[i]-currentMin;
		}
		if(arr[i]<currentMin)
			currentMin=arr[i];
	}
	return maximumDifference;
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
		cout<<maximumDifference(arr)<<endl;
	}
}
