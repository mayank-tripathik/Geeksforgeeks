/*
 * Given a string S of brackets, the task is to find an index k which decides the number of opening brackets is equal to the number of 
 * closing brackets.
 * String must be consists of only opening and closing brackets i.e. ‘(‘ and ‘)’.
 * An equal point is an index such that the number of opening brackets before it is equal to the number of closing brackets 
 * from and after.
 * Example : 
    Input : S = "(())))("
    Output:   4
    After index 4, string splits into (()) and ))(.
    Number of opening brackets in the first part 
    is equal to number of closing brackets in the second part.

    Input : S = "))"
    Output: 2
    As after 2nd position i.e. )) and "empty" string will be 
    split into these two parts. So, in this number of opening
    brackets i.e. 0 in the first part is equal to number 
    of closing brackets in the second part i.e. also 0.
  * We can use two pointer method to match brackets from left and right in such a way that one pointer advances only if their
  * matching bracket exist at the other pointer.
  * TC:O(n)
  */

#include<iostream>
using namespace std;
int findEqualPoint(string &str){
	int i,j;
	for(i=0,j=str.size()-1;i<j;){
		// If left bracket is opening but right is not closing, decrement right index
		if(str[i]=='(' && str[j]=='('){
			j--;
		}
		// If right bracket is closing but right is not opening, decrement right index
		else if(str[i]==')' && str[j]==')'){
			i++;
		}
		// else if left is opening and right is closing or if left is closing and right is opening
		// increment left and decrement right pointer
		else{
			i++;
			j--;
		}
	}
	// If i and j have crossed over each other, means number of opening and closing are equal
	// return i'th index
	if(i!=j){
		return i;
	}
	// If i and j are equal, the consider i'th bracket and then return answer accordingly
	else
	{
		// if i'th bracket is opening that include it in right part, hence return i
		if(str[i]=='(')
			return i;
		// if is closing then return i+1 so that it is included in left part
		else
			return i+1;
	}
}
int main()
{
	int test;
	cin>>test;
	while(test--){
		string str;
		cin>>str;
		cout<<findEqualPoint(str)<<endl;
	}
	return 0;
}
