/* Problem: Find the maximum element in an array which is first increasing and then decreasing
 * Solution: Linear search is trivial, complexity is O(n)
 * Modified binary search can be used to find maximam element in log(n)
 */
 #include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &arr, int low , int high){
  //if one element, return it
	if(low==high)
		return arr[low];
  //if two element remianing, return max of them
	if(high==low+1)
		return max(arr[low],arr[high]);
	//otherwise move left or right or return element accordingly
  int mid=(low+high)/2;
	if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1])
		return arr[mid];
	else if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1])
		return binarySearch(arr,low,mid-1);
	else
		return binarySearch(arr,mid+1,high);
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
		cout<<binarySearch(arr,0,n-1)<<endl;
	}
}
