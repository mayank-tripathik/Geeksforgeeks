/*
 * Given two unsorted arrays A, B. They can contain duplicates.
 * For each element in A , count elements less than or equal to it in array B .
 * Brute force is to pick each element of array a and compare it with every element of array b to find the number of elements
 * less than or equal to it. TC:O(n^2)
 * Efficient solution is to use hashing. We can create an array of size of max element of a. Then we can find frequency
 * of every element of b. We can then calculate the required count using cumulative frequency sum
 * TC:O(n) . Extra space: O(n)
 * /

#include<iostream>
#include<vector>
using namespace std;
#define MAX 101

void countElementsLessOrEqual(vector<int> &a, vector<int> &b){
	// Array to count the number of occurence of each element in b
	vector<int> hash(MAX,0);
	// count frequency of each element
	for(int i=0;i<b.size();i++)
		hash[b[i]]++;
	// fill hash array with cumulative frequency
	for(int i=1;i<101;i++)
		hash[i]=hash[i]+hash[i-1];
	// for every element of a, prints it frequency which is equal to the nube of elements less
	// than or equal to it
	cout<<hash[a[0]];
	for(int i=1;i<a.size();i++)
		cout<<","<<hash[a[i]];
	cout<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> a(n);
		vector<int> b(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		countElementsLessOrEqual(a,b);
	}
	return 0;
}
