#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr, int low, int high){
	for(int i=low;i<=high;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int longestBitonicSequenceGFG(vector<int> &arr){
	int n=arr.size();
	vector<int> leftIncrease(n),rightIncrease(n);
	leftIncrease[0]=1;
	rightIncrease[n-1]=1;
	int sequenceLength=1;
	for(int i=1;i<n;i++){
		if(arr[i]>=arr[i-1])
			leftIncrease[i]=leftIncrease[i-1]+1;
		else
			leftIncrease[i]=1;
	}
	for(int i=n-2;i>=0;i--){
		if(arr[i]>=arr[i+1])
			rightIncrease[i]=rightIncrease[i+1]+1;
		else
			rightIncrease[i]=1;
	}
	for(int i=0;i<n;i++){
		if((leftIncrease[i]+rightIncrease[i]-1)>sequenceLength)
			sequenceLength=leftIncrease[i]+rightIncrease[i]-1;
	}
	return sequenceLength;
}


int bitonic(vector<int> &a){
	int maxLength = 0;
	int size=a.size();
	int flag = 0, count = 1;
	for(int i= 0 ;i<size-1;i++){
		if(flag == 0){
			if(a[i]<=a[i+1]){
				count++;
			}else if(a[i]>a[i+1]){
				flag = 1;
				count++;
			}
		}
		else if(flag == 1){
			if(a[i]>=a[i+1]){
				count++;
			}else{
				flag = 0;
				maxLength = max(maxLength, (count));
				count = 2;
			}
		}
	}
	maxLength = max(maxLength, count);
	return maxLength;
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		n=10;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			int x=rand()%20;
			arr[i]=x;
		}
		print(arr,0,n-1);
		cout<<longestBitonicSequenceGFG(arr)<<endl;
	}
}
