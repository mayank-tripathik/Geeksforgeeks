/*
 * Problem : Given a sorted element and an element x, check if x is majority element of array or not
 * Solution : A simple approach could have been a linear search that first scans for position of x and then check if positon+n/2
 * has same element or not. This is O(N) approach.
 * Above approach can be improved by modified binary search where element's first occurence is found in O(logn) time.
 */


#include<iostream>
#include<vector>
using namespace std;

//Modified binary search that returns index of the first occurence of element if element is found otherwise returns -1
int binarySearch(vector<int> &arr, int x, int low, int high){
		if(high<low)
			return -1;
		int mid=(low+high)/2;
		if ((mid == 0 || x > arr[mid-1]) && (arr[mid] == x))
            return mid;
		else if(arr[mid]<x)
			return binarySearch(arr,x,mid+1,high);
		else
			return binarySearch(arr,x,low,mid-1);	
}

//First check the occurence of given element in array and then checks if n/2th element after it is same or not
void majorityElementSortedArray(vector<int> &arr, int element){
	int n=arr.size();
	int elementIndex=binarySearch(arr,element,0,n-1);
	int nextIndex=elementIndex+(n/2);
	if(elementIndex!=-1)
		if((nextIndex<=(n-1)) && arr[nextIndex]==element)
			cout<<"Given element is the majority element\n";
		else
			cout<<"Element Found but is not the majority element\n";
	else
		cout<<"Given element is not found at all\n";
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
		int x;
		cin>>x;
		majorityElementSortedArray(arr,x);
	}
}
