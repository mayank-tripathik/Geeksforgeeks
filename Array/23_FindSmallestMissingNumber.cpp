/*
 * Given a sorted array of length n, find the smallest missing number in array, where elements are in range [0,m-1]
 * Brute force: Pick each element from 0 to m-1, and search it in array using binary search. TC:O(mlogn)
 * Linear search: Since array is sorted, we can check adjacent element if their difference is greater than 1
 * TC:O(n). works for duplicates too.
 * However if their are no duplicates, modified binary search can be used to get missing number in O(logn)
 */

#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr, int low, int high){
	for(int i=low;i<=high;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

//Another way to write the modified binary search
int binarySearch(vector<int> &arr, int low, int high){
	if(high<low)
		return low;
	int mid=(low+high)/2;
	if(arr[mid]>mid){
		if(mid-1<0 || (mid-1>=0 && (arr[mid-1]==mid-1)) )
			return mid;
		else
			binarySearch(arr,low,mid-1);
	}
	else
		binarySearch(arr,mid+1,high);

}

//GFG modified binary search
/*int binarySearch(vector<int> &array, int low, int high){
    if (low  > high)
        return high + 1;
    if (low != array[low])
        return low;
    int mid = (low + high) / 2;
    if (array[mid] == mid)
        return binarySearch(array, mid+1, high);
    return binarySearch(array, low, mid);
}*/


/*This method works only for array having no duplicates*/
int findSmallestMissingNumber(vector<int> &arr, int n, int m){
	print(arr,0,n-1);
	cout<<binarySearch(arr,0,n-1)<<endl;
	
}


/*Though linear, it also works with duplicates*/
int findSmallestMissingNumberLinear(vector<int> &arr, int n, int m){
	if(arr[0]!=0)
		return 0;
	for(int i=0;i+1<n;i++){
		if(arr[i+1]-arr[i]>1)
			return arr[i]+1;
	}
	return arr[arr.size()-1]+1;
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n,m;
		cin>>n>>m;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		findSmallestMissingNumber(arr,n,m);
		cout<<findSmallestMissingNumberLinear(arr,n,m)<<endl;
	}
	return 0;
}
