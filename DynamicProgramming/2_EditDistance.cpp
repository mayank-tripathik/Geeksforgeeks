/*
 * Given two strings str1 and str2 and below operations that can performed on str2. Find minimum number of edits (operations) 
 * required to convert one string to another. Three operations that are allowed are: Insert, Remove, Replace.
 * All of the above operations are of equal cost.
 * Example: 
    Input:   str1 = "geek", str2 = "gesek"
    Output:  1
    We can convert str1 into str2 by inserting a 's'.
    Input:   str1 = "cat", str2 = "cut"
    Output:  1
    We can convert str1 into str2 by replacing 'a' with 'u'.
 * Suppose we want to convert str1 to str1
 * Think of base case. If one of the string is empty, then cost required is always equal to the length of other string. Why?
 * because we can either add all the char of non empty string to empty string, or we can remove all chars of nonempty string to
 * make it empty. Since cost of both removal and add is same!
 * What about non empty strings? Well, their are two cases. Start from either left or right. Say right. So if their last chars
 * are same, nothing to do, we can safely remove last chars of both and recur for the remaining string. Size of both thus 
 * decreases by 1.
 * If the last chars are not same, we can use the three allowed operations to make them same. Suppose last char of both string1
 * and string2 are char1 and char2 respectively. Three operations are:
 * Replace: Replace char2 by char1, and remove the last chars of both which are equal now. Both string length decreases by 1.
 * Remove: Remove last char2. This make string1 length same, but string2 length decreases by 1.
 * Add: Add char1 at last index of string2, and remove last chars of both which are equal now. While size of string1 decreases, 
 * size of string2 effectively remains the same (first increases by one and then decreases)
 * After applying one of the three operations(all of cost 1) on last chars of both strings, we can recur for the remaining 
 * strings and take minimum of the three cost we get.
 * Time complexity? The time complexity of above solution is exponential. In worst case, we may end up doing O(3^m) operations.
 * The worst case happens when none of characters of two strings match. 
 * Consider the two strings "abcd", "efgh". At every position, we have 3 choices: Insert, Update, Delete. This makes 3^n steps.
 * If we draw recursive call graph, we can see that many subproblems are solved again and again,
 * Since same suproblems are called again, this problem has Overlapping Subprolems property. 
 * So Edit Distance problem has both properties of a dynamic programming problem. 
 * Like other typical Dynamic Programming(DP) problems, recomputations of same subproblems can be avoided by constructing a 
 * temporary array that stores results of subpriblems.
 * We can avoid using 2D array of size O(n*m) because we need only two rows at each stage.Two array will thus suffices.
 * TC:O(m*n), Extra Space:O(2*n) if we just want length. Tracking requires whole matrix of size O(n*m)
 */
 

#include <bits/stdc++.h>
using namespace std;
int editDistanceRecursive(string str1, string str2, int i, int j){
	// If first string is empty, only option is to remove all characters of second string
	// Whose cost is equal to current size of second string
	if(i<0)
		return j+1;
    // If second string is empty, only option is to add all characters of first string
	// Whose cost is equal to current size of first string
	else if(j<0)
		return i+1;
    // If last characters are same, recur for the remaining string
	else if(str1[i]==str2[j])
		return editDistanceRecursive(str1,str2,i-1,j-1);
    // If last char are not same, apply all three operations and choose the one 
    // that uncurs minimum cost
	else
		return min(editDistanceRecursive(str1,str2,i-1,j-1),
			min(editDistanceRecursive(str1,str2,i,j-1),editDistanceRecursive(str1,str2,i-1,j)))+1;
}


int editDistanceDP(string str1, string str2){
	// Instead of having complete space of size O(n*m), we can just size two arrays,  because all we want
	// at any time is current and upper row. 
	vector<int> dpUpper(str1.size()+1);
	vector<int> dpLower(str1.size()+1);
	// Initialize first row. Since second string is empty here, cost will be equal to length of
	// string at that index ((similar to first base case of above recursion))
	for(int i=0;i<dpUpper.size();i++)
		dpUpper[i]=i;
	// Now start from first char of second string and go till last char of it
	for(int k=0;k<str2.size();k++){
		// dpLower[0] indicates first string with no characters being considered. Thus cost of
		// converting from second string to first will be just removing all characters of second string
		// which is equal to the current length of second string (similar to second base case of above recursion)
		dpLower[0]=k+1;
		// start from first character of first string and go till last
		for(int j=1;j<dpUpper.size();j++){
			// If current char of first string is equal to current char of second string, we can remove both of
			// these chars and cost will be as same as the cost for two strings we get after after removing last chars 
			if(str2[k]==str1[j-1])
				dpLower[j]=dpUpper[j-1];
			// If last chars are not same
			else{
				// We can replace char2 by char 1, and after replacing we can remove both last chars
				int replace=dpUpper[j-1];
				// We can just remove char2
				int remove=dpUpper[j];
				// We can just add char1 at last index of string2 and them remove both last chars
				int add=dpLower[j-1];
				// Take minimum of all the three operations, +1 indicates cost of each operation
				dpLower[j]=min(replace,min(remove,add))+1;
			}
		}
		// Copy lower row to upper row
		for(int j=0;j<dpUpper.size();j++){
			dpUpper[j]=dpLower[j];
		}
	}
	// return last value of lower of upper row(both will be same because of the last copy step)
	return dpUpper[dpUpper.size()-1];
}

int main() {
	int test;
	cin>>test;
	while(test--){
		string str1,str2;
		cin>>str1>>str2;
		cout<<editDistanceDP(str1,str2)<<endl;
	}
	return 0;
}
