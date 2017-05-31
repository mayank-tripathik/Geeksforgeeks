#include<iostream>
#include<cstdlib>
using namespace std;

struct Queue
{
	struct ListNode
	{
		int value;
		ListNode* next;	
	};
	ListNode* front;
	ListNode *rear;
	int size;
	Queue(){
		front=rear=NULL;
		size=0;
	}
	ListNode* newNode(int x){
		ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
		temp->value=x;
		temp->next=NULL;
		return temp;
	}
	bool empty(){
		return (size==0);
	}
	void push(int x){
		ListNode* temp=newNode(x);
		if(size==0)
			rear=front=temp;
		else{
			rear->next=temp;
			rear=rear->next;
		}
		size++;
	}
	int getFront(){
		return front->value;
	}
	void pop(){
		ListNode* temp=front;
		front=front->next;
		if(front==NULL)
			rear=NULL;
		size--;
		delete temp;
	}
	void print(){
		if(empty()){
			cout<<"List is empty!\n";
			return;
		}
		cout<<"List:";
		ListNode* temp=front;
		while(temp){
			cout<<temp->value<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
};

int main(){
	Queue q;
	q.print();
	q.push(1);
	q.print();
	q.push(2);
	q.print();
	q.push(3);
	q.print();
	q.push(4);
	q.print();
	cout<<"Popped:"<<q.getFront()<<endl;
	q.pop();
	q.print();
	cout<<"Popped:"<<q.getFront()<<endl;
	q.pop();
	q.print();
	cout<<"Popped:"<<q.getFront()<<endl;
	q.pop();
	q.print();
	cout<<"Popped:"<<q.getFront()<<endl;
	q.pop();
	q.print();
}
