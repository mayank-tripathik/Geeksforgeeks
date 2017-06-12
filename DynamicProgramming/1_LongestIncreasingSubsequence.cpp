/*
 * The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence 
 * such that all elements of the subsequence are sorted in increasing order. 
 * For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}. 
 * Optimal Substructure:
 * Let arr[0..n-1] be the input array and L(i) be the length of the LIS ending at index i such that arr[i] is the last 
 * element of the LIS.
	Then, L(i) can be recursively written as:
	L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or
	L(i) = 1, if no such j exists.
 * To find the LIS for a given array, we need to return max(L(i)) where 0 < i < n.
 * Thus LIS problem satisfies the optimal substructure property as the main problem can be solved using solutions to subproblems.
 * Solveing it with recursion is exponential. Reason?
 * Recursion tree for an array of size 4. lis(n) gives us the length of LIS for arr[].

				      lis(4)
				/        |     \
			      lis(3)    lis(2)   lis(1)
			     /   \        /
			   lis(2) lis(1) lis(1)
			   /
			lis(1)

 * We can see that there are many subproblems which are solved again and again. 
 * So this problem has Overlapping Substructure property and recomputation of same subproblems can be avoided by either 
 * using Memoization or Tabulation. Following is a tabluated implementation for the LIS problem.
*/

#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &vec){
    cout<<"LIS is : ";
    for(int i=vec.size()-1;i>=0;i--)
        cout<<vec[i]<<" ";
    cout<<endl;
}
int longestIncreasingSubsequence(vector<int> &arr){
	// If array length is zero, then LIS is zero
	if(arr.size()==0)
		return 0;
	// Every index of this array will store the length of the LIS, if arr[index] is the last element of LIS
	// Initialize LIS array to length 1
    vector<int> LIS(arr.size(),1);
    // Array used to track the elements that are a part of LIS
    vector<int> parent(arr.size(),-1);
    // Start from second element and go till last
    for(int i=1;i<arr.size();i++){
    	// For all element preceding the above chose element, check whether it is less then chosen element
    	// If it is less, then choses element will participate in forming LIS. If it is greater,Chosen element
    	// is simply the single element of a LIS of which it is the last element
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                if(LIS[j]+1>LIS[i]){
                    LIS[i]=1+LIS[j];
                    parent[i]=j;
                }
            }
        }
    }
    // Get maximum LIS length from array
    int maxIndex=0;
    for(int i=1;i<arr.size();i++){
        if(LIS[i]>LIS[maxIndex]){
            maxIndex=i;
        }
    }
    // Once we get max LIS length, we can track the elements which are a part of LIS using parent array.
    // We will keep tracking back until we get an index -1
    int index=maxIndex;
    vector<int> LISArray;
    while(index!=-1){
        LISArray.push_back(arr[index]);
        index=parent[index];
    }
    // print the LIS elements
    print(LISArray);
    // return our answer
    return LIS[maxIndex];
}
int main() {
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<"LIS length:"<<longestIncreasingSubsequence(arr)<<endl;
    }
	return 0;
}
