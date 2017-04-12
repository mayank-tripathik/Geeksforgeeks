#include<iostream>
#include<vector>
using namespace std;

int binary_search_recursive(vector<int> &arr, int low, int high, int k){
	if(high<low)
		return -1;
	int mid=(high+low)/2;
	if(k==arr[mid])
		return mid;
	if(k<arr[mid])
		return binary_search_recursive(arr,low,mid-1,k);
	else
		return binary_search_recursive(arr,mid+1,high,k);
}

int binary_search_iterative(vector<int> &arr, int low, int high, int k){
	int mid;
	while(low<=high){
		mid=(high+low)/2;
		if(k==arr[mid])
			break;
		if(k<arr[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	if(arr[mid]==k)
		return mid;
	else
		return -1;
}
int main(){
	int n,k;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int test;
	cin>>test;
	while(test--){
		cin>>k;
		int ans=binary_search_iterative(arr,0,n-1,k);
		if(ans==-1)
			cout<<"not found\n";
		else
			cout<<"found\n";
	}
}
