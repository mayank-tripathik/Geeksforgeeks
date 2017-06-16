/*
 * Given two strings s1 & s2, remove those characters from first string which are present in second string. 
 * Both the strings are different and contain only lowercase characters.
 * We can use the same process we have used in removing duplicates from string. Here instead of duplicates we have to remove
 * those characters from string2 that are appearing in string1. We can thus first store the existence of chars among the total
 * 26 possible in string2, and then traverse string1 using two pointer i and j to remove and shift chars is string1
 * TC:O(n)
 */

#include<bits/stdc++.h>
using namespace std;

// This function removes all those chars from str1 that are appearing in str2
void removeSecondFromFirst(string &str1, string &str2){
	vector<int> hash(26,false);
	// Store existence of those chars among the total 26, that are appearing in string2
	for(int i=0;i<str2.size();i++)
		hash[str2[i]-'a']=true;
	// This index will keep track of the location of the next character of resultant string
	int j=0;
	// iterate over string one throught index i
	for(int i=0;i<str1.size();i++){
		int index=str1[i]-'a';
		// If char is not present in string two, place it in appropriate position using variable j
		if(hash[index]==false){
			str1[j]=str1[i];
			j++;
		}
	}
	// resize the string one to length j
	str1.resize(j);
}
int main()
{
	int test;
	cin>>test;
	while(test--){
		string str1,str2;
		cin>>str1>>str2;
		removeSecondFromFirst(str1,str2);
		cout<<str1<<endl;
	}
	return 0;
}
