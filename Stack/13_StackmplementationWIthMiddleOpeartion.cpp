#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int value;
	node *next;
	node *previous;
public:
	node(int x){
		value=x; 
		next=previous=NULL;
	}
};

class Stack{
	node *head;
	node *middle;
	int size;
public:	
	Stack(){
		head=middle=NULL;
		size=0;
	}
	bool empty(){
		return (size==0);
	}
	void print(){
		cout<<"List: ";
		node *temp=head;
		while(temp){
			cout<<temp->value<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	void push(int x){
		node *temp=new node(x);
		temp->next=head;
		if(size!=0)
			head->previous=temp;
		head=temp;
		size++;
		if(size==1)
		 	middle=head;
		else if(size%2==0)
		 	middle=middle->previous;
	}
	int top(){
		return head->value;
	}
	int getMiddle(){
		return middle->value;
	}
	void pop(){
		node *temp=head;
		head=head->next;
		size--;
		if(size!=0)
			head->previous=NULL;
		if(size==0)
			middle=head=NULL;
		else if(size==1)
			middle=head;
		else if(size%2!=0)
			middle=middle->next;
		delete temp;
	}
	void delMiddle(){
		node *temp=middle;
		size--;
		if(size==0){
			head=middle=NULL;
			delete temp;
			return;
		}
		if(size==1){
			middle=middle->next;
			head=middle;
			head->previous=NULL;
			return;
		}
		else if(size%2==0)
			middle=middle->previous;
		else
			middle=middle->next;
		temp->previous->next=temp->next;
		temp->next->previous=temp->previous;
		delete temp;
	}

};

int main()
{
    Stack s;
    s.push(1);
    cout<<"Middle: "<<s.getMiddle()<<endl;
    cout<<"Top: "<<s.top()<<endl;

    s.push(2);
    cout<<"Middle: "<<s.getMiddle()<<endl;
    cout<<"Top: "<<s.top()<<endl;
    
    s.push(3);
    cout<<"Middle: "<<s.getMiddle()<<endl;
    cout<<"Top: "<<s.top()<<endl;
    
    s.push(4);
    cout<<"Middle: "<<s.getMiddle()<<endl;
    cout<<"Top: "<<s.top()<<endl;
    
    s.push(5);
    cout<<"Middle: "<<s.getMiddle()<<endl;
    cout<<"Top: "<<s.top()<<endl;
    
    cout<<"\n\nAfter pushes:";
    s.print();
    cout<<"Popped:"<<s.top()<<endl;s.pop();cout<<"Middle: "<<s.getMiddle()<<endl;cout<<"Top: "<<s.top()<<endl;
    cout<<"Popped:"<<s.top()<<endl;s.pop();cout<<"Middle: "<<s.getMiddle()<<endl;cout<<"Top: "<<s.top()<<endl;
    cout<<"Popped:"<<s.top()<<endl;s.pop();cout<<"Middle: "<<s.getMiddle()<<endl;cout<<"Top: "<<s.top()<<endl;
    cout<<"Popped:"<<s.top()<<endl;s.pop();cout<<"Middle: "<<s.getMiddle()<<endl;cout<<"Top: "<<s.top()<<endl;
    cout<<"Popped:"<<s.top()<<endl;s.pop();s.print();cout<<s.empty()<<endl;
    return 0;
}
