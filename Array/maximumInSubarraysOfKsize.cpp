#include<bits/stdc++.h>
using namespace std;

void maximumSumSubarrayNaive(vector<int> &arr, int k){
	int n=arr.size();
	for(int i=0;i<=n-k;i++){
		int max=i;
		for(int j=i+1;j<i+k && j<n;j++){
			if(arr[j]>arr[max])
				max=j;
		}
		cout<<arr[max]<<" ";
	}
	cout<<endl;
}

void maximumSumSubarraySliding(vector<int> &arr, int k){
	vector<int> leftMax,rightMax,windowMax;
	int max=INT_MIN;
	int window=k;
	int n=arr.size();
	//Calculating left max array
	for(int i=0;i<n;i++){
		if(arr[i]>max)
			max=arr[i];
		leftMax.push_back(max);
		window--;
		if(window==0){
			max=INT_MIN;
			window=k;
		}
	}
	max=INT_MIN;
	if(window!=k)
		window=k-window;
	//Calculating right max array
	for(int i=n-1;i>=0;i--){
		if(arr[i]>max)
			max=arr[i];
		rightMax.push_back(max);
		window--;
		if(window==0){
			max=INT_MIN;
			window=k;
		}
	}
	//populating answer using the two max arrays
	for(int i=k-1,j=n-1;i<n;i++,j--){
		int maxInWindow=((leftMax[i]>rightMax[j])?leftMax[i]:rightMax[j]);
		windowMax.push_back(maxInWindow);
	}
	for(int i=0;i<windowMax.size();i++){
		cout<<windowMax[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int test;
	cin>>test;
	while(test--){
		int n,k;
		cin>>n>>k;
		//cout<<n<<k<<endl;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		maximumSumSubarraySliding(arr,k);

	}
}
