/*
 * Given an expression in RPN aka Postfix notation , evaluate it
 */

#include<bits/stdc++.h>
using namespace std;

int evaulate(int x, int y, char c){
	if(c=='^')
		return (pow(x,y));
	else if(c=='/')
		return (x/y);
	else if(c=='*')
		return (x*y);
	else if(c=='-')
		return (x-y);
	else 
		return (x+y);
}

int postfixEvaluation(string &exprPostfix){
	stack<int> operandStack;
	for(int i=0;i<exprPostfix.size();i++){
		if(exprPostfix[i]>='1' && exprPostfix[i]<='9')
			operandStack.push(exprPostfix[i]-'0');
		else{
			int operand1=operandStack.top();
			operandStack.pop();
			int operand2=operandStack.top();
			operandStack.pop();
			int res=evaulate(operand1,operand2,exprPostfix[i]);
			operandStack.push(res);
		}
	}
	int result=operandStack.top();
	operandStack.pop();
	return result;
}
int main(){
	int test;
	cin>>test;
	while(test--){
		string exprPostfix;
		cin>>exprPostfix;
		cout<<postfixEvaluation(exprPostfix)<<endl;

	}
}
