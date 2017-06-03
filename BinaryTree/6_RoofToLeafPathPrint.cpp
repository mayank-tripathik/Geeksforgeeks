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

void print(vector<TreeNode*> &arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]->value<<" ";
	cout<<endl;
}

void printAllRootToLeafPathHelper(TreeNode*root, vector<TreeNode*> &arr){
	if(root==NULL){
		return;
	}
	if(root->left || root->right){
		if(root->left){
			arr.push_back(root->left);
			printAllRootToLeafPathHelper(root->left,arr);
			arr.pop_back();
		}
		if(root->right){
			arr.push_back(root->right);
			printAllRootToLeafPathHelper(root->right,arr);
			arr.pop_back();
		}
	}
	else{
		print(arr);
	}
}

void printAllRootToLeafPath(TreeNode* root){
	vector<TreeNode*> arr;
	arr.push_back(root);
	printAllRootToLeafPathHelper(root,arr);
}


int main(){
	TreeNode *root=new TreeNode(5);
	root->left=new TreeNode(9);
	root->right=new TreeNode(1);
	root->left->left=new TreeNode(10);
	root->left->right=new TreeNode(3);
	root->right->left=new TreeNode(7);
	root->right->right=new TreeNode(23);
	root->left->right->left=new TreeNode(28);
	root->left->left->left=new TreeNode(24);
	root->left->left->right=new TreeNode(25);
	root->left->right->left=new TreeNode(26);
	root->left->right->right=new TreeNode(27);
	root->right->left->left=new TreeNode(28);
	root->right->left->right=new TreeNode(29);
	root->right->right->left=new TreeNode(30);
	root->right->right->right=new TreeNode(31);
	printAllRootToLeafPath(root);
}
