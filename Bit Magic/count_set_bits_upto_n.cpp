/*
 * Asked in Amazon!
 * Given a positive integer n, count the total number of set bits in binary representation of all numbers from 1 to n. 
 * Naive: O(nlogn) , Calculate set bits in each case and sum it accordingly
 * Improved approach: O(n). Calculated set bits beforehand in O(n) using bottom up manner
 * Best approach : O(logn) : Recursion occurs at most logn times
 */

/*
 * Improved O(n) approach
 */
 #include <bits/stdc++.h>
using namespace std;

int set_bits(int x){
    int count=__builtin_popcount(x);
    return count;
}

void populate(vector<int> &arr,vector<int> &cum){
    arr[0]=0;
    cum[0]=0;
    arr[1]=1;
    cum[1]=1;
    arr[2]=1;
    cum[2]=2;
    arr[3]=2;
    cum[3]=4;
    int m=2,k;
    int i=4;
    while(i<=1001)
    {
        k=pow(2,m)-1;
        for(int j=0;j<=k;j++){
            arr[i]=1+arr[j];
            cum[i]=cum[i-1]+arr[i];
            i++;
            if(i>1001)
                break;
        }
        m++;
    }
}
int main() {
	int test;
	cin>>test;
	vector<int> arr(1001);
	vector<int> cum(1001,0);
	populate(arr,cum);
	while(test--)
	{
	    int n;
	    cin>>n;
	    cout<<cum[n]<<endl;
	}
	return 0;
}
 
 
/*
 * Best solution
 */
#include<bits/stdc++.h>
using namespace std;


int count_set_bits_upto_n(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int position_of_last_set_bit=(log2(n));
    int sum_of_upper_block_where_last_set_bit_is_zero=pow(2,position_of_last_set_bit-1)*position_of_last_set_bit;
    int number_of_leftmost_set_bits=n-(pow(2,position_of_last_set_bit)-1);
    int sum=sum_of_upper_block_where_last_set_bit_is_zero+number_of_leftmost_set_bits;
    return sum+count_set_bits_upto_n(n-pow(2,position_of_last_set_bit));
}

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        cout<<count_set_bits_upto_n(n)<<endl;
    }
    
}
