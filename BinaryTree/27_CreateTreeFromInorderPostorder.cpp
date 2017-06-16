/*
 * Given Postorder and Inorder traversals, construct the tree.
 * Examples:
 
    Input : 
      in[]   = {2, 1, 3}
      post[] = {2, 3, 1}

      Output : Root of below tree
            1
          /   \
         2     3 


    Input : 
      in[]   = {4, 8, 2, 5, 1, 6, 3, 7}
      post[] = {8, 4, 5, 2, 6, 7, 3, 1} 

      Output : Root of below tree
                1
             /     \
           2        3
         /    \   /   \
        4     5   6    7
          \
            8
            
  * The process is similar to creating tree from inorder and preorder traversal
  * Since in postorder, root is always at last, so unlike preorder where we have started from begining, here we wills start from
  * end. We will pick the last node, make it root, then search for root in inorder array to find the left and right subtree
  * of root. Everything on left is in left subtree and everything on right is in right subtree of root. 
  * Thus in our example, we pick 1, the last element, make it root and then search for it in inorder array to get its position
  * everything on 1's left is in the left subtree of 1, and everything on 1's right is in the right subtree of 1.

             1
           /    \
    [4,8,2,5]   [6,3,7] 

 * Then we recur the above process for both subtrees, first for right and then for left(unlike preorder where we have recurred
 * for left first and then right). why? Can't we do the same preorder? No! Because we are traversing in postorder, from end 
 * using postorderIndex, means we will see first a node that lies on right side of root node in tree and then a node that 
 * lies on left side of root node in tree. That's why, to make the required tree, we need to call root->right first as 
 * postorderIndex gives the right node first.
 * TC:O(n^2). Occurs in skewed BT.
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

void postorderTraversal(TreeNode* root){
	if(root==NULL)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout<<root->value<<" ";
}

TreeNode* constructTree(vector<int> &inorder, vector<int> &postorder, int *postorderIndex,int low , int high){
	// If low>high, means no node in this subtree, hence returns NULL
	// This will also handle the case when postorder and inorder is empty at all
	if(low>high)
		return NULL;
	// Create a new node with value having index as postorderIndex. 
	TreeNode* root=new TreeNode(postorder[(*postorderIndex)]);
	// Search for the value that is indexed at postorderIndex. This value's index in inorder array is stored
	// in inorderIndex variable
	int inorderIndex=findElementInInorder(inorder,postorder[*postorderIndex],low, high);
	// Decrement the postorderIndex value through its pointer so that when next node is created. it's
	// value is equal to the previous value in postorder array
	(*postorderIndex)=(*postorderIndex)-1;
	// Recursively call constructTree on right side of current root of inorder array
	// and left side of current root in inorder array and assign it to root right and root left respectively
	root->right=constructTree(inorder,postorder,postorderIndex,inorderIndex+1,high);
	root->left=constructTree(inorder,postorder,postorderIndex,low,inorderIndex-1);	
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
		vector<int> postorder(n);
		for(int i=0;i<n;i++)
			cin>>inorder[i];
		for(int i=0;i<n;i++)
			cin>>postorder[i];
		// This variable holds the index of the postorder array and is passed by reference
		// so that it can be decremented in each recursive call.Thus new node is always
		// created with previous postorder array values
		int postorderIndex=n-1;
		// 0 and n-1 denotes the lower and higher bound of inorder array i.e current subtree
		// we are considering
		TreeNode* root=constructTree(inorder,postorder,&postorderIndex,0,n-1);
		// Print tree traversal to check if the tree created is correct or not
		inorderTraversal(root);
		cout<<endl;
		postorderTraversal(root);
	}
	return 0;
}
