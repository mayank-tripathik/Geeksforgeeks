/*
 * Problem : Two sorted arrays given, with first is of size m+n containing only m elements and n spaced denoted by -1. 
 * Another one is of size n and contains n elements. Merge them to get first array of size m+n as sorted.
 * Solution: It can be solved by first moving all array elements of first array to begining, then comparing elements of both array 
 * from end to fill first from last
 * Complexity: O(m+n)
 * Note that this can also be solved by moving elements of first array to end
 * Thus moving all the space to either start or end both works!
 */
 
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void print(vector<int> &arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void moveElementsToStart(vector<int> &arr){
	for(int i=0, j=0;i<arr.size();i++){
		if(arr[i]!=-1){
			arr[j++]=arr[i];
		}
	}
}

void mergeSortedArray(vector<int> &arr1, vector<int> &arr2){
	moveElementsToStart(arr1);
	int n=arr1.size();
	int m=arr2.size();
	print(arr1);
	print(arr2);
	for(int i=n-m-1, j=m-1, k=n-1;j>=0;){
		if(i>=0){
			if(arr2[j]>arr1[i])
				arr1[k--]=arr2[j--];
			else
				arr1[k--]=arr1[i--];
		}
		else{
			arr1[k--]=arr2[j--];
		}
	}
	print(arr1);
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
		mergeSortedArray(arr1,arr2);
	}
}



/* 
 * Problem: Given two sorted arrays of size n and m, merge them so that resultant array is sorted
 * Solution : It can be solved in O(m+n) complexity if O(m+n) extra space is used. 
 * Compare elements of two arrays and put the small one in new array.
 * Complication arising due to difference in array size can be handled by adding some sentinel (ex INT_MAX) to arrays end.
 */

#include<bits/stdc++.h>
using namespace std;
#define SENTINEL INT_MAX

void print(vector<int> &arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void mergeSortedArray(vector<int> &arr1, vector<int> &arr2){
	vector<int> aux;
	arr1.push_back(SENTINEL);
	arr2.push_back(SENTINEL);
	for(int i=0,j=0;i<arr1.size();){
		if(arr1[i]<=arr2[j])
			aux.push_back(arr1[i++]);
		else
			aux.push_back(arr2[j++]);
	}
	aux.pop_back();
	print(aux);
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
		mergeSortedArray(arr1,arr2);
	}
}
