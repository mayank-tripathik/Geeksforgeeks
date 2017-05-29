#include<bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &s, int item){
	if(s.empty() || item>=s.top()){
		s.push(item);
	}
	else{
		int x=s.top();
		s.pop();
		sortStack(s,item);
		s.push(x);
	}
}

void reverse(stack<int> &s){
	if(s.empty())
		return;
	else{
		int x=s.top();
		s.pop();
		reverse(s);
		sortStack(s,x);
	}
}

int main()
{
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        stack<int> s;
        for(int i=0;i<n;i++){
        	int x;
        	cin>>x;
        	s.push(x);
        }
        reverse(s);
        while(!s.empty()){
        	cout<<s.top()<<endl;
        	s.pop();
        }
    }
    return 0;
}
