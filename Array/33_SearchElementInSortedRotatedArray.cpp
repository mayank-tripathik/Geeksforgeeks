/*
 * An element in a sorted array can be found in O(log n) time via binary search. 
 * But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand. 
 * So for instance, 1 2 3 4 5 might become 3 4 5 1 2. Devise a way to find an element in the rotated array in O(log n) time.
 * Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
             key = 3
    Output : Found at index 8

    Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
             key = 30
    Output : Not found

    Input : arr[] = {30, 40, 50, 10, 20}
            key = 10   
    Output : Found at index 3
 * One way is to first search for the pivot(element at which). Pivot is the element after which element are sorted and upto which
 * element are sorted. The whole idea is to find the pivot point, divide the array in two sub-arrays and call binary search.
 * The main idea for finding pivot is – for a sorted (in increasing order) and pivoted array, pivot element is the only only 
 * element for which next element to it is smaller than it.
 * Using above criteria and binary search methodology we can get pivot element in O(logn) time. Follwoing is the approach:
 *  int findPivot(int arr[], int low, int high)
    {
       // base cases
       if (high < low)  return -1;
       if (high == low) return low;

       int mid = (low + high)/2;   //low + (high - low)/2;
       if (mid < high && arr[mid] > arr[mid + 1])
           return mid;
       if (mid > low && arr[mid] < arr[mid - 1])
           return (mid-1);
       if (arr[low] >= arr[mid])
           return findPivot(arr, low, mid-1);
       return findPivot(arr, mid + 1, high);
    }
    
 * we can then apply binary search in the two halves. This approach requires two pass of binary search
 * We can get answer in one part of binary search. The interesting property of a sorted + rotated array is that when you divide
 * it into two halves, atleast one of the two halves will always be sorted.
 * Example: Let input array arr = [4,5,6,7,8,9,1,2,3]
    number of elements  = 9
    mid index = (0+8)/2 = 

    [4,5,6,7,8,9,1,2,3]
             ^
     left   mid  right

    as seem right sub-array is not sorted while left sub-array is sorted.

    If mid happens to be the point of rotation them both left and right sub-arrays will be sorted.

    [6,7,8,9,1,2,3,4,5]
             ^
    But in any case one half(sub-array) must be sorted.

 * We can easily know which half is sorted by comparing start and end element of each half. Once we find which half is sorted 
 * we can see if the key is present in that half - simple comparison with the extremes.
 * If the key is present in that half we recursively call the function on that half else we recursively call our search on the 
 * other half.
 * We are discarding one half of the array in each call which makes this algorithm O(logN).
 */
 
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int key, vector<int> &arr, int low, int high){
	if(low>high)
		return -1;
	// Divide the array into two halves
	int mid=(low+high)/2;
	// if key is equal to mid element, it is the answer, return it
	if(arr[mid]==key)
		return mid;
	// if first half of the array is sorted
	else if(arr[low]<=arr[mid]){
		// Since first half is sorted we can check if key lies in first half by simply checking it with the 
		// extreme elements. If it lies we recur for it, otherwise we discard it and recur for second half
		if(arr[low]<=key && key<=arr[mid])
			return binarySearch(key,arr,low,mid-1);
		else
			return binarySearch(key,arr,mid+1,high);
	}
	// if first half is not sorted then second half must be sorted
	else{
		// Since second half is sorted we can check if key lies in second half by simply checking it with the 
		// extreme elements. If it lies we recur for it, otherwise we discard it and recur for first half
		if(arr[mid]<=key && key<=arr[high])
			return binarySearch(key,arr,mid+1,high);
		else
			return binarySearch(key,arr,low,mid-1);
	}
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int k;
		cin>>k;
		cout<<binarySearch(k,arr,0,n-1)<<endl;
	}
	return 0;
}
