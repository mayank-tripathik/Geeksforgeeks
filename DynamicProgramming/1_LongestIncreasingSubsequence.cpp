#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &vec){
    cout<<"LIS is : ";
    for(int i=vec.size()-1;i>=0;i--)
        cout<<vec[i]<<" ";
    cout<<endl;
}
int longestIncreasingSubsequence(vector<int> &arr){
	if(arr.size()==0)
		return 0;
    vector<int> LIS(arr.size(),1);
    vector<int> parent(arr.size(),-1);
    for(int i=1;i<arr.size();i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                if(LIS[j]+1>LIS[i]){
                    LIS[i]=1+LIS[j];
                    parent[i]=j;
                }
            }
        }
    }
    int maxIndex=0;
    for(int i=1;i<arr.size();i++){
        if(LIS[i]>LIS[maxIndex]){
            maxIndex=i;
        }
    }
    int index=maxIndex;
    vector<int> LISArray;
    while(index!=-1){
        LISArray.push_back(arr[index]);
        index=parent[index];
    }
    print(LISArray);
    return LIS[maxIndex];
}
int main() {
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<"LIS length:"<<longestIncreasingSubsequence(arr)<<endl;
    }
	return 0;
}
