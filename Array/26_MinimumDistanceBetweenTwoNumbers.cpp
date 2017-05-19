/*
 * Given an unsorted array and two numbers x and y, find the minimum distance between x and y
 * Naive solution: Pick pairs by two loops and check if one is x and other is y, and thus maintaining smallest distance
 * Complexity: O(n^2)
 * Note that we don't need to make compare of every pairs, we just need to check adjacent x and y for minimum distance
 * Method 2 uses this approach by maintaining two indexes, one for jumping to x and other to y, and then tracking their distance
 * Complexity:O(n)
 */

#include<bits/stdc++.h>
using namespace std;

void minimumDistance(vector<int> &arr, int x, int y){
	int n=arr.size();
	int i=-1,j=-1,diff=n;
	for(int k=0;k<n;k++){
		if(arr[k]==x){
			i=k;
		}
		else if(arr[k]==y){
			j=k;
		}
		if(i!=-1 && j!=-1 && abs(i-j)<diff)
			diff=abs(i-j); 
	}
	if(diff==n)
		cout<<"Elements not found\n";
	else
		cout<<"Difference:"<<diff<<endl;
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n,x,y;
		cin>>n>>x>>y;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		minimumDistance(arr,x,y);

	}
}
