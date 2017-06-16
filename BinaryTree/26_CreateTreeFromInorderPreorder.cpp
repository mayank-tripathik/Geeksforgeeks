/*
 * Construct Tree from given Inorder and Preorder traversals
 * Example : 
    Inorder sequence: D B E A F C
    Preorder sequence: A B D E C F
    Then tree will be :

               A
             /   \
           /       \
          B         C
         / \        /
       /     \    /
      D       E  F
      
  * We know that in a Preorder sequence, leftmost element is the root of the tree. 
  * So we know ‘A’ is root for given sequences. By searching ‘A’ in Inorder sequence, we can find out all elements on 
  * left side of ‘A’ are in left subtree and elements on right are in right subtree. So we know below structure now.

                 A
               /   \
             /       \
           D B E     F C
           
  * We can recusrively follow the steps to get the tree
  * Algorithm:
    1) Pick an element from Preorder.
    2) Create a new tree node(say temp) with the data as picked element.
    3) Find the picked element’s index in Inorder. Let the index be inorderIndex.
    4) Increment a Preorder Index Variable (preorderIndex in below code) to pick next element in next recursive call.
    4) Call constructTree for elements before inorderIndex and make the constructed tree as left subtree of temp.
    5) Call constructTree for elements after inorderIndex and make the constructed tree as right subtree of temp.
    6) return temp.
  * TC:O(n^2). Worst case occurs when tree is left skewed. 
  * Example Preorder and Inorder traversals for worst case are {A, B, C, D} and {D, C, B, A}.
  */


#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int value;
	TreeNode* left,*right;
	TreeNode(int x){
		left=right=NULL;
		value=x;
	}
};

int findElementInInorder(vector<int> &inorder, int elem, int low, int high){
	for(int i=low;i<=high;i++){
		if(inorder[i]==elem)
			return i;
	}
}
void inorderTraversal(TreeNode* root){
	if(root==NULL)
		return;
	inorderTraversal(root->left);
	cout<<root->value<<" ";
	inorderTraversal(root->right);
}

void preorderTraversal(TreeNode* root){
	if(root==NULL)
		return;
	cout<<root->value<<" ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

TreeNode* constructTree(vector<int> &inorder, vector<int> &preorder, int *preorderIndex,int low , int high){
	// If low>high, means no node in this subtree, hence returns NULL
	// This will also handle the case when preorder and inorder is empty at all
	if(low>high)
		return NULL;
	// Create a new node with value having index as preorderIndex. 
	TreeNode* root=new TreeNode(preorder[(*preorderIndex)]);
	// Search for the value that is indexed at preorderIndex. This value's index in inorder array is stored
	// in inorderIndex variable
	int inorderIndex=findElementInInorder(inorder,preorder[*preorderIndex],low, high);
	// Increment the preOrderIndex value through its pointer so that when next node is created. it's
	// value is equal to the next value in preorder array
	(*preorderIndex)=(*preorderIndex)+1;
	// Recursively call constructTree on left side of current root of inorderarray
	// and right side of current root in inorder array and assign it to root left and root right
	root->left=constructTree(inorder,preorder,preorderIndex,low,inorderIndex-1);	
	root->right=constructTree(inorder,preorder,preorderIndex,inorderIndex+1,high);
	return root;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> inorder(n);
		vector<int> preorder(n);
		for(int i=0;i<n;i++)
			cin>>inorder[i];
		for(int i=0;i<n;i++)
			cin>>preorder[i];
		// This variable holds the index of the preorder array and is passed by reference
		// so that it can be incremented in each recursive call.Thus new node is always
		// created with next preorder array values
		int preorderIndex=0;
		// 0 and n-1 denotes the lower and higher bound of inorder array i.e current subtree
		// we are considering
		TreeNode* root=constructTree(inorder,preorder,&preorderIndex,0,n-1);
		// Print tree traversal to check if the tree created is correct or not
		inorderTraversal(root);
		preorderTraversal(root);
	}
	return 0;
}
