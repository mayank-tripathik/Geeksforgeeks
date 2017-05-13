/*
 * Given an array integers, construct a Product Array (of same size) such that prod[i] is equal to the product of all the 
 * elements of arr[] except arr[i]. 
 * Solve it without division operator and in O(n)
 * Solution: We can use two arrays,left and right to store cumulative product starting from left and right(except last elements)
 * We can then construct product array by simply multiplying two:
 * TC: O(n) but also O(n) auxiliary space.
 * We can reduce auxiliary space to O(1) by storing one of the cumulative sum in variable(say left) and using product array as
 * a temporary array for storing right cumulative product
 */

#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr, int low, int high){
	for(int i=low;i<=high;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

/*Following implementation uses O(n) auxillary space*/
void productArray(vector<int> &arr){
	int n=arr.size();
	vector<int> leftCumulativeProduct(n);
	vector<int> product(n);
	product[n-1]=1;
	leftCumulativeProduct[0]=1;
	for(int i=1;i<n;i++)
		leftCumulativeProduct[i]=leftCumulativeProduct[i-1]*arr[i-1];
	for(int i=n-2;i>=0;i--)
		product[i]=product[i+1]*arr[i+1];
	print(leftCumulativeProduct,0,n-1);
	print(product,0,n-1);
	for(int i=0;i<n;i++){
		product[i]=leftCumulativeProduct[i]*product[i];
	}
	print(product,0,n-1);
}

/*Following implementation uses O(1) auxillary space, product array is itself used as a temporary space*/
void productArraySpaceEfficient(vector<int> &arr){
	int n=arr.size();
	int leftCumulativeProduct=1;
	vector<int> product(n);
	product[n-1]=1;
	for(int i=n-2;i>=0;i--)
		product[i]=product[i+1]*arr[i+1];
	for(int i=0;i<n;i++){
		product[i]=leftCumulativeProduct*product[i];
		leftCumulativeProduct=leftCumulativeProduct*arr[i];
	}
	print(product,0,n-1);
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
		//productArray(arr);
		productArraySpaceEfficient(arr);
	}
	return 0;
}
