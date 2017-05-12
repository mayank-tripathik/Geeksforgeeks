/*
 * Problem: Given two sorted arrays. find their union and intersection
 * Both are similar to merge operation on sorted arrays
 * Solution: In union, push smaller elements on comparing one by one, and push only one in case of common.
 * In case of intersection, do nothing to smaller, but just push only if common element occurs.
 * Complexity : Both O(m+n)
 * Note that if their is a significant difference in size of two arrays, best way is to pick element of smaller array one by one
 * and search it in bigger array using binary search and then do the opeartion accordingly.
 */

#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr, int low, int high){
	for(int i=low;i<=high;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

vector<int> unionOfArray(vector<int> &arr1, vector<int> &arr2){
	vector<int> arrayUnion;
	int i=0,j=0;
	while(i<arr1.size() && j<arr2.size()){
		if(arr1[i]<arr2[j]){
			arrayUnion.push_back(arr1[i]);
			i++;
		}
		else if( arr2[j]<arr1[i]){
			arrayUnion.push_back(arr2[j]);
			j++;
		}
		else{
			arrayUnion.push_back(arr1[i]);
			i++;
			j++;
		}
	}
	while(i<arr1.size()){
		arrayUnion.push_back(arr1[i++]);
	}
	while(j<arr2.size()){
		arrayUnion.push_back(arr2[j++]);
	}
	return arrayUnion;
}

vector<int> intersectionOfArray(vector<int> &arr1, vector<int> &arr2){
	vector<int> arrayIntersection;
	int i=0,j=0;
	while(i<arr1.size() && j<arr2.size()){
		if(arr1[i]<arr2[j]){
			i++;
		}
		else if(arr2[j]<arr1[i]){
			j++;
		}
		else{
			arrayIntersection.push_back(arr1[i]);
			i++;
			j++;
		}
	}
	return arrayIntersection;
}


int main(){
	int test;
	cin>>test;
	while(test--){
		int n,m;
		cin>>n;
		vector<int> arr1(n);
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		cin>>m;
		vector<int> arr2(m);
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		vector<int> arrayUnion=unionOfArray(arr1,arr2);
		vector<int> arrayIntersection=intersectionOfArray(arr1,arr2);
		print(arrayUnion,0,arrayUnion.size()-1);
		print(arrayIntersection,0,arrayIntersection.size()-1);
	}
}
