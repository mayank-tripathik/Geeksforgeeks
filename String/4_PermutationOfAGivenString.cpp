#include<bits/stdc++.h>
using namespace std;

void permute(string &str,string &temp,vector<bool> &flag){
	if(temp.size()==str.size()){
		cout<<temp<<endl;
		return;
	}
	for(int i=0;i<str.size();i++){
		if(flag[i]==false){
			flag[i]=true;
			string temp1=temp;
			temp=temp+str[i];
			permute(str,temp,flag);
			flag[i]=false;
			temp=temp1;
		}
	}
}

void permute(string &str, int k){
	if(k==str.size()){
		cout<<str<<" ";
		return;
	}
	for(int i=k;i<str.size();i++){
		swap(str[i],str[k]);
		permute(str,k+1);
		swap(str[i],str[k]);
	}

}

int main()
{
	int test;
	cin>>test;
	while(test--){
		string str;
		cin>>str;
		vector<bool> flag(str.size(),false);
		string temp="";
		permute(str,temp,flag);
		permute(str,0);
	}
	return 0;
}
