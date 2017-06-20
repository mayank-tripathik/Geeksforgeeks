/*
 * Problem : Reverse words in a given string
 * Example: Let the input string be “i like this program very much”. 
 * The function should change the string to “much very program this like i”
 * We can use stack or array of strings to first seperate the words and then append these words in reverse.
 * TC:O(n), extra space:O(n)
 * Efficient Algorithm:
    1) Reverse the individual words, we get the below string.
         "i ekil siht margorp yrev hcum"
    2) Reverse the whole string from start to end and you get the desired output.
         "much very program this like i"
    We can also do step 2 first and step 1 after that.
 */



#include<iostream>
#include<vector>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

void reverseString(string &str, int start, int end){
	for(int i=start,j=end;i<j;i++,j--){
		swap(str[i],str[j]);
	}
}

// No extra space is used by this function
void reverseWordsinString(string &str){
	// Reverse the whole string first
	reverseString(str,0,str.size()-1);
	// Then reverse each individual word of the string
	// start and end of word is maintained through start and end index variable
	// string so formed is our desired answer
	for(int i=0;i<str.size();){
		int start=i;
		while(i+1< str.size() && str[i+1]!='.' && str[i+1]!=' ')
			i++;
		int end=i;
		reverseString(str,start,end);
		i=i+2;
	}
}

// This function uses extra space of O(n). We can use either stack or array of strings here
void reverseWordsinStringExtraSpace(string &str){
	vector<string> s;
	// Variable to temporarily hold the string
	string temp;
	// Extract each word of given string(using seperator which is dot here)
	// push those words in array of strings
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='.'){
			s.push_back(temp);
			temp="";
		}
		else
		{
			temp=temp+str[i];

		}
	}
	// Push the last word explicitly as it has no dot in the end
	s.push_back(temp);
	// initialize our answer with the last word of array
	str=s[s.size()-1];
	// Go through all the word, starting from second last and append it to answer using a seperator
	for(int i=s.size()-2;i>=0;i--){
		str=str+'.';
		str=str+s[i];
	}
}

int main (){
	int test;
	cin>>test;
	while(test--){
		string str;
		cin>>str;
		reverseWordsinString(str);
		//reverseWordsinStringExtraSpace(str);
		cout<<str<<endl;
	}
}
