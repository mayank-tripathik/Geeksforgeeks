#include<bits/stdc++.h>
using namespace std;


// structure of a node
struct node {
	int value;
	node *next;
};

// creating node of node type dynamically
node* createNode(int x){
	node *t=(node*)malloc(sizeof(node));
	t->next=NULL;
	t->value=x;
	return t;
}

// structure of a stack with one extra information i.e minelement
struct Stack
{
	node *head;
	int minElement;
	int size;
};

// creating stack through malloc dynamically
Stack* createStack(){
	Stack *s=(Stack*)malloc(sizeof(Stack));
	s->size=0;
	s->head=NULL;
	return s;
}

// stack is empty if its size is 0
bool empty(Stack *s){
	if(s->size==0)
		return true;
	else
		return false;
}

// return the size of the stack
int size(Stack *s){
	return s->size;
}

// push funtion for our modified stack
void push(Stack *s, int x){
	node *temp;
	// it stack is empty, just set minelement and push item
	if(s->size==0)
	{
		temp= createNode(x);
		s->minElement=x;
	}
	else
	{	
		// if item is less than the top, encode it and push it.
		if(x<(s->minElement)){
			temp= createNode(2*x-(s->minElement));
			s->minElement=x;
		}
		// if item is greater it can't be minelement, so just push it
		else
			temp= createNode(x);

	}
	// pushing in front
	temp->next=s->head;
	s->head=temp;
	(s->size)++;
}

int top(Stack *s){
	// if stack top element is less than minvalue, it means minvalue is actual value, otherwise just return stack top
	if((s->head->value)<(s->minElement))
		return s->minElement;
	else
		return s->head->value;
}

void pop(Stack *s){
	// if top element value is less than min value, means minimum is being popped, so reset minimum by decoding it
	if((s->head->value)<(s->minElement))
		s->minElement=2*(s->minElement)-(s->head->value);
	node *temp=s->head;
	s->head=s->head->next;
	free(temp);
	(s->size)--;
}
int getMin(Stack *s){
	return s->minElement;
}

void print(Stack *s){
	cout<<"stack:";
	node *temp=s->head;
	while(temp){
		cout<<temp->value<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main(){
	Stack *s=createStack();
	push(s,3);
	print(s);
	cout<<"min:"<<getMin(s)<<endl;
	push(s,5);
	print(s);
	cout<<"min:"<<getMin(s)<<endl;
	push(s,2);
	print(s);
	cout<<"min:"<<getMin(s)<<endl;
	push(s,1);
	print(s);
	cout<<"min:"<<getMin(s)<<endl;
	push(s,1);
	print(s);
	cout<<"min:"<<getMin(s)<<endl;
	push(s,-1);
	print(s);
	cout<<"min:"<<getMin(s)<<endl;
	cout<<top(s)<<endl;pop(s);
	cout<<top(s)<<endl;pop(s);
	cout<<top(s)<<endl;pop(s);
	cout<<top(s)<<endl;pop(s);
	cout<<top(s)<<endl;pop(s);
	cout<<top(s)<<endl;pop(s);
}
