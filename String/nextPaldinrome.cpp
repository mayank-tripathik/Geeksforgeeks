#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void print(vector<int> &vec){
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";
	cout<<endl;
}

void mirrorNumber(vector<int> &num, bool* mirrorIsGreater, int *middle1, int* middle2){
	if(num.size()%2!=0){
		int middle=num.size()/2;
		*middle1=*middle2=middle;
		if(num[middle-1]>num[middle+1])
			*mirrorIsGreater=true;
	}
	else{
		int middle=num.size()/2;
		*middle1=middle-1;
		*middle2=middle;
		if(num[middle-1]>num[middle])
			*mirrorIsGreater=true;
	}
	for(int i=0,j=num.size()-1;i<j;i++,j--){
		num[j]=num[i];
	}
}

void convertMirrorToNextPalindrome(vector<int>& num, int pos1, int pos2) {
	if (pos1 < 0) {
		num[num.size()-1] = 1;
		num.insert(num.begin(), 1);
		return;
   	} else if (num[pos1] < 9) {
      		num[pos1] = num[pos2] = num[pos1] + 1;
      		return;
   	} else {
     		num[pos1] = num[pos2] = 0;
      		convertMirrorToNextPalindrome(num, pos1-1, pos2+1);
      		return;
   	}
}


void nextPalindrome(vector<int> &num){
	bool mirrorIsGreater=false;
	int middle1,middle2;
	mirrorNumber(num,&mirrorIsGreater,&middle1,&middle2);
	if(mirrorIsGreater)
		return;
	else{
		convertMirrorToNextPalindrome(num,middle1,middle2);
	}
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> num(n);
		for(int i=0;i<n;i++)
			cin>>num[i];
		print(num);
		nextPalindrome(num);
		print(num);
	}
	return 0;
}
