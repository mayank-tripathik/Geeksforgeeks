/*
 * Serialization is to store a tree in an array so that it can be later restored
 * Deserialization is reading tree back from the array. 
 * Write a program to complete the function serialize which stores the tree into an array A[ ] and deSerialize which 
 * deserializes the array to tree and returns it.
 * One simple approach can be storing both inorder and preorder traversals
 * We can store tree more efficiently using any traversal if we use marker for NULL nodes, (example -1 for NULL values).
 * Following program uses level order traversal to first serialize the tree and then deserializes it using the same concept
 * TC:O(n)
 * How much extra space is required in above solution?
 * If there are n keys, then the above solution requires n+1 markers which may be better than simple solution (storing keys 
 * twice) in situations where keys are big or keys have big data items associated with them.
 * Further optimization : If we take a closer look at above serialized trees, we can observer that all leaf nodes require two 
 * markers. One simple optimization is to store a separate bit with every node to indicate that the node is internal or external.
 * This way we don’t have to store two markers with every leaf node as leaves can be identified by extra bit. 
 * We still need marker for internal nodes with one child.
 */


#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
	int value;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(int x){
		value=x;
		left=right=NULL;
	}
	
};

void inorder(TreeNode *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->value<<" ";
	inorder(root->right);
}

// this function will set array A using level order traversal
// if node has no children, -1 is placed (that is -1 replaces NULL)
void serialize(TreeNode *root,vector<int> &A)
{
	// Usual level order traversal
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode* parent=q.front();
		q.pop();
		// if popped node is not NULL, push its value in array
		if(parent)
			A.push_back(parent->value);
		// if popped value is NULL, push -1 in array
		else
			A.push_back(-1);
		// if node is not NULL, push its left and right child
		// Note that if any child is NULL, NULL will be pushed in queue
		if(parent){
			q.push(parent->left);
			q.push(parent->right);
		}
	}
}

TreeNode * deSerialize(vector<int> &A)
{
	// We will use extra array of node to set left and right child of a node
	// We could have used a queue also
	vector<TreeNode*> nA;
	// Fill this array by creating nodes using the given array
	// If -1 is encountered place NULL there, else create node of that value
	// and place it
	for(int i=0;i<A.size();i++){
		TreeNode* temp;
		if(A[i]!=-1)
			temp=new TreeNode(A[i]);
		else{
			temp=NULL;
		}
		nA.push_back(temp);
	}
	// Initialize root as first node of node array
	// intiialize leftChild index and right child index
	TreeNode* root=nA[0];
	int leftChild=1;
	int rightChild=2;
	for(int i=0;rightChild<nA.size();i++){
		// take one node , call it parent
		TreeNode* parent=nA[i];
		// if parent is not NULL, set its left and right child
		// and advance left and right child pointers
		if(parent){
			parent->left=nA[leftChild];
			parent->right=nA[rightChild];
			leftChild=leftChild+2;
			rightChild=rightChild+2;
		}
	}
	// return the new tree
	return root;
}

int main(){
	TreeNode *root=new TreeNode(8);
	root->left=new TreeNode(3);
	root->right=new TreeNode(10);
	root->left->left=new TreeNode(1);
	root->left->right=new TreeNode(6);
	root->right->right=new TreeNode(14);
	root->left->right->right=new TreeNode(9);
	root->right->right->left=new TreeNode(2);
	cout<<"Given Tree\n";
	inorder(root);
	cout<<endl;
	vector<int> treeArray;
	serialize(root,treeArray);
	TreeNode* rootTree=deSerialize(treeArray);
	cout<<"Tree after serialization and deserialization\n";
	inorder(rootTree);
	cout<<endl;
}
