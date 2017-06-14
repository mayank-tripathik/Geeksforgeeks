/*
 * Write a program return maximum occurring character in the input string 
 * Example: if input string is “test” then function should return ‘t’. 
 * If more than one character occurs maximum number of time then print the lexicographically smaller character.
 * Solution: We can use sorting to first sort the charcaters and then traverse it linearly to find the frequency of chars
 * Efficinet solution is to use hashing. Depending upon the size of character set, we can create a hashset, wherein we could
 * hash each character we encounter. Then we can return the maximum occuring character by a single traverse
 * TC:O(n), extra space: O(1), because constant space is required
 */

#include<bits/stdc++.h>
using namespace std;

char maximumOccuringChar(string &str){
	vector<int> hash(26,0);
	int maxIndex=0;
	for(int i=0;i<str.size();i++){
		int index=str[i]-'a';
		hash[index]++;
		if(hash[index]>hash[maxIndex])
			maxIndex=index;
		else if(hash[index]==hash[maxIndex] && index<maxIndex)
			maxIndex=index;
	}
	return maxIndex+'a';
}

int main(){
	int test;
	cin>>test;
	while(test--){
		string str;
		cin>>str;
		cout<<maximumOccuringChar(str)<<endl;
	}
}
