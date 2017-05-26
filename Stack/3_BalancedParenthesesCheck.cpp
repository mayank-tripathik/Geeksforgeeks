/*
 * Given an expression containing all three type of parentheses, [] , () and {}
 * Check if expression made by them is balanced
 */

#include<bits/stdc++.h>
using namespace std;

char matchingParenthesis(char c){
	if(c==')')
		return '(';
	else if(c==']')
		return '[';
	else
		 return '{';
}

bool isExpressionParenthesesBalanced(string &expression){
	stack<char> opStack;
	for(int i=0;i<expression.size();i++){
		if(expression[i]=='(' || expression[i]=='[' || expression[i]=='{')
			opStack.push(expression[i]);
		else if(expression[i]==')' || expression[i]==']' || expression[i]=='}'){
			if(opStack.empty())
				return false;
			else if(opStack.top()!=matchingParenthesis(expression[i]))
				return false;
			else
                opStack.pop();
		}
	}
	if(!opStack.empty())
		return false;
	else
		return true;
}

int main(){
	int test;
	cin>>test;
	while(test--){
		string expression;
		cin>>expression;
		if(isExpressionParenthesesBalanced(expression))
			cout<<"Balanced\n";
		else
			cout<<"Not Balanced\n";
	}
}
