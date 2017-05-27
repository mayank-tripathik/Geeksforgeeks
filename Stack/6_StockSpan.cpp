#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

vector<int> firstGreaterInRight(vector<int> &arr){
	int n=arr.size();
	stack<int> s;
	vector<int> firstGreater(n);
	s.push(n-1);
	print(arr);
	for(int i=n-2;i>=0;i--){
		while(!s.empty() && arr[i]>arr[s.top()]){
			firstGreater[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()){
		firstGreater[s.top()]=-1;
		s.pop();
	}
	return firstGreater;
}

vector<int> stockSpan(vector<int> &arr){
	vector<int> span=firstGreaterInRight(arr);
	for(int i=0;i<arr.size();i++){
		span[i]=i-span[i];
	}
	return span;
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
		vector<int> span=stockSpan(arr);
		print(span);
	}
}
