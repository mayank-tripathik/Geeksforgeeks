/* 
 * Problem: Implement data structure two stacks using single array that support push1,push2,pop1,pop2 on their respective stack.
 * We can divide the array space into two equal halves and assign the half half space to two stacks
 * Use arr[0] to arr[n/2] for stack1, and arr[n/2+1] to arr[n-1] for stack2
 * This method is inefficient use of array space. 
 * A stack push operation may result in stack overflow even if there is space available in arr[]. 
 * Efficient method is to start two stacks from two extreme corners of arr[]. 
 * Stack1 starts from the leftmost element, the first element in stack1 is pushed at index 0. 
 * The stack2 starts from the rightmost corner, the first element in stack2 is pushed at index (n-1). 
 * Both stacks grow (or shrink) in opposite direction.
 * TC: All 4 operations are O(1)
 */
.
#include<bits/stdc++.h>
using namespace std;

class stackType{
	vector<int> arr;
	int top1,top2;
public:
	stackType(int n){
		arr.resize(n);
		top1=-1;
		top2=n;
	}
	bool isStackFull(){
		return ((top2-top1)==1);
	}
	void push1(int x){
		if(isStackFull())
			cout<<"Stack1 is full!\n";
		else{
			top1++;
			arr[top1]=x;
		}
	}
	void push2(int x){
		if(isStackFull())
			cout<<"Stack2 is full!\n";
		else{
			top2--;
			arr[top2]=x;
		}
	}
	int pop1(){
		if(top1==-1)
			cout<<"Stack1 is Empty\n";
		else{
			int topElement=arr[top1];
			top1--;
			cout<<"Element popped :"<<topElement<<endl;
			return topElement;
		}
	}
	int pop2(){
		if(top2==arr.size())
			cout<<"Stack2 is Empty\n";
		else{
			int topElement=arr[top2];
			top2++;
			cout<<"Element popped :"<<topElement<<endl;
			return topElement;
		}
	}
	void print(){
		cout<<"Stack1:";
		for(int i=0;i<=top1;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		cout<<"Stack2:";
		for(int i=top2;i<arr.size();i++)
			cout<<arr[i]<<" ";
		cout<<endl;

	}
};

int main(){
	int n;
	cin>>n;
	stackType Stack(n);
	int op;
	cin>>op;
	for(int i=0;i<op;i++){
		int stackno,optype;
		cin>>stackno>>optype;
		cout<<"operation: ";
		cout<<stackno<<" "<<optype<<" ";
		if(optype==1){
			//Push operation
			int x;
			cin>>x;
			cout<<x<<endl;
			if(stackno==1)
				Stack.push1(x);
			else
				Stack.push2(x);
		}
		else{
			//Pop operation
			cout<<endl;
			if(stackno==1)
				Stack.pop1();
			else
				Stack.pop2();
		}
		cout<<endl;
		cout<<"After operation: \n";
		Stack.print();
		cout<<"------------------\n\n";
	}
	return 0;
}
