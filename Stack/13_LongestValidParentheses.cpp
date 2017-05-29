#include<bits/stdc++.h>
using namespace std;

int longestValidParentheses(string &expr){
	int MaxParenthesesLength=0;
	stack<int> s;
	s.push(-1);
	for(int i=0;i<expr.size();i++){
		if(expr[i]=='(')
			s.push(i);
		else{
			s.pop();
			if(!s.empty())
				MaxParenthesesLength=max(MaxParenthesesLength,i-s.top());
			else
				s.push(i);
		}
	}
	return MaxParenthesesLength;
}

int main()
{
    int test;
    cin>>test;
    while(test--){
    	string expr;
    	cin>>expr;
    	cout<<longestValidParentheses(expr)<<endl;
    }
    return 0;
}
