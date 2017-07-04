/*
 * Given an array, how to check if the given array represents a Binary Max-Heap.
 * Examples:

  Input:  arr[] = {90, 15, 10, 7, 12, 2} 
  Output: True
  The given array represents below tree
         90
       /    \
     15      10
    /  \     /
   7    12  2 
  The tree follows max-heap property as every
  node is greater than all of its descendants.

  Input:  arr[] = {9, 15, 10, 7, 12, 11} 
  Output: False
  The given array represents below tree
         9
       /    \
     15      10
    /  \     /
   7    12  11
  The tree doesn't follows max-heap property 9 is 
  smaller than 15 and 10, and 10 is smaller than 11. 
 * Max-heap has property that every node is greater than all of its descendants.
 * A Simple Solution is to first check root, if it’s greater than all of its descendants. 
 * Then check for children of root. Time complexity of this solution is O(n^2)
 * An Efficient Solution is to compare root only with its children (not all descendants), if root is greater than its children 
 * and same is true for for all nodes, then tree is max-heap 
 * This conclusion is based on transitive property of > operator, i.e., if x > y and y > z, then x > z.
 * Similary we can check for min heap property by changing the compare operator
 * Complexity : O(n)
 */

#include<iostream>
#include<vector>
using namespace std;

// This function checks if a given array represent a binary max heap or not
bool isHeap(vector<int> &arr){
	// We will iterate till that element after which element doesn't have left child
	// Why do we do that? because heap has complete binary tree property so if any element has
	// no left child, no subsequent elements after it will have any child at all
	for(int i=0;2*i+1<arr.size();i++){
		// getting the indices of left and right child of current element
		int leftChild=2*i+1;
		int rightChild=2*i+2;
		// if current element is less than its leftchild or is less than its right child (if it exists)
		// we will return false as max heap property is violated
		if(arr[i]<arr[leftChild] || (rightChild<arr.size() && arr[i]<arr[rightChild]) )
		{
			return false;  
		}
	}
	return true;
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
		cout<<isHeap(arr)<<endl;
	}
	return 0;
}
