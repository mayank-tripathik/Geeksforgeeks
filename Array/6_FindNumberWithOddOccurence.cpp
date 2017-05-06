/*
 * Problem : Given an array where ll numbers occur even number of times except one number which occurs odd number of times. Find it
 * Solution : First approach could be bruteforce. Picking each number and checking its occurence. O(N^2)
 * Other could be using hashing to count occurences. O(N) time complexity but also O(N) space complexity
 * Best approach: Calculate XOR of all elements. Their XOR will give the number with odd occurence: TC- O(N)
 */

#include<iostream>
#include<vector>
using namespace std;

int findNummberWithOddOccurence(vector<int> &arr){
	int xorOfAllNumbers=0;
	for(int i=0;i<arr.size();i++)
		xorOfAllNumbers=xorOfAllNumbers ^ arr[i];
	return xorOfAllNumbers;
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
		cout<<findNummberWithOddOccurence(arr)<<endl;
	}
}
