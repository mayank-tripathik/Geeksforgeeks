/*
 * Given a string, remove duplicates from it. Note that original order of characters must be kept same.  
 * Expected time complexity O(n) where n is length of input string and extra space O(1)
 * Assume that there are total 256 possible characters in a string.
 * If the restriction of original order and O(n) TC is not there, we would have just sorted the string, and then remove duplicate
 * in O(n) traverse
 * We can use extra array of size 256 (that is O(1)), to keep track of whether the char has repeated or not
 * We can use to index variable i and j, one to traverse the given string and one to keep track of location of next character 
 * in the resultant string, respectively. 
 * Why to use the second index variable? So that when we encounter a char that is first visited in string, we should place 
 * it at the last index of resultant string (and then increment j to keep doing the same process)
 * So j'th value at last will be one index after the last index of resultant string. We can thus resize our string accordingly.
 * TC:O(n) and extra space O(1)
 */

#include<bits/stdc++.h>
using namespace std;

// This function works for all strings(even with spaces or special characters)
// Assumes character space of 256 chars
// It remove duplicates of every type,  be it space, alphabet or any char
void removeAllDuplicates(string &str){
	// Intitialize char space of 256 char, with their presence int string as false
	vector<int> hash(256,false);
	// This variable will keep track of the index of string before which no duplicates exists
	// It is used to fill the string with non duplicates chars that replaces the duplicate ones
	int j=0;
	for(int i=0;i<str.size();i++){
		int index=str[i];
		// If current character is visited for the first time
		if(!hash[index]){
			// replace the duplicate character by non duplicate chars
			if(i!=j)
				str[j]=str[i];
			// make char visited
			hash[index]=true;
			// increment so that when we encounter a char that is first time visited again, it is 
			// to be filled at this new j'th position.
			j++;
		}
	}
	// resize string to j characters
	str.resize(j);
}

int main(){
	int test;
	cin>>test;
	cin.ignore(1,'\n');
	while(test--){
		string str;
		getline(cin,str);
		removeAllDuplicates(str);
		cout<<str<<endl;
	}
}
