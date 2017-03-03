/*
 * Asked in Amazon!
 * Some people are standing in a queue. A selection process follows a rule where people standing on even positions are selected. Of the selected people a queue is formed and again out of these only people on even position are selected. This continues until we are left with one person. Find out the position of that person in the original queue.
 * greates power of 2 which is smallest than n is the answer
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    int x=(log2(n));
	    cout<<pow(2,x)<<endl;
	}
	return 0;
}
