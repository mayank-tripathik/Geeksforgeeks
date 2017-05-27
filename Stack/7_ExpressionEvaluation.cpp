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

int evaluate(int x, int y, char c){
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

int popAndEvaluate(stack<char> &operatorStack, stack<int> &operandStack){
	char oprtr=operatorStack.top();
	operatorStack.pop();
	int operand2=operandStack.top();
	operandStack.pop();
	int operand1=operandStack.top();
	operandStack.pop();
	int tempResult=evaluate(operand1,operand2,oprtr);
	return tempResult;
}

int expressionEvaluation(string &expr){
	stack<char> operatorStack;
	stack<int> operandStack;
	for(int i=0;i<expr.size();i++){
		if(expr[i]>='0' && expr[i]<='9')
			operandStack.push(expr[i]-'0');
		else if(expr[i]=='(')
			operatorStack.push(expr[i]);
		else if(expr[i]==')'){
			while(!operatorStack.empty() && operatorStack.top()!='('){
				int tempResult=popAndEvaluate(operatorStack,operandStack);
				operandStack.push(tempResult);
			}
			operatorStack.pop();
		}
		else{
			while(!operatorStack.empty() && precedence(expr[i])<precedence(operatorStack.top())){
				int tempResult=popAndEvaluate(operatorStack,operandStack);
				operandStack.push(tempResult);
			}
			operatorStack.push(expr[i]);
		}
	}
	while(!operatorStack.empty()){
		int tempResult=popAndEvaluate(operatorStack,operandStack);
		operandStack.push(tempResult);
	}
	return operandStack.top();
}

int main(){
	int test;
	cin>>test;
	while(test--){
		string expr;
		cin>>expr;
		cout<<expressionEvaluation(expr)<<endl;

	}
}
