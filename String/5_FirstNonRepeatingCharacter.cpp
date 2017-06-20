/*
 * Given a string, find the first non-repeating character in it. 
 * Examples:  1. If the input string is “GeeksforGeeks”, then output should be ‘f’ 
              2. If input string is “GeeksQuiz”, then output should be ‘G’.
 * We can count the occurence of each character and then again traverse the string and return the first character whose count
 * is 1. If no such char exists we can return -1
 * This approach though takes O(n) time but requires two traversal of string
 * In practice it can be improved. The first part of the algorithm runs through the string to construct the count array (in O(n))
 * This is reasonable. But the second part about running through the string again just to find the first non-repeater is not good
 * in practice. In real situations, your string is expected to be much larger than your alphabet. 
 * Take DNA sequences for example: they could be millions of letters long with an alphabet of just 4 letters. 
 * What happens if the non-repeater is at the end of the string? Then we would have to scan for a long time (again).
 * We can improve this by maintaining one extra info apart from count. We should also maintain index of the first time you 
 * encountered the character
 * So when it comes to finding the first non-repeater, we just have to scan the count array, instead of the string.
 * TC:O(n)
 */

#include<iostream>
#include<vector>
using namespace std;

// count will count the fequency of each char in the given string
// firstindex will contain the index of the first occurence of a character
struct charInfo{
	int count;
	int firstIndex;
	charInfo(){
		count=0;
		firstIndex=-1;
	}
};

void firstNonRepeatingIndex(string &str){
	vector<charInfo> hash(26);
	// count the occurence of all the characters. If char is encountered for the
	// for the first time, set its firstIndex
	for(int i=0;i<str.size();i++){
		if(hash[str[i]-'a'].count==0){
			hash[str[i]-'a'].firstIndex=i;
		}
		hash[str[i]-'a'].count++;
	}
	// This variable will contain the index of first non repeeating char in the string
	// Initialize it with some illegal value, INT_MAX or 26
	int nonRepeatingIndex=26;
	// Go through all the alphabets, and search for that whose count is 1
	// and whose first occurence index is least. It will be our answer
	for(int i=0;i<26;i++){
		if(hash[i].count==1 && hash[i].firstIndex<nonRepeatingIndex){
			nonRepeatingIndex=hash[i].firstIndex;
		}
	}
	// If our answer has still the value of 26, means no such char is found, hence print -1
	if(nonRepeatingIndex==26)
		cout<<"-1\n";
	// else print the answer
	else
		cout<<str[nonRepeatingIndex]<<endl;
}

void firstNonRepeatingIndexTwoTraverse(string  &str){
	vector<int> hash(26,0);
	// First count the occurence of each letter in the given string
	for(int i=0;i<str.size();i++)
		hash[str[i]-'a']++;
	int i;
	// Again traverse the string and if we encounter a character whose count is 1
	// break the loop, It will be the first non repeating character
	for(i=0;i<str.size();i++){
		if(hash[str[i]-'a']==1)
		{
			break;
		}
	}
	// If i is equal to string size at this point, means no such char is encountered
	// hence print -1
	if(i==str.size())
		cout<<"-1\n";
	// else print the answer
	else
		cout<<str[i]<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		string str;
		cin>>str;
		firstNonRepeatingIndex(str);
		//firstNonRepeatingIndexTwoTraverse(str);
	}
	return 0;
}
