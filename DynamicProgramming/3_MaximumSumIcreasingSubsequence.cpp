/*
 * Problem: Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array 
 * such that the intgers in the subsequence are sorted in increasing order. 
 * Example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100)
 * Note that this problem is a slight variation of LIS problem where we have to find the maximum length of increasing subsequence
 * whereas here, we have to found the largest sum of increasing subsequence.
 * Thus all we need to change is to use sum as a criteria instead of length of increasing subsequence.
 * TC:O(n^2)
 */

#include <bits/stdc++.h>
using namespace std;

int maxSumIncreasingSubsequence(vector<int> &arr){
	// This array is used to track the maximum sum we get if the element at i'th index is included in
	// the increasing subsequence
	// Initialize this extra array of same size as given array
	vector<int> dp(arr.size());
    // For every single element, element itself would be the largest sum possible
    // hence initialize largest sum as the element itself at each position
	for(int i=0;i<dp.size();i++)
		dp[i]=arr[i];
    // Now starting from second element
	for(int i=1;i<dp.size();i++){
    	// check for all previous element of above chosen element
		for(int j=0;j<i;j++){
        	// if the j'th element is smaller than the ith element, then largest sum we get if we include
        	// element at index i may increase(because we want increasing subsequence). To check if largest sum
        	// increases or not, check if largest sum at index j, when combined with element at index i, fetches
        	// a sum which is greater than the sum we already have at i'th index, if it is, choose it, otherwise
        	// discards it
			if(arr[i]>arr[j]){
				dp[i]=max(arr[i]+dp[j],dp[i]);
			}
		}
	}
    // DP array now stores maximum sum we get if we include ith element in the increasing subsequence
    // Our answer will simply be the max of all these sums.
	return *max_element(dp.begin(),dp.end());
}

int main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<maxSumIncreasingSubsequence(arr)<<endl;
	}
	return 0;
}
