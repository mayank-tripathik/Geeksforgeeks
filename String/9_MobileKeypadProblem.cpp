/*
 * Before advent of QWERTY keyboards, texts and numbers were placed on the same key. 
 * For example 2 has “ABC” if we wanted to write anything starting with ‘A’ we need to type key 2 once. 
 * If we wanted to type ‘B’, press key 2 twice and thrice for typing ‘C’. below is picture of such keypad.
* Given a typical keypad, and n digit number, list all words which are possible by pressing these numbers.
* For example if input number is 234, possible words which can be formed are (Alphabetical order):
  adg adh adi aeg aeh aei afg afh afi bdg bdh bdi beg beh bei bfg bfh bfi cdg cdh cdi ceg ceh cei cfg cfh cfi
* Following program imlements a recursive approach where we pick each key and print its char, then move to next digit and so on
* TC:O(4^n)
*/

#include<bits/stdc++.h>
using namespace std;

class MobileKeypad {
private:
	vector<vector<char> > keypad;
public:

	MobileKeypad(){
		keypad.resize(10);
	}

	void createKeypad(){
		char c='a';
		for(int i=2;i<=9;i++){
			if(i==7 || i==9){
				for(int k=0;k<4;k++){
					keypad[i].push_back(c);
					c++;
				}
			}
			else if(i==0 || i==1)
				continue;
			else{
				for(int k=0;k<3;k++){
					keypad[i].push_back(c);
					c++;
				}
			}
		}
	}

	bool printAllWords(vector<int> &buttonToPress, int currentButton, string &output,vector<string> &ans){
		if(currentButton==buttonToPress.size()){
			ans.push_back(output);
			return true;
		}
		else if(buttonToPress[currentButton]==0 || buttonToPress[currentButton]==0)
			return false;
		else{
			int key=buttonToPress[currentButton];
			for(int i=0;i<keypad[key].size();i++){
				output[currentButton]=keypad[key][i];
				printAllWords(buttonToPress,currentButton+1,output,ans);
			}
		}
		return true;
	}

	vector<string> letterCombinations(string digits) {
		int n=digits.size();
		vector<int> buttonToPress;
		for(int i=0;i<digits.size();i++){
			buttonToPress.push_back(digits[i]-'0');
		}
		vector<string> ans;
		if(digits=="")
			return ans;
		string output;
		output.resize(n);
		createKeypad();
		bool flag=printAllWords(buttonToPress,0,output,ans);
		if(!flag)
			ans.resize(0);
		return ans;
	}
};

int main (){
	int test;
	cin>>test;
	while(test--){
		string str;
		cin>>str;
		MobileKeypad m;
		vector<string> words=m.letterCombinations(str);
		for(int i=0;i<words.size();i++)
			cout<<words[i]<<endl;
	}
}
