/*
 * Given an array if integers, find contiguous subarray with maximum sum
 * Kadane algorithm is used: Complexity O(n)
 */

#include<bits/stdc++.h>
#include<vector>
using namespace std;


/*Sample Input:
2
8
-2 -3 4 -1 -2 1 5 -3
8
-2 -3 -5 -1 -2 -1 -3 -3
*/

//Handles only cases where array has atleast one positive number
/*int largestSumContiguousSubarray(vector<int> &arr){
	int maximumSum=0,currentSum;
	for(int i=0;i<arr.size();i++){
		currentSum+=arr[i];
		if(currentSum<0)
			currentSum=0;
		else if(currentSum>maximumSum)
			maximumSum=currentSum;
		cout<<currentSum<<" "<<maximumSum<<endl;
	}
	return maximumSum;
}


int largestSumContiguousSubarray(vector<int> &a){
	int max_so_far = a[0];
	int curr_max = a[0];
	int size=a.size();
	for (int i = 1; i < size; i++){
		curr_max = max(a[i], curr_max+a[i]);
		max_so_far = max(max_so_far, curr_max);
		cout<<curr_max<<" "<<max_so_far<<endl;
	}
	return max_so_far;
}
*/

//Handles every case
int largestSumContiguousSubarray(vector<int> &arr){
	int maximumSum=INT_MIN,currentSum=0;
	int start=0,end=0,current_start=0;
	for(int i=0;i<arr.size();i++){
		currentSum+=arr[i];
		if(currentSum>maximumSum)
			maximumSum=currentSum,start=current_start,end=i;
		if(currentSum<0)
			currentSum=0,current_start=i+1;
	}
	cout<<start<<" "<<end<<endl;
	return maximumSum;
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
		cout<<largestSumContiguousSubarray(arr)<<endl;
	}
}
