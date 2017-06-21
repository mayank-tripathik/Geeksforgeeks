/*
 * Given three strings A, B and C. 
 * Write a function that checks whether C is an interleaving of A and B.
 * C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual 
 * strings is preserved.
 * Following is O(m+n) approach and works only if the two strings have no duplicates. If duplicates exists, we have to use the
 * DP solution. Example : if string A = “AAB”, string B = “AAC” and string C = “AACAAB”, then the above method will return false.
 */

#include<bits/stdc++.h>
using namespace std;

// This program will check if str is interleaved of str1 and str2
bool interleavedOf(string &str, string &str1, string &str2){
	int i=0,j=0,k;
	// Take each character of str
	for(k=0;k<str.size();k++){
		// Check if it is first char of str1, if it is we will take next char of str1 in next iteration
		if(i<str1.size() && str1[i]==str[k])
			i++;
		// else Check if it is first char of str2, if it is we will take next char of str2 in next iteration
		else if(j<str2.size() && str2[j]==str[k])
			j++;
		// If it is neither from str1 nor from str2, return false
		else
			return false;
	}
	// At last check if any of the char in both string remains or not, if remains, return false, else return true
	// This is to ensure that all chars of both string are used in forming interleaved string
	if(i<str1.size() || j<str2.size())
		return false;
	else
		return true;
}

int main (){
	int test;
	cin>>test;
	while(test--){
		string str,str1,str2;
		cin>>str>>str1>>str2;
		if(interleavedOf(str,str1,str2))
			cout<<"YES\n";
		else
			cout<<"NO\n";
		//cout<<str<<endl;
	}
}
