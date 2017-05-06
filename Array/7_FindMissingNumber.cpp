/*
 * Problem: Given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in list.
 * One of the integers is missing in the list. Find it. 
 * Solution: First soln can be using sum formula to get sum of all numbers from 1 to n, and then subtracting each number from it.
 * Best solution in doing XOR of all elements from 1 to n, and further XORing it with XOR of all array elements to get answer
 * Complexity: O(n)
 */


#include<iostream>
#include<vector>
using namespace std;

int findMissingNumber(vector<int> &arr){
	int n=arr.size();
	int xor1=0,xor2=0;
	//xor1 stores xor of all elements from 1 to n
	for(int i=1;i<=n+1;i++)
		xor1=xor1 ^ i;
	//xor2 stores xor of all array elements
	for(int i=0;i<n;i++)
		xor2=xor2 ^ arr[i];
	return xor1 ^ xor2;
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
		cout<<findMissingNumber(arr)<<endl;
	}
}
