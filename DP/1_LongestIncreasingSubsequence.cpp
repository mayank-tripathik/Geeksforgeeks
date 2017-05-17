#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void printLISArray(vector<int> &arr, vector<int> &parent){
	cout<<"LIS is:";
	int i=parent.size()-1;
	vector<int> LIS;
	while(parent[i]==-1)
		i--;
	if(i>=0){
			while(i>=0){
			LIS.push_back(arr[i]);
			i=parent[i];
		}
		for(int j=LIS.size()-1;j>=0;j--)
			cout<<LIS[j]<<" ";
	}
	else
		cout<<arr[0];
	cout<<endl;
}

int longestIncreasingSubsequence(vector<int> &arr){
	int n=arr.size();
	vector<int> dp(n,1);
	vector<int> parent(n,-1);
	cout<<"Array:";
	print(arr);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]>arr[i])
			{
				if(dp[i]+1>dp[j]){
					parent[j]=i;
					dp[j]=dp[i]+1;
				}
				else{
					dp[j]=max(dp[i]+1,dp[j]);

				}
			}
		}
	}
	printLISArray(arr,parent);
	return dp[n-1];
}


int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<"LIS length:"<<longestIncreasingSubsequence(arr)<<endl;
	}
}
