/*
 * Given a number n. The problem is to check whether every bit in the binary representation of the given number is set or not. 
 * Here n>=0.
 * Examples:
    Input : 7
    Output : Yes
    (7)10 = (111)2

    Input : 14
    Output : No
 * Two methods are shown below. Second method can lead to overflow.
 * Complexity: O(d) where d is the number of bits in representation of n
 */


#include<iostream>
using namespace std;
bool everyBitSetMethod1(int n){
	// Check till number is not zero
	while(n){
		// check if rightmost bit is set. If not set return false
		if((n & 1)==0)
			return false;
		// rightshift n so that we can check next bit in next iteartion
		n=n>>1;
	}
	// if control reaches here means every bit is set so return true
	return true;
}

bool everyBitSetMethod2(int n){
	// if n is 0 return false
	if(n==0)
		return false;
	// Otherwise add 1 to n. If number would have all bits set, then adding 1 to it would
	// result into a number which is perfect power of two. That is its one bit will be set only
	// so and it with n to check if we get zero. If we get zero, return true else return false
	if( ((n+1) & n ) == 0)
		return true;
	return false;
}

int main()
{
	int test; 
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		if(everyBitSetMethod2(n))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
