/*
 * Implement queue using stacks
 * TC: One queue operation is O(n), other is O(1)
 */

#include<bits/stdc++.h>
using namespace std;

/*Method 1 : Using 1 user stack and one function call stack*/
class QueueByStack{
	stack<int> stack1;
public:
	//simply pushing the element
	void enqueue(int x){
		stack1.push(x);
		cout<<x<<" is enqueued\n";
	}
	//Recursively pop all elements until one element left
	void dequeue(){
		//If stack is empty, means queue is underflow
		if(stack1.empty()){
			cout<<"Queue is empty\n";
		}
		//if one element left, then this is front of queue. Print and discard it.
		else if(stack1.size()==1){
			int x=stack1.top();
			stack1.pop();
			cout<<"Front element is: "<<x<<endl;
			return;
		}
		//recursively pop elements(until one left) and then push them back again
		else{
			int temp=stack1.top();
			stack1.pop();
			dequeue();
			stack1.push(temp);
		}
	} 

};


/*Method 2 : 2 user stacks are used, with enqueue operation as the costly one*/
class QueueByStack{
	stack<int> stack1;
	stack<int> stack2;
public:
	void enqueue(int x){
		// Stack1 elements are first trasnferred to stack2
		while(!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
		// New element is pushed to stack1
		stack1.push(x);
		// Elements of stack1 are again restored from stack2. In this way new element moves to the bottom of the stack1.
		// and oldest one remains at top
		while(!stack2.empty()){
			stack1.push(stack2.top());
			stack2.pop();
		}
		cout<<x<<" is enqueued\n";
	}
	//Simply pop the element from the stack1 as it is the oldest element. This property is maintained by above enqueue operation
	void dequeue(){
		if(!stack1.empty()){
			cout<<"Front element is: "<<stack1.top()<<endl;
			stack1.pop();
		}
		else
			cout<<"Queue is empty\n";
	}
};



/* Method 3 : 2 user stacks are used, with dequeue operation as the costly one. 
 * Method 2 moves all the elements twice in enQueue operation while method 3 (in deQueue operation) moves the elements once 
 * and moves elements only if stack2 empty. Hence method 3 is the preferred one
 */
class QueueByStack{
	stack<int> stack1;
	stack<int> stack2;
public:
	//Elements are always pushed to stack1
	void enqueue(int x){
		stack1.push(x);
		cout<<x<<" is enqueued\n";
	}
	//Elements are always dequeued from stack2
	void dequeue(){
		//If stack2 has elements, simply return the top one. Top one is oldest as this property is maintained by the below step
		if(!stack2.empty()){
			int x=stack2.top();
			stack2.pop();
			cout<<"Front element is: "<<x<<endl;
		}
		// if stack2 is empty, transfer all elements from stack1 to stack2. In this way, oldest elements from stack1
		// comes at the top of stack2 and queue property will be satisfied
		else if(!stack1.empty()){
			while(!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
			int x=stack2.top();
			stack2.pop();
			cout<<"Front element is: "<<x<<endl;
		}
		//Both stacks are empty, means queue underflow 
		else{
			cout<<"Queue is empty\n";
		}
	}
};

int main(){
	QueueByStack queue;
	queue.dequeue();
	queue.dequeue();
	queue.enqueue(1);
	queue.enqueue(2);
	queue.dequeue();
	queue.enqueue(4);
	queue.enqueue(5);
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.enqueue(9);
	queue.enqueue(10);
	queue.dequeue();
	queue.dequeue();
}
