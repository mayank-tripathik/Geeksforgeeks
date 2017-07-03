/*
 * We can multiply a number by 7 using bitwise operator. First left shift the number by 3 bits (you will get 8n) then subtract the 
 * original number from the shifted number and return the difference (8n – n).
 * To avoid overflow we can also do it as: n + (n<<1) + (n<<2);
 * Following implementation works only for positive integers
 * We can use the same approach for multiplying different number effficiently
 *  multiply with 2 n<<1
    multiply with 3 (n<<1)+n
    multiply with 4 (n<<2)
    multiply with 5 (n<<2)+n
    multiply with 6 (n<<2)+(n<<1)
    multiply with 7 (n<<3)-n
    multiply with 8 (n<<3)
    multiply with 9 (n<<3)+n
    multiply with 10 (n<<3)+(n<<1)
 * Should we really use these methods to multiply instead of our regular multilplication operator? Not likely. Compiler has an 
 * optimizer in it that knows how to multiply as quickly as your target processor architecture is capable. Your best bet is to 
 * tell the compiler your intent clearly (i.e. i*2 rather than i << 1) and let it decide what the fastest assembly/machine code 
 * sequence is. It's even possible that the processor itself has implemented the multiply instruction as a sequence of shifts & 
 * adds in microcode.
*/

# include<stdio.h>
 
int multiplyBySeven(unsigned int n)
{  
    /* Note the inner bracket here. This is needed 
       because precedence of '-' operator is higher 
       than '<<' */
    return ((n<<3) - n);
}
 
/* Driver program to test above function */
int main()
{
    unsigned int n = 4;
    printf("%u", multiplyBySeven(n));
 
    getchar();
    return 0;
}


/* What if no arithmetic operators are allowed */

#include <iostream>
using namespace std;
int add(int x,int y)
{
    while(y!=0)
    {
        int carry=x&y;
        x=x^y;
        y=carry<<1;
    }
    return x;
}
int mul(int a)
{
    return add(a<<3,~a);
}
int main() {
    int a=5,b=7;
    cout<<add(mul(a),1); return="" 0;="" 
}
