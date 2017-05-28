#include<bits/stdc++.h>
using namespace std;
     
class Stack{
	stack<int> elementStack;
	stack<int> minStack;
public:
	void push(int x){
		elementStack.push(x);
		if(minStack.empty())
			minStack.push(x);
		else if(x<minStack.top())
			minStack.push(x);
	}
	bool empty(){
		return elementStack.empty();
	}
	void pop(){
		int x=elementStack.top();
		elementStack.pop();
		if(x==minStack.top())
			minStack.pop();
	}
	int top(){
		return elementStack.top();
	}
	int getMin(){
		return minStack.top();
	}
};

int main(){
	Stack s;
	s.push(14);
	s.push(4);
	s.push(10);
	s.push(2);
	s.push(9);
	cout<<s.top()<<endl;s.pop();
	cout<<s.getMin()<<endl;
	cout<<s.top()<<endl;s.pop();
	cout<<s.getMin()<<endl;
	cout<<s.top()<<endl;s.pop();
	cout<<s.getMin()<<endl;
	cout<<s.top()<<endl;s.pop();
	cout<<s.getMin()<<endl;
}
