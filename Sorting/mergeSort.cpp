#include<bits/stdc++.h>
using namespace std;
#define SENITEL INT_MAX

void merge(vector<int> &arr, int low, int mid, int high){
	vector<int> lowerArray,upperArray;
	for(int i=low;i<=mid;i++)
		lowerArray.push_back(arr[i]);
	for(int i=mid+1;i<=high;i++)
		upperArray.push_back(arr[i]);
	lowerArray.push_back(SENITEL);
	upperArray.push_back(SENITEL);
	int k=low;
	for(int i=0,j=0;i<=lowerArray.size() && k<=high;){
		if(lowerArray[i]<upperArray[j])
			arr[k++]=lowerArray[i++];
		else
			arr[k++]=upperArray[j++];
	}
}

void mergeSort(vector<int> &arr, int low, int high){
	if(low<high){
		int mid=(low+high)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
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
		mergeSort(arr,0,n-1);
	}
}
