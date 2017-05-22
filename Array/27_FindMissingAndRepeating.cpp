/*
 * Problem: Given an unsorted array of number in range 1-n, one number is missing and one is repeating, find them.
 * Solution: Sorting the array and then traversing will do the job but is O(nlogn)
 * Since array numbers are in range 1-n, we can keep track of every number by making its (value-1)th index negative
 * That element will be repeated whose (value-1)th index is already -ve before doing.
 * Missing can be found in another scan by checking index whose value is positive. That index+1 will be the missing value
 * TC: O(n)
 * Other method: Sum formula
 */
 #include<bits/stdc++.h>
using namespace std;


int repeatingNumber(vector<int> &arr){
	int repeating=-1;
	for(int i=0;i<arr.size();i++){
		//for every array value, its (value-1)th index is made -ve to keep track of repetition
		int index=abs(arr[i])-1;
		//if it is already -ve, means it is the repeated value
		if(arr[index]<0){
			repeating=abs(arr[i]);
			break;
		}
		else
			arr[index]= -arr[index];
	}
	return repeating;
}

int missingNumber(vector<int> &arr){
	int missing=-1;
	//traversing array to check the positive value. Only value of that index will be positive 
	// which is not made -ve in repeatingNumber function
	for(int i=0;i<arr.size();i++){
		if(arr[i]>0)
			missing=i+1;
		else
			arr[i]=-arr[i];
	}
	return missing;
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
		int repeating,missing;
		repeating=repeatingNumber(arr);
		missing=missingNumber(arr);
		cout<<"repeating:"<<repeating<<" and missing:"<<missing<<endl;
	}
}
