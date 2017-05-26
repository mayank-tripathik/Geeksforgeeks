#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *next;
};

class Stack{
	node *front;
public:
	Stack(){
		front=NULL;
	}
	bool isEmpty(){
		if(front==NULL)
			return true;
		else
			return false;
	}
	void push(int x){
		node *temp=new node();
		temp->data=x;
		temp->next=NULL;
		temp->next=front;
		front=temp;
		cout<<x<<" is pushed to stack\n";
	}
	int top(){
		if(!isEmpty())
			cout<<"Top element is: "<<front->data<<endl;
		else
			cout<<"Stack is Empty!\n";
	}
	void pop(){
		if(!isEmpty()){
			node *temp=front;
			front=front->next;
			delete temp;
			cout<<"Element is popped!\n";
		}
		else
			cout<<"Stack is Empty!\n";		
	}

};

int main(){
	int test;
	cin>>test;
	while(test--){
		Stack mystack;
		mystack.push(2);
		mystack.push(3);
		mystack.top();
		mystack.pop();
		mystack.top();
		mystack.pop();
	}
}
