/*
 * You are given n pairs of numbers. In every pair, the first number is always smaller than the second number. 
 * A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. 
 * Find the longest chain which can be formed from a given set of pairs. 
 * Example, if the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} }
 * Then the longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}
 * Note that sequence here doesn't matters. So to maximize the following condtion, we will first sort pairs according to 
 * first or second item
 * Once sorted, the problem becomes a variation of standard Longest Increasing Subsequence problem. 
 * we can now use modified LIS process where we compare the second element of already finalized LIS with the first element of 
 * new LIS being constructed.
 * TC:O(n^2)
 * The given problem is also a variation of Activity Selection problem and can be solved in (nLogn) time. 
 * To solve it as a activity selection problem, consider the first element of a pair as start time in activity selection 
 * problem, and the second element of pair as end time.
 */
#include <bits/stdc++.h>
using namespace std;

struct chainPair
{
	int first;
	int second;
	chainPair(int x, int y){
		first=x;
		second=y;
	}	
};

int maxChainLength(vector<chainPair> &chain){
	// This array is used to track the maximum chain length we get if the pair at i'th index is included in
	// the chain sequence
	// Initialize this extra array of same size as given array, with value 1 as every pair is itself
	// the candidate for longest chain length ending at its index
	vector<int> dp(chain.size(),1);
    // Now starting from second pair
	for(int i=1;i<dp.size();i++){
    	// check for all previous pair of above chosen element
		for(int j=0;j<i;j++){
        	// if the first element of i'th pair is greater than second element of j'th pair, the j'th
        	// pair may be included in the maximum chain ending at i. To check if it will actually be a part or
        	// not, check if the maximum chain length upto j, when combines with ith pair yield a chain length
        	// that is greater than the previous chain length ending at index i, if it is, include the j'th pair
        	// otherwise discard it
			if(chain[i].first>chain[j].second){
				dp[i]=max(1+dp[j],dp[i]);
			}
		}
	}
    // DP array now stores maximum chain length we get if we include ith pair in the chain sequence
    // Our answer will simply be the max of all these chain length.
	return *max_element(dp.begin(),dp.end());
}

bool compare(const chainPair &l, const chainPair &r){
	return l.first<r.first;
}

int main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<chainPair> chain;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			chain.push_back(chainPair(x,y));
		}
		// We are sorting the given pairs as we want the longest chain we can form from given
		// set of pairs (NOT sequence of pairs). Hence order doesn't matter here. So we sort the 
		// given set of pair according to first or last value.
		sort(chain.begin(),chain.end(),compare);
		cout<<maxChainLength(chain)<<endl;
	}
	return 0;
}
