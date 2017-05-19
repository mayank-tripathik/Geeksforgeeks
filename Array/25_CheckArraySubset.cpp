/* 
 * Problem : Given two unsorted arrays, arr1 of size m and arr2 of size n, find whether arr2 is a subset of arr1.
 * Solution: Naive: O(n^2), pick each element of arr2 and check its presence in arr1.
 * Method 1: Sort arr1 and then check each element of arr2 in arr1 using binary search. Comeplxity:O(mlogm+nlogm)
 * Method 2: Sort both arrays, and then check both using modified merge procedure. Complexity: O(nlogn+mlogm)
 * Method 3: Hash all elements of arr1 along with their frequency, and then pick each element of arr2 and check it in hash
 * and accordingly decrease their frequency. If any of them not found, return false. Complexity : O(m+n), AS: O(R) where R
 * is range of numbers
 */

#include<bits/stdc++.h>
using namespace std;

/*Method 1. Sorting arr1 and then searching each element of arr2 in arr1 using binary search*/
bool binarySearch(vector<int> &arr, int low, int high, int x){
	if(high<low)
		return false;
	int mid=(low+high)/2;
	if(arr[mid]==x)
		return true;
	else if(arr[mid]>x)
		return binarySearch(arr,low,mid-1,x);
	else
		return binarySearch(arr,mid+1,high,x);
}

bool elementExists(int x,vector<int> &arr){
	return binarySearch(arr,0,arr.size()-1,x);
}

bool isSubsetOf(vector<int> &arr2, vector<int> &arr1){
	sort(arr1.begin(),arr1.end());
	for(int i=0;i<arr2.size();i++){
		if(!elementExists(arr2[i],arr1))
			return false;
	}
	return true;
}


/*Method 2: Sorting both arrays and then comparing them using a varition of merge procedure*/
bool isSubsetOf(vector<int> &arr2, vector<int> &arr1){
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());
	int i=0,j=0;
	while(i<arr1.size() && j<arr2.size()){
		if(arr1[i]==arr2[j])
			i++,j++;
		else if(arr1[i]<arr2[j])
			i++;
		else
			return false;
	}
	if(j==arr2.size())
		return true;
	else
		return false;
}

/*Method 3 : Using hashmap*/
bool isSubsetOf(vector<int> &arr2, vector<int> &arr1){
	unordered_map<int, int> hash;
	for(int i=0;i<arr1.size();i++){
		if(hash.find(arr1[i])!=hash.end()){
			hash.insert(make_pair(arr1[i],1));
		}
		else
			hash[arr1[i]]++;
	}
	for(int i=0;i<arr2.size();i++){
		if(hash.find(arr2[i])==hash.end())
			return false;
		else{
			if(hash[arr2[i]]<=0)
				return false;
			else
				hash[arr2[i]]--;
		}
	}
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
		if(isSubsetOf(arr2,arr1))
			cout<<"Array 2 is a subset of Array 1\n";
		else
			cout<<"Array 2 is not a subset of Array 1\n";
	}
}
