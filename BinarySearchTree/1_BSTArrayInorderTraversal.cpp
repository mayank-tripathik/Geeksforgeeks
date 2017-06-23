/*
 * Given an array that stores a complete Binary Search Tree, write a function that efficiently prints the given array in 
 * ascending order.
 * For example, given an array [4, 2, 5, 1, 3], the function should print 1, 2, 3, 4, 5
 * Inorder traversal of BST prints it in ascending order. 
 * The only trick is to modify recursion termination condition in standard Inorder Tree Traversal.
 * TC:O(n)
 */
 
#include<iostream>
#include<vector>
using namespace std;

int leftSubtree(int i){
	return 2*i+1;
}

int rightSubtree(int i){
	return 2*i+2;
}

void inorder(vector<int> &BST, int root){
	if(root>=BST.size())
		return;
	inorder(BST,leftSubtree(root));
	cout<<BST[root]<<" ";
	inorder(BST,rightSubtree(root));
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> BST(n);
		for(int i=0;i<n;i++)
			cin>>BST[i];
		inorder(BST,0);
	}
}
