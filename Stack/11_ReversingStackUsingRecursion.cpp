#include<bits/stdc++.h>
using namespace std;

void pushBottom(stack<int> &s, int x){
	if(s.empty()){
		s.push(x);
	}
	else{
		int y=s.top();
		s.pop();
		pushBottom(s,x);
		s.push(y);
	}
}
void reverse(stack<int> &s, int n){
	if(s.empty())
		return;
	else{
		int x=s.top();
		s.pop();
		reverse(s,n);
		pushBottom(s,x);
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
        reverse(s,n);
        while(!s.empty()){
        	cout<<s.top()<<endl;
        	s.pop();
        }
    }
    return 0;
}
