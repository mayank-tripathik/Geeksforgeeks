/*
 * Given a number n, find the smallest number that has same set of digits as n and is greater than n. 
 * This problem is also referred as finding next permutation
 * If next permutation is not possible, then print “not possible”
 * Example: 
    Input:  n = "218765"
    Output: "251678"
    Input: n = "4321"
    Output: "Not Possible" 
 * key Observation : When we want to compute the next permutation, we must “increase” the sequence as little as possible. 
 * This is similar to counting numbers, where we try to modify the rightmost elements and leave the left side unchanged. 
 * For example, if we have 01, then instead of changing first number i.e 0 to 1, we can change 01 to 02 to get an even closer
 * next permutation. Thus we should start from right side.
 * Firstly, identify the longest suffix that is non-increasing (i.e. weakly decreasing). 
 * This suffix is already the highest permutation, so we can’t make a next permutation just by modifying it – we need to modify 
 * some element(s) to the left of it. (Note that we can identify this suffix in O(n) time by scanning the sequence from right to 
 * left)
 * Secondly, the element immediately to the left of the suffix, call it pivot, is necessarily less than the head of the suffix. 
 * Note if there is no pivot element – i.e. the entire sequence is non-decreasing – then this is already the last permutation.
 * The pivot is necessarily less than the head of the suffix. So some element in the suffix is greater than the pivot. 
 * If we swap the pivot with the smallest element in the suffix that is greater than the pivot, then the prefix is minimized.
 * (The prefix is everything in the sequence except the suffix.)  
 * Note that if the suffix has multiple copies of the new pivot, we should take the rightmost copy.
 * Finally, we sort the suffix in non-decreasing (i.e. weakly increasing) order because we increased the prefix, so we want to 
 * make the new suffix as low as possible. 
 * We can avoid sorting and simply reverse the suffix, because the replaced element respects the weakly decreasing order.
 * Summarizing, the basic idea is to divide string into some prefix and suffix so that we have to change as little as possible
 * to get a larger number. Such suffix would be the longest non-icreasing suffix.Once we get prefix and suffix, we have to 
 * increase prefix in such a way that increase is minimal. we have done this by swapping the last element of prefix with 
 * smallest element larger than it in suffix. Then we make the suffix as small as possible by sorting/reversing it.
 * TC:O(n)
 * Similar logic can be used for generating previous permutation, where we first search for longest non-decreasing suffix
 * and then for search largest element smaller than pivot in the right and then swapping and reversing
 */

#include<iostream>
#include<algorithm>
using namespace std;

void reverse(string &str, int start, int end){
	while(start<end){
		swap(str[start],str[end]);
		start++;
		end--;
	}
}

// This function will change the given string to next permuation that is possible from the digits of the given number
// and returns true. If next permuatation is not possible, false is returned
bool nextPermutation(string &str){
	int i;
	// Try to find last index i in string (i.e first from right), such that str[i]<str[i+1]
	// That is search for first index that violates the ascending property from right
	for(i=str.size()-2;i>=0;i--){
		if(str[i]<str[i+1]){
			break;
		}
	}
	// If i>=0, means such index exists. If such index exists, then find the smallest number greater 
	// than it in its right. Since numbers right to i are descending, to find the smallest greater number
	// we can start from the extreme right and go on till i'th index and report the first character that 
	// is greater than str[i]. It will be the smallest number greater than str[i]
	// We can search such nuumber using either binary search or linear. Here we are going linear
	if(i>=0){
		int k;
		for(k=str.size()-1;k>i;k--){
			if(str[k]>str[i])
				break;
		}
		// swap these two numbers
		swap(str[i],str[k]);
		// reverse all the digits to the right of i'th number. Since digits to right of i
		// are descending, reversing it produces the smallest possible number possible with suffix
		reverse(str,i+1,str.size()-1);
		return true;
	}
	// if i is less than 0, means no such number exists, hence return true;
	else
		return false;
}

// This is the quick way of getting next permuation through the next_permutation algo present
// in algorithm library of c++. If next permutation is possible, it changes the string and return true
// otherwise it return false
void nextPermutationSTL(string &str){
	bool val = next_permutation(str.begin(), str.end());
	if (val == false)
		cout << "Not Possible" << endl;
	else
		cout << str << endl;
}

// This function will change the given string to previous permuation that is possible from the digits of the given number
// and returns true. If previous permuatation is not possible, false is returned
bool prevPermutation(string &str){
	int i;
	// Try to find last index i in string (i.e first from right), such that str[i]>str[i+1]
	// That is search for first index that violates the descending property from right
	for(i=str.size()-2;i>=0;i--){
		if(str[i]>str[i+1]){
			break;
		}
	}
	// If i>=0, means such index exists. If such index exists, then find the largest number smaller 
	// than it in its right. Since numbers right to i are ascending, to find the largest smaller number
	// we can start from the extreme right and go on till i'th index and report the first character that 
	// is smaller than str[i]. It will be the largest number smaller than str[i]
	// We can search such nuumber using either binary search or linear. Here we are going linear
	if(i>=0){
		int k;
		for(k=str.size()-1;k>i;k--){
			if(str[k]<str[i])
				break;
		}
		// swap these two numbers
		swap(str[i],str[k]);
		// reverse all the digits to the right of i'th number. Since digits to right of i
		// are ascending, reversing it produces the largest possible number possible with suffix
		reverse(str,i+1,str.size()-1);
		return true;
	}
	// if i is less than 0, means no such number exists, hence return false
	else
		return false;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		string str;
		cin>>str;
		//nextPermutationSTL(str);
		while(prevPermutation(str))
			cout<<str<<endl;
		while(nextPermutation(str))
			cout<<str<<endl;
	}
	return 0;
}

