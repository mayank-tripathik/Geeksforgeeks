/*
 * Problem: Given an infix expression, write a program to convert it into postfix expression
 * Shunting yard algo is used to do the conversion
 * TC: O(n) where n is the length of a given Infix expression
 */

#include<bits/stdc++.h>
using namespace std;

int precedence(char c){
	if(c=='^')
		return 4;
	else if(c=='/' || c=='*')
		return 3;
	else if(c=='+' || c=='-')
		return 2;
	else
		return 1;
}

string convertInfixToPostfix(string &exprInfix){
	string exprPostfix;
	stack<char> opstack;
	for(int i=0;i<exprInfix.size();i++){
		if(exprInfix[i]>='a' && exprInfix[i]<='z')
			exprPostfix+=exprInfix[i];
		else if(exprInfix[i]=='(' || opstack.empty())
			opstack.push(exprInfix[i]);
		else if(exprInfix[i]==')'){
			while(!opstack.empty() && opstack.top()!='('){
				char c=opstack.top();
				exprPostfix+=c;
				opstack.pop();
			}
			opstack.pop();
		}
		else{
			while(!opstack.empty() && precedence(exprInfix[i])<=precedence(opstack.top())){
				char c=opstack.top();
				exprPostfix+=c;
				opstack.pop();
			}
			opstack.push(exprInfix[i]);
		}
	}
	while(!opstack.empty()){
		char c=opstack.top();
		exprPostfix+=c;
		opstack.pop();
	}
	return exprPostfix;
}
int main(){
	int test;
	cin>>test;
	while(test--){
		string exprInfix;
		cin>>exprInfix;
		cout<<convertInfixToPostfix(exprInfix)<<endl;

	}
}
