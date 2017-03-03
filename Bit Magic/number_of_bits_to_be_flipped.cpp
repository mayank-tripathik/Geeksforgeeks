/*
 * Count number of bits to be flipped to convert A to B
 * Asked in Samsung and Amazon
 * 1. Calculate XOR of A and B.      
        a_xor_b = A ^ B
   2. Count the set bits in the above calculated XOR result.
        countSetBits(a_xor_b)
 */
 
#include <iostream>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--){
	    int a,b;
	    cin>>a>>b;
	    int n=(a ^ b);
	    n=__builtin_popcount(n);
	    cout<<n<<endl;
	}
	return 0;
}
