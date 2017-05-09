/*
 * Problem: Given an array, count number of inversion in array
 * Solution: Brute force would give O(n)
 * Following is divide and conquor approach based on merge sort where merge procedure is altered to set split inversions
 * Time complexity: O(nlogn) 
 * Space complexity: O(n)
 */


#include<bits/stdc++.h>
using namespace std;
#define SENITEL INT_MAX
long totalInversions;

void print(vector<int> &arr, int low, int high){
	for(int i=low;i<=high;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

long merge(vector<int> &arr, int low, int mid, int high){
	vector<int> lowerArray,upperArray;
	long inversions=0;
	for(int i=low;i<=mid;i++)
		lowerArray.push_back(arr[i]);
	for(int i=mid+1;i<=high;i++)
		upperArray.push_back(arr[i]);
	lowerArray.push_back(SENITEL);
	upperArray.push_back(SENITEL);
	int k=low;
	int offset=lowerArray.size()-1;
	for(int i=0,j=0;i<=lowerArray.size() && k<=high;){
		if(lowerArray[i]<=upperArray[j]){
			arr[k++]=lowerArray[i++];	
		}
		else{
			if(lowerArray[i]!=SENITEL){
				inversions+=(offset-i);
			}
			arr[k++]=upperArray[j++];
		}
	}
	return inversions;
}

void extendedMergeSort(vector<int> &arr, int low, int high){
	if(low<high){
		int mid=(low+high)/2;
		extendedMergeSort(arr,low,mid);
		extendedMergeSort(arr,mid+1,high);
		totalInversions+=merge(arr,low,mid,high);
	}
}

void countInversions(vector<int> arr){
	totalInversions=0;
	extendedMergeSort(arr,0,arr.size()-1);
	cout<<totalInversions<<endl;
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
		countInversions(arr);
	}
}
