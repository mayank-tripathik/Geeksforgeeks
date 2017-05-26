#include<bits/stdc++.h>
using namespace std;

class Stack{
	queue<int> q;
public:
	void push(int x){
		int size=q.size();
		q.push(x);
		while(size--){
			int x=q.front();
			q.pop();
			q.push(x);
		}
	}
	bool empty(){
		if(q.empty())
			return true;
		else
			return false;
	}
	int top(){
		return q.front();
	}
	void pop(){
		q.pop();
	}
};

int main(){
	Stack s;
	s.push(1);
	s.push(2);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
}
