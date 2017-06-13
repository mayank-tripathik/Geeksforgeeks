/*
* Problem: Given a “2 x n” board and tiles of size “2 x 1”, count the number of ways to tile the given board using the 
* 2 x 1 tiles. A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile.
* Examples:
    Input n = 3
    Output: 3
    Explanation:
    We need 3 tiles to tile the board of size  2 x 3. 
    We can tile the board using following ways
    1) Place all 3 tiles vertically. 
    2) Place first tile vertically and remaining 2 tiles horizontally.
    3) Place first 2 tiles horizontally and remaining tiles vertically

    Input n = 4
    Output: 5
    Explanation:
    For a 2 x 4 board, there are 5 ways
    1) All 4 vertical
    2) All 4 horizontal
    3) First 2 vertical, remaining 2 horizontal
    4) First 2 horizontal, remaining 2 vertical
    5) Corner 2 vertical, middle 2 horizontal
 * The problem has optimal subtructure as when ever we get a tile, we can either place it vertically in case of which number of
 * ways depends on how we have placed n-1 tiles. Or we can place this tile and the previous one horizontally, in case of which
 * the number of ways depends on how we have placed n-2 tiles before it.
 * This is nothing but fibonacci number count upto n which we can calculate in O(logn) time. Following methods implements the 
 * usual O(n) implementation
 * TC:O(n)
 */

#include<iostream>
#include<vector>
using namespace std;
vector<long> ways;
long getCount(int n){
	// If n is 1, means 2*1 board is there and the only way is to put one 2*1 tile vertically
	if(n==1)
		return 1;
	// if n is 2, means 2*2 board is there, so we can either put two tiles horizontally, or 2 tiles
	// verticall, so two ways
	if(n==2)
		return 2;
	// If we have already calculated the ways for b tiles, return it
	if(ways[n]!=-1)
		return ways[n];
	// New tile can be put vertically, in case of which problem reduces to finding ways for n-1 tiles
	// or we can put tile horizontally, in case of which we also have to put previous tile horizontally.
	// problem thus reduces to finding ways for n-2 tiles. Hence recur for them and add them
	else
		return ways[n]=getCount(n-1)+getCount(n-2);
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		ways.clear();
		ways.resize(n+1,-1);
		long way=getCount(n);
		cout<<way<<endl;
	}
	return 0;
}


/* Solution to the genralized problem of above
 * Generalized problem: Given a floor of size n x m and tiles of size 1 x m. 
 * The problem is to count the number of ways to tile the given floor using 1 x m tiles. 
 * For a given value of n and m, the number of ways to tile the floor can be obtained from the following relation.

                      |  1, 1 < = n < m
           count(n) = |  2, n = m
                      | count(n-1) + count(n-m), m < n
                   
  */
             

#include<iostream>
#include<vector>
using namespace std;
vector<long> ways;
long getCount(int n, int m){
	// If n is less than m, only way is to put tiles vertically
	if(n<m)
		return 1;
    // if n==m, then we can either put all tiles horizontal or all tiles vertical
	if(n==m)
		return 2;
    // Similar recursion as above
	if(ways[n]!=-1)
		return ways[n];
	else
		return ways[n]=getCount(n-1,m)+getCount(n-m,m);
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n,m;
		cin>>n>>m;
		ways.clear();
		ways.resize(n+1,-1);
		long way=getCount(n,m);
		cout<<way<<endl;
	}
	return 0;
}
