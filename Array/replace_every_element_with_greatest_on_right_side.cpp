/*
 * Given an array of integers, replace every element with the next greatest element (on the right side) in the array. 
 * Since there is no element next to the last element, replace it with -1.
 * Naive solution: O(n^2)
 * The idea is to start from the rightmost element, move to the left side one by one, and keep track of the maximum element.
 * Then Replace every element with the maximum element.
 */


#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int max=arr[n-1];
        arr[n-1]=-1;

        for(int i=n-2;i>=0;i--){
            int prev_max=max;
            if(arr[i]>max)
                max=arr[i];
            arr[i]=prev_max;
        }
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    
}
