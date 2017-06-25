/*
 * Given a string of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ 
 * characters. 
 * The value of a string is defined as the sum of squares of the count of each distinct character. 
 * For example consider the string “saideep”, here frequencies of characters are s-1, a-1, i-1, e-2, d-1, p-1 and value of the 
 * string is 1^2 + 1^2 + 1^2 + 1^2 + 1^1 + 2^2 = 9.
 * Since we want to minmize the defined value, it is evident that we have to remove the character with largest frequency at it
 * contributes the most. So the vague idea can be count frequency of each char in string, sort the frequency in decreasing order
 * and start removing k characters from the first one, because it is currently maximum. After decreasing it few times, it may be
 * possible that some other frequency becomes greater than the current maximum and to minimize the value, we have to start
 * removing char from thi frequency. Summarizing, we will first pick current max, decrease its count by 1 (equivalent to removing
 * char from string with highest frequency). Then we again pick the maximum from the all the frequencies and repeats the same
 * process till k characters are removed
 * Since we want current max at each stage, instead of sorting or linear search for max at each step, we can use priority queue
 * to get the current max efficiently. At each step, we pick the current max, decrease its value and push it again. We will 
 * repeat until we pop k times. Queue at this stage will contain freqencies that will minimize our string value. So pop all items
 * and add their squares to answer
 * TC: O(n) time for storing frequency. Then we pop k times to remove k characters from string i.e O(k*log(26)). Queue is finally
 * popped again to get our answer O(k*log(26)). So overall O(n+klog(26)) which is O(n),for worst k.
 */

#include<bits/stdc++.h>
using namespace std;

// Following function return minimum value of string after removal of k elments
int minValue(string &str, int k){
	// Array to count frequency of each character in given string
	vector<int> hash(26,0);
	priority_queue<int> q;
	// Count frequency of each character of string
	for(int i=0;i<str.size();i++)
		hash[str[i]-'a']++;
	// push each count of character in priority queue, so that we can pick the larger count
	// at each step. 
	for(int i=0;i<26;i++)
		q.push(hash[i]);
	// Run until k characters are not removed
	while(k--){
		// pop the largest count from queue and decrease its value by 1, which semantically means 
		// we are deleting that character in each step which has currently the maximum count which will
		// help in minimizing the string value
		int currentMin=q.top();
		q.pop();
		currentMin=currentMin-1;
		// repush the popped character with decremented value
		q.push(currentMin);
	}
	// intialize our answer as 0
	int sum=0;
	// pop each count from q and add its square to the answer
	while(!q.empty()){
		int currentMin=q.top();
		q.pop();
		// This check is used to ensure that no negative value contributes to sum
		// Negative value is possible if given k is greater than string size
		if(currentMin>0)
			sum+=pow(currentMin,2);
	}
	// return answer
	return sum;

}

int main()
{
	int test;
	cin>>test;
	while(test--){
		string str;
		int k;
		cin>>str;
		cin>>k;
		cout<<minValue(str,k)<<endl;
	}
	return 0;
}
