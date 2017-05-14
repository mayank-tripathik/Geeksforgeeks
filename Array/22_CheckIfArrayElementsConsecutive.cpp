/*
 * Given an array, check if array elements are consecutive or not
 * Solution: Sorting can be used to check but takes O(nlogn) time
 * Efficent: Two conditions to be satisfied: 
 * 1) max – min + 1 = n where max is maximum element in array, min is minimum element in array & n is the number of elements.
 * 2) All elements are distinct.
 * For 2nd condition, if all array elements are positive we can check it in O(n) by changing them to -ve on first encounter
 * If not all are positive then extra space of O(n) is used to check duplicates
 * TC:O(n)
 */

#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr, int low, int high){
	for(int i=low;i<=high;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

/*Works only if all elements are positive, works in O(1) auxiliary space*/
bool isArrayElementConsecutive(vector<int> &arr){
	int n=arr.size();
	if(n==1)
		return true;
	int maxElement,minElement;
	if(arr[0]>arr[1])
		maxElement=arr[0],minElement=arr[1];
	else
		maxElement=arr[1],minElement=arr[0];
	for(int i=2;i<n;i++){
		if(arr[i]>maxElement)
			maxElement=arr[i];
		else if(arr[i]<minElement)
			minElement=arr[i];
	}
	/*Enters only if 1st condition is satisfied, then further check for duplicates*/
	if(maxElement-minElement+1==n){
		for(int i=0;i<n;i++){
			if(arr[arr[i]-minElement]<0)
				return false;
			arr[arr[i]-minElement]=-arr[arr[i]-minElement];
		}
		return true;
	}
	return false;

}

/*Works for both negative and positive elements but takes O(n) auxiliary space*/
bool isArrayElementConsecutive(vector<int> &arr){
	int n=arr.size();
	if(n==1)
		return true;
	//Finding max and min element in array  in one loop
	int maxElement,minElement;
	if(arr[0]>arr[1])
		maxElement=arr[0],minElement=arr[1];
	else
		maxElement=arr[1],minElement=arr[0];
	for(int i=2;i<n;i++){
		if(arr[i]>maxElement)
			maxElement=arr[i];
		else if(arr[i]<minElement)
			minElement=arr[i];
	}
	//Enters only if 1st condition is satisfied, then further check for duplicates
	if(maxElement-minElement+1==n){
		vector<bool> visited(n,false);
		for(int i=0;i<n;i++){
			if(visited[arr[i]-minElement]!=false)
				return false;
			visited[arr[i]-minElement]=true;
		}
		return true;
	}
	return false;

}

/*O(nlogn) approach using sorting*/
bool isArrayElementConsecutive(vector<int> &arr){
	int n=arr.size();
	sort(arr.begin(),arr.end());
	int i;
	for(i=0;i+1<n;i++){
		if((arr[i]+1)!=arr[i+1])
			break;
	}
	if(i+1==n)
		return true;
	else
		return false;
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
		cout<<isArrayElementConsecutive(arr)<<endl;
	}
	return 0;
}
