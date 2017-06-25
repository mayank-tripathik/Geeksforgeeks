/*
 * Find and print the uncommon characters of the two given strings.
 * Here uncommon character means that either the character is present in one string or the other string but not in both.
 * The strings contain only lowercase characters and can contain duplicates.
 * Brute force solution is to pick each char of string 1 and check its presence in string2, which is O(N^2)
 * We can use hashing to solve it efficently. We can hash the presence of characters of each string and then print those
 * that are present in only one of them, by using xor
 * TC:O(n)
 */

#include<iostream>
#include<vector>
using namespace std;

// Function that prints the uncommon character between two strings str1 and str2
void uncommonChar(string &str1,string &str2){
	// create two arrays of size 26, the number of possible lower apha characters
	// Initialize them as false
	vector<int> hash1(26,false);
	vector<int> hash2(26,false);
	// Mark the presence of each char of string1
	for(int i=0;i<str1.size();i++)
		hash1[str1[i]-'a']=true;
	// Mark the presence of each char of string2
	for(int i=0;i<str2.size();i++){
		hash2[str2[i]-'a']=true;
	}
	// Iterate over each char and check if it present in only one of the string, using xor
	// if it is then only print it otherwise discard it
	for(int i=0;i<26;i++)
	{
		hash1[i]=hash1[i] xor hash2[i];
		if(hash1[i]){
			char c=i+'a';
			cout<<c;
		}
	}
	cout<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		string str1,str2;
		cin>>str1>>str2;
		uncommonChar(str1,str2);
	}
	return 0;
}
