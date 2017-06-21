/*
 * Given an input string, write a function that returns the Run Length Encoded string for the input string.
 * For example, if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6”.
 * Algorithm:
  a) Pick the first character from source string.
  b) Append the picked character to the destination string.
  c) Count the number of subsequent occurrences of the picked character and append the count to destination string.
  d) Pick the next character and repeat steps b) c) and d) if end of string is NOT reached.
 * TC:O(n)
 */

#include<bits/stdc++.h>
using namespace std;

// Function to convert an integer to string
string integerToString(int n){
	string num="";
	while(n){
		int digit=n%10;
		char c=digit+'0';
		num=c+num;
		n=n/10;
	}
	return num;
}

string runLengthEncoding(string &str){
	// This is the result string, intialized as empty
	string encodedString="";
	// n is the length of string
	int n=str.size();
	// Take each character of given string one by one
	for(int i=0;i<n;i++){
		char c=str[i];
		// Append it to result string
		encodedString+=c;
		// This variable will store the number of times the current character is consecutively repeated
		int count=1;
		// Count the consecutive ocurence of current character
		while(i+1<n && str[i+1]==c){
			i++;
			count++;
		}
		// Convert the integer count to string count so that we can append it to result string
		string numCount=integerToString(count);
		// append count to our result string
		encodedString.append(numCount);
	}
	// return run length encoded string
	return encodedString;
}

int main (){
	int test;
	cin>>test;
	while(test--){
		string str;
		cin>>str;
		cout<<"Given String: "<<str<<endl;
		cout<<"Encoded String: "<<runLengthEncoding(str)<<endl;
	}
}
