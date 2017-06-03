/*
 * Given a tree and a certain value k, print nodes at distance k from the root
 * Both recursive and iterative approaches are O(n)
 */

#include<bits/stdc++.h>
#include<queue>
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

void printNodesAtDistanceKRecursive(TreeNode* root, int k){
	// If root is null, means tree is empty so just return 
	if(root==NULL){
		return;
	}
	// If k is 0, means we have arrived at the desired level, hence print the node and return
	if(k==0){
		cout<<root->value<<" ";
		return;
	}
	// Else recur for left and right subtree but with reduced k i.e k-1, this will allow us to reach
	// at desired interval when k eventually reaches 0
	else{
		printNodesAtDistanceKRecursive(root->left,k-1);
		printNodesAtDistanceKRecursive(root->right,k-1);
	}
}

void printNodesAtDistanceKIterative(TreeNode* root, int k){
	if(!root)
		return;
	queue<TreeNode*> q;
	q.push(root);
	int distance=-1;
	while(!q.empty()){
		int n=q.size();
		distance++;
		while(n--){
			TreeNode* parent=q.front();
			q.pop();
			if(distance==k)
				cout<<parent->value<<" ";
			else
			{
				if(parent->left)
					q.push(parent->left);
				if(parent->right)
					q.push(parent->right);
			}
		}
		if(distance==k)
			break;
	}
}

int main(){
	TreeNode *root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(8);
	cout<<"Nodes at distance "<<1<<":";
	printNodesAtDistanceKRecursive(root,1);
	cout<<endl;
	cout<<"Nodes at distance "<<2<<":";
	printNodesAtDistanceKIterative(root,2);
}
