/*
 * Problem : Write a program to print all the LEADERS in the array. 
 * An element is leader if it is greater than all the elements to its right side. 
 * This means the rightmost element is always a leader.
 * Solution: A brute force approach would be picking each element one by one and checking if it is greater than all the 
 * elements to the right. Complexity: O(n)
 * Better solution is to scan array from right to left and check if number is maximum from right. Each number which is current
   maximum from right is leader. Complexity: O(n)
 */


#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void findLeaders(vector<int> arr){
	int n=arr.size();
	int currentMax=arr[n-1];
	cout<<currentMax<<" ";
	for(int i=n-1;i>=0;i--){
		if(arr[i]>currentMax){
			currentMax=arr[i];
			cout<<currentMax<<" ";
		}
	}
	cout<<endl;
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
		findLeaders(arr);
	}
}
