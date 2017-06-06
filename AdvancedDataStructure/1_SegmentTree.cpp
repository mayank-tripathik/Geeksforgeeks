#include<bits/stdc++.h>
using namespace std;

class segmentTree{
	vector<int> tree;
public:
	segmentTree(int n){
		int size;
		int i=0;
		while(pow(2,i)<n)
			i++;
		size=(2*pow(2,i))-1;
		tree.resize(size, INT_MAX);
	}
	void buildTreeHelper(vector<int> &arr, int low, int high, int pos){
		if(low==high){
			tree[pos]=arr[low];
			return;
		}
		int mid=(low+high)/2;
		buildTreeHelper(arr,low,mid,2*pos+1);
		buildTreeHelper(arr,mid+1,high,2*pos+2);
		tree[pos]=min(tree[2*pos+1],tree[2*pos+2]);
	}
	void buildTree(vector<int> arr){
		int low=0;
		int high=arr.size()-1;
		int pos=0;
		buildTreeHelper(arr,low,high,pos);
	}
	int minimumRangeQueryHelper(int qLow, int qHigh, int low, int high, int pos){
		if(qLow<=low && qHigh>=high)
			return tree[pos];
		else if(qLow>high || qHigh<low)
			return INT_MAX;
		int mid=(low+high)/2;
		return min(minimumRangeQueryHelper(qLow,qHigh,low,mid,2*pos+1),
				minimumRangeQueryHelper(qLow,qHigh,mid+1,high,2*pos+2));
	}
	int minimumRangeQuery(int qLow, int qHigh, int n){
		return minimumRangeQueryHelper(qLow,qHigh,0,n-1,0);
	}
	void print(){
		for(int i=0;i<tree.size();i++)
			cout<<tree[i]<<" ";
		cout<<endl;
	}
};

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	segmentTree tree(n);
	tree.buildTree(arr);
	tree.print();
	cout<<tree.minimumRangeQuery(3,6,n)<<endl;
	return 0;
}
