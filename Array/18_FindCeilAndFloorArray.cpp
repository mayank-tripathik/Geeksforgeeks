/*
 * Given an array of numbers and a number x , find the ceiling and floor of x in array
 * Ceiling is the smallest number greater than or equal to x
 * Floor is the largest number smaller than or equal to x
 * Solution : One is simple linear approach where we search for x and report it if found, otherwise search for number just greater
 * than x or number just smaller than x depending upon ceil and floor. Complexity: O(n)
 * Best: Use modified binary search to search for x, if x exist report it, otherwise report elements greater or smaller than it
 * if exists in array
 * TC: O(logn)
 */

#include<bits/stdc++.h>
using namespace std;

/*Following are the O(n) implimenataions of floor and ceiling functions*/
void floor(vector<int> &arr, int x){
	int floorOfx;
	int i;
	for(i=arr.size()-1;i>=0;i--){
		if(arr[i]==x){
			floorOfx=arr[i];
			break;
		}
		else if(arr[i]<x){
			floorOfx=arr[i];
			break;
		}
	}
	if(i<0)
		cout<<"Floor of given number doesn't exist!"<<endl;
	else
		cout<<"Floor of given number is:"<<floorOfx<<endl;
}

void ceiling(vector<int> &arr, int x){
	int ceilingOfx;
	int i;
	for(i=0;i<arr.size();i++){
		if(arr[i]==x){
			ceilingOfx=arr[i];
			break;
		}
		else if(arr[i]>x){
			ceilingOfx=arr[i];
			break;
		}
	}
	if(i==arr.size())
		cout<<"Ceil of given number doesn't exist!"<<endl;
	else
		cout<<"Ceil of given number is:"<<ceilingOfx<<endl;
}


/* Finding ceiling and floor using binary search : O(logn)*/
int binarySearchForCeiling(vector<int> &arr, int low, int high, int x){
	if(high<low){
		if(low<arr.size())
			return arr[low];
		else
			return -1;
	}
	int mid=(low+high)/2;
	if(x==arr[mid]){
		return x;
	}
	else if(x>arr[mid])
		binarySearchForCeiling(arr,mid+1,high,x);
	else
		binarySearchForCeiling(arr,low,mid-1,x);
}

int binarySearchForFloor(vector<int> &arr, int low, int high, int x){
	if(high<low){
		if(low-1>=0)
			return arr[low-1];
		else
			return -1;
	}
	int mid=(low+high)/2;
	if(x==arr[mid]){
		return x;
	}
	else if(x>arr[mid])
		binarySearchForFloor(arr,mid+1,high,x);
	else
		binarySearchForFloor(arr,low,mid-1,x);
}

void findCeilAndFloor(vector<int> &arr, int x){
	int floorOfx=binarySearchForFloor(arr,0,arr.size()-1,x);
	if(floorOfx==-1)
		cout<<"Floor of given number doesn't exist!"<<endl;
	else
		cout<<"Floor of given number is:"<<floorOfx<<endl;
	int ceilingOfx=binarySearchForCeiling(arr,0,arr.size()-1,x);
	if(ceilingOfx==-1)
		cout<<"Ceil of given number doesn't exist!"<<endl;
	else
		cout<<"Ceil of given number is:"<<ceilingOfx<<endl;
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n,x;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cin>>x;
		findCeilAndFloor(arr,x);
	}
	return 0;
}
