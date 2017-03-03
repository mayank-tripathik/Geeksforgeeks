/*
 * Problem : The problem is to count all the possible paths from top left to bottom right of a MxN matrix.
 * Constraints is that from each cell you can either move only to right or down.
 */


/*
 * Recursive Solution
 * Expensive! Exponential complexity
 * Works for small matrices
 */
 
#include <iostream>
using namespace std;

int dfs(int x, int y, int m, int n){
    if(x>m || y>n)
        return 0;
    else if(x==m && y==n){
        return 1;   
    }       
    else
        return dfs(x+1,y,m,n)+dfs(x,y+1,m,n);
}

int count_paths(int m,int n){
    return dfs(1,1,m,n);
}

int main() {
	int test;
	cin>>test;
	while(test--){
	    int m,n;
	    cin>>m>>n;
	    cout<<count_paths(m,n)<<endl;
	}
	return 0;
}
