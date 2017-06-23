/*
 * Given a number, find the next smallest palindrome larger than this number. 
 * For example, if the input number is “2 3 5 4 5”, the output should be “2 3 6 3 2”.
 * And if the input number is “9 9 9”, the output should be “1 0 0 1”.
 * The input is assumed to be an array. Every entry in array represents a digit in input number.
 * Idea:  Since a palindrome is effectively "mirrored" around the central digit(s) of a number, we can reflect the first half 
 * of the number onto the second half. If the number of digits in the number is even - there will be more than one "central" 
 * element. So for example, given an input number of say, 1594 - we mirror it to 1551. 
 * This number is already a palindrome but obviously it's smaller than the input number so we need to do further work 
 * If it's already larger than, this is the next palindrome after K. 
 * Now if we have a palindrome that is less than or equal to the intended number we need to have an algorithm that: 
	 1. Increases the number but maintains it as a palindrome
	 2. Ensure that we don't skip any palindromes on the way
* If we take note that a palindrome must be mirrored, then we can deduce that the next largest palindrome would be one with its 
* central most digit incremented. This can be derived from the fact that the next largest (not necessarily palindrome) number is 
* one with its LSD (least significant digit) increased by 1, however since we need to retain it as a palindrome it also means 
* the MSD will need to be increased also - which is far from optimal. You can observe from this that the most optimal strategy
* would be to increase the center digits due to the mirror-like property of palindromes. 
* From the example above, if we incremented the first (and consequently last) digit then we yield 2552, however this isn't the 
* most optimal step because you can modify the central digits to 1661 and retain palindrome status.
* What happens if the center digits happened to be 9's? You set the currently operating digits to be 0 and increment the next
* pair of digits as this yields the next smallest number. For example, given 1999 - you first mirror it to 1991, increment the
* center digits to yield 1001 and then increment the next set of digits to yield 2002 - which is the expected answer. 
* This obviously needs to be looped via iteration or called recursively for multiple 9's.
* There is still one minor case we need to cover, it's one that reaches to the MSD but still needs to "carry on" the increments 
* or more simply "all 9's". A basic example would be 9999, if you do the algorithm above then you end up yielding 0000 and still 
* need to increment 1 to the next set of digits (which don't exist as of yet). 
* Covering this case is rather simple, add an extra digit '1' to the beginning of the number (i.e. 0000 -> 10000) and change 
* the LSD to a 1 also (for obvious reasons).
* TC:O(n)
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void print(vector<int> &vec){
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";
	cout<<endl;
}

// This function will convert a given number to a mirror palindrome
// In mirror palindrome, left high is reversely copied to right half
// Note that we could have also copied right half to left half, but we want next greater palindrome
// so left should be copied. Function will also set two pointers, middle1 and middle2. In case of odd length
// palindrome middle1 and middle2 both point to middle while in case of even they point to two middles possible
vector<int> numberToMirrorNumber(vector<int> &num, int *middle1, int* middle2){
	vector<int> mirrorNumber(num.size());
	if(num.size()%2!=0){
		int middle=num.size()/2;
		*middle1=*middle2=middle;
	}
	else{
		int middle=num.size()/2;
		*middle1=middle-1;
		*middle2=middle;
	}
	for(int i=0,j=num.size()-1;i<=j;i++,j--){
		mirrorNumber[j]=num[i];
		mirrorNumber[i]=num[i];
	}
	return mirrorNumber;
}

// This function takes the mirror palindrome and the two middle elements of it to start with
void convertMirrorToNextPalindrome(vector<int>& num, int pos1, int pos2) {
	// if left pointer becomes less than 0, means carry propagated through middle exceeds the number
	// thus we have to add extra 1 at left and make rightmost digit 1. In between, zeroes would
	// have been filled by now
	if (pos1 < 0) {
		num[num.size()-1] = 1;
		num.insert(num.begin(), 1);
		return;
	}
	// If number at first middle is less than 9, simply add 1 to both middle and return
	// Carry would not propagate because middle element is less than 9
	else if (num[pos1] < 9) {
		num[pos1] = num[pos2] = num[pos1] + 1;
		return;
	}
	// If middle element is 9, add 0 to both middles and recur for the left and right part by
	// decrementing and incrementing middle1 and middle2 respectively
	else {
		num[pos1] = num[pos2] = 0;
		convertMirrorToNextPalindrome(num, pos1-1, pos2+1);
		return;
	}
}

// Function to compare to number given in array form
// It returns true if v2 is greater than v1, return false otherwise
bool isMirrorGreater(const vector<int>& v1, const vector<int>& v2) {
	if (v1.size() != v2.size()) 
		return v1.size() < v2.size();
	for (int i = 0; i < v1.size(); i++)
		if (v1[i] != v2[i])
			return v1[i] < v2[i];
		return false;
	}

vector<int> nextPalindrome(vector<int> &num){
	int middle1,middle2;
	// Convert given number to mirror palindrome
	vector<int> mirrorNumber=numberToMirrorNumber(num,&middle1,&middle2);
	// Check if mirror palindrome is greater than number. If it is greater, it is our next
	// larger palindrome. If it is equal of smaller then only we have to move to next step
	// i.e convert it into a larger palindrome
	if(!isMirrorGreater(num,mirrorNumber)){
		convertMirrorToNextPalindrome(mirrorNumber,middle1,middle2);
	}
	return mirrorNumber;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> num(n);
		for(int i=0;i<n;i++)
			cin>>num[i];
		num=nextPalindrome(num);
		print(num);
	}
	return 0;
}
