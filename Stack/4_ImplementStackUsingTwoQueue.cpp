#include<bits/stdc++.h>
using namespace std;

// Making push operation costlier i.e O(n)
class StackByQueue{
	queue<int> q1;
	queue<int> q2;
public:
	void push(int x){
		// Element is always pushed to q1
		q1.push(x);
		// Elements of q2 (which resembles the stack) are then dequeued and enqueued to q1
		// q1 thus resembles the stack now
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}
		// To avoid transfer of elements again to q2, rename q1 as q2 and q2 as q1
		// In this way elements are always popped from q2 and always pushed to q1
		queue<int> temp=q1;
		q1=q2;
		q2=temp;
	}
	bool empty(){
		return (q2.empty());
	}
	int top(){
		return q2.front();
	}
	void pop(){
		q2.pop();
	}
};

//Making pop operation costlier i.e O(n)
class StackByQueue{
	queue<int> q1;
	queue<int> q2;
public:
	// Element is always pushed to q1
	void push(int x){
		q1.push(x);
	}
	bool empty(){
		return (q1.empty());
	}
	int pop(){
		// Size of q1 is maintained in such a way that last element should left on popping
		int size=q1.size()-1;
		// dequeue all element, except last, from q1 and enqueue them to q2
		for(int i=0;i<size;i++){
			q2.push(q1.front());
			q1.pop();
		}
		// store value of last element of q1 and pop it
		int x=q1.front();
		q1.pop();
		// renaming both queues so that again pushing to only q1 is needed
		queue<int> temp=q1;
		q1=q2;
		q2=temp;
		return x;
	}
	// Top uses pop and then again pushed the same element
	int top(){
		int x=pop();
		q1.push(x);
		return x;
	}
};


int main(){
	StackByQueue s;
	s.push(1);
	s.push(2);;
	s.push(3);
	s.push(5);
	s.push(6);;
	s.push(7);
	cout<<s.top()<<endl;s.pop();
	cout<<s.top()<<endl;s.pop();
	cout<<s.top()<<endl;s.pop();
	cout<<s.top()<<endl;s.pop();
	cout<<s.top()<<endl;s.pop();
	cout<<s.top()<<endl;s.pop();
	s.push(14);
	s.push(25);;
	s.push(3);
	s.push(59);
	cout<<s.top()<<endl;s.pop();
	cout<<s.top()<<endl;s.pop();
	cout<<s.top()<<endl;s.pop();
	cout<<s.top()<<endl;s.pop();
}
