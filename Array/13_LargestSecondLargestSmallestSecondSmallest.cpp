/*
 * Given an array, find the smallest and second smallest element. Similary find largest and second largest
 * Solution: Sorting array and choosing two smallest will account O(nlogn)
 * Better solution is to first search for minimum element and then search for second minimum in another pass
 * Best solution is to track both smallest and second smallest in one pass, by carefully changing both
 * Complexity: O(n)
 */

#include<bits/stdc++.h>
using namespace std;

void largestAndSecondLargest(vector<int> &arr){
	int largest=arr[0];
	int secondLargest=INT_MIN;
	for(int i=1;i<arr.size();i++){
		if(arr[i]>largest){
			secondLargest=largest;
			largest=arr[i];
		}
		else if(arr[i]>secondLargest && arr[i]<largest){
			secondLargest=arr[i];
		}
	}
	cout<<"Largest:"<<largest<<endl;
	if(secondLargest!=INT_MIN)
		cout<<"Second largest:"<<secondLargest<<endl;
	else
		cout<<"Second largest doesn't exist"<<endl;
}

void smallestAndSecondSmallest(vector<int> &arr){
	int smallest=arr[0];
	int secondSmallest=INT_MAX;
	for(int i=1;i<arr.size();i++){
		if(arr[i]<smallest){
			secondSmallest=smallest;
			smallest=arr[i];
		}
		else if(arr[i]>smallest && arr[i]<secondSmallest){
			secondSmallest=arr[i];
		}
	}
	cout<<"Smallest:"<<smallest<<endl;
	if(secondSmallest!=INT_MAX)
		cout<<"Second smallest:"<<secondSmallest<<endl;
	else
		cout<<"Second smallest doesn't exist"<<endl;
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
		smallestAndSecondSmallest(arr);
		largestAndSecondLargest(arr);
	}
}
