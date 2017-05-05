/*
 * Problem : Given an array, find the majority element (if it exists), otherwise print "NONE". 
 * Note: A majority element in an array A[] of size n is an element that appears more than n/2 times.
 * Solution : Bruteforce gives O(N^2). Moore voting algorithm gives majority element in O(N) by first finding candidate and then
 * checking if candidate is actually a majority element or not.
 */


/*
Sample Input: 
2
10
2 2 2 2 4 4 4 4 4 4
10
7 7 7 3 4 4 2 2 7 7
Output:
4
NONE
*/

#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

//Brute Force Implementation O(N^2)
int majorityElementBruteForce(vector<int> &arr){
	int max_repeat=-1;
	int n=arr.size();
	FOR(i,n){
		int number=arr[i];
		int repeat=0;
		FOR(j,n){
			if(arr[j]==number)
				repeat++;
		}
		if(repeat>(n/2)){
			max_repeat=repeat;
			break;
		}
	}
	return max_repeat;
}

//returns candidate for majority element
int findMajorityCandidate(vector<int> &arr){
	int count=1;
	int candidate=arr[0];
	for(int i=1;i<arr.size();i++){
		if(arr[i]==candidate){
			count++;
		}
		else if(count==1){
			candidate=arr[i];
		}
		else{
			count--;
		}
	}
	return candidate;
}

//Efficient O(N) algorithm
void mooreVoting(vector<int> &arr){
	int majorityCandidate=findMajorityCandidate(arr);
	int majorityElement;
	int repeat=0;
	for(int j=0;j<arr.size();j++){
		if(arr[j]==majorityCandidate)
			repeat++;
	}
	if(repeat>(arr.size()/2)){
		cout<<majorityCandidate<<endl;
		return;
	}
	cout<<"NONE\n";
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> arr(n);
		FOR(i,n)
			cin>>arr[i];
		mooreVoting(arr);
	}
}
