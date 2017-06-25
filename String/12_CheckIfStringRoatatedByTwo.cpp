/*
 * Given two strings, the task is to find if a string ('a') can be obtained by rotating another string ('b') by two places.
 * Examples:
    Input : a = "amazon" 
            b = "azonam"  // rotated anti-clockwise
    Output : 1

    Input : a = "amazon"
            b = "onamaz"  // rotated clockwise
    Output : 1
 * We can check for anti clockwise and clockwise cases by comparing two strings for both cases. If either one of the case
 * satisfies we return true, else return false
 * TC:O(n)
 */

#include<iostream>
using namespace std;
bool rotatedByTwo(string &a, string &b){
	if(a.size()!=b.size())
		return false;
	if(a.size()<=2 && (a==b))
		return true;
  // First condition means clockwise rotation, next conndition means anticlockwise roatation. We check for all characters
  // then and return true if every char matches, else we return false
	if(a[0]==b[2] || a[0]==b[b.size()-2]){
		int j=(a[0]==b[2])?2:b.size()-2;
		for(int i=0;i<a.size();i++,j++){
			j=j%(b.size());
			if(a[i]!=b[j])
				return false;
		}
		return true;
	}
	else
		return false;
}
int main()
{
	int test;
	cin>>test;
	while(test--){
		string a,b;
		cin>>a>>b;
		cout<<rotatedByTwo(a,b)<<endl;
	}
	return 0;
}
