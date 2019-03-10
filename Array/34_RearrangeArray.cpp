/*
 * Given an array of elements of length N, ranging from 0 to N-1, your task is to write a program that rearranges the elements 
 * of the array. All elements may not be present in the array, if element is not present then there will be -1 present in the 
 * array. Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.
 * Input : arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1}
 * Output : [-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]
 * Input : arr = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8, 11, 10, 9, 5, 13, 16, 2, 14, 17, 4}
 * Output : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11, 12, 13, 14, 15, 16, 17, 18, 19]
  */

#include<iostream>
#include<vector>
using namespace std;

void rearrange(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        
        // if element is already organized or -1 is there then skip
        // otherwise go inside the loop
        if(arr[i]!=-1 && arr[i]!=i){
            // store the current value and set it -1
            int value = arr[i];
            arr[i] = -1;
            // recursively go to each index value, store already
            // existing value in temp, set it and go to temp value
            // if it is not -1 and not already set
            while(1){
                int temp = arr[value];
                arr[value] = value;
                if((value == temp) || temp==-1)
                    break;
                else
                    value = temp;
            }
        }
    }
}

void print(vector<int> &arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    rearrange(arr);
	    print(arr);
	}
	return 0;
}
