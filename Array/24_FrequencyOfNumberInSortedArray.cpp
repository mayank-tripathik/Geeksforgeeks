/*
 * Given a sorted array of numbers and a number x, find the number of occurences of x in array. If no occurence, return -1
 * Linear search is naive. Comeplxity: O(n)
 * We can use two binary searches, one modified for finding it sfirst occurence, other modified for finding its last occurence.
 * TC: O(logn)
 */

#include<bits/stdc++.h>
using namespace std;

int binarySearchLeft(vector<int> &arr, int low, int high, int x){
	if(high<low)
		return -1;
	int mid=(low+high)/2;
	if(arr[mid]==x){
		if(mid-1>=0 && arr[mid-1]==x)
			return binarySearchLeft(arr,low,mid-1,x);
		else
			return mid;
	}
	else if(arr[mid]>x)
		return binarySearchLeft(arr,low,mid-1,x);
	else
		return binarySearchLeft(arr,mid+1,high,x);
}

int binarySearchRight(vector<int> &arr, int low, int high, int x){
	if(high<low)
		return -1;
	int mid=(low+high)/2;
	if(arr[mid]==x){
		if(mid+1<arr.size() && arr[mid+1]==x)
			return binarySearchRight(arr,mid+1,high,x);
		else
			return mid;
	}
	else if(arr[mid]>x)
		return binarySearchRight(arr,low,mid-1,x);
	else
		return binarySearchRight(arr,mid+1,high,x);
}

int numberOfOccurences(vector<int> &arr, int x){
	int leftIndex=binarySearchLeft(arr,0,arr.size()-1,x);
	cout<<"L:"<<leftIndex<<endl;
	if(leftIndex==-1)
		return -1;
	int rightIndex=binarySearchRight(arr,leftIndex,arr.size()-1,x);
	cout<<"R:"<<rightIndex<<endl;
	return (rightIndex-leftIndex+1);
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n,x;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cin>>x;
		cout<<numberOfOccurences(arr,x)<<endl;
	}
}
