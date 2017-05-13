/*
 * Given an array, find the equilibrium indexes of array, otherwise return none
 * An equilibrium index is a index such that sum of elements left to it is equal to sum of elements right to it
 * note that left and right part consists of no elements too
 * Brute force would be picking each element and checking if it is the required index by calculating left and right sum to it
 * Efficient solution: Take sum of all elements and use it to calculate rightsum by subtracting each array element while 
 * maintaining leftsum by adding array elemeny
 * TC: O(n)
 */

#include<bits/stdc++.h>
using namespace std;

void equilibriumIndex(vector<int> &arr){
	int n=arr.size();
	bool hasEquilibriumIndex=false;
	int rightSum=0,leftSum=0;
	for(int i=0;i<n;i++)
		rightSum+=arr[i];
	for(int i=0;i<n;i++){
		rightSum=rightSum-arr[i];
		if(rightSum==leftSum){
			cout<<"Equilibrium Index is:"<<i<<endl;
			hasEquilibriumIndex=true;
		}
		leftSum=leftSum+arr[i];
	}
	if(!hasEquilibriumIndex)
		cout<<"No Equilibrium Index Found!\n";
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
		equilibriumIndex(arr);
	}
	return 0;
}
