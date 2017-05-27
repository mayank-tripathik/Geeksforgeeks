#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

vector<int> printNextGreater(vector<int> &arr){
	int n=arr.size();
	print(arr);
	vector<int> nextGreater(n);
	stack<int> s;
	s.push(0);
	for(int i=1;i<n;i++){
		while(!s.empty() && arr[i]>arr[s.top()]){
			nextGreater[s.top()]=arr[i];
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()){
		nextGreater[s.top()]=-1;
		s.pop();
	}
	return nextGreater;
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		vector<int> nextGreater=printNextGreater(arr);
		print(nextGreater);
	}
}
