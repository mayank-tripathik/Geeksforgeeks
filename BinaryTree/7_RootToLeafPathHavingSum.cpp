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


bool printAllRootToLeafPathHelper(TreeNode*root, int sum, int value){
  // if root is null return
	if(root==NULL){
		return;
	}
  // If root has any child
	if(root->left || root->right){
		bool ans=false;
    // Recur for left with sum updated as previous sum+ root's left child value
		if(root->left){
			ans=ans || printAllRootToLeafPathHelper(root->left,sum+(root->left->value),value);
		}
    // Recur for right with sum updated as previous sum+ root's right child value
		if(root->right){
			ans=ans || printAllRootToLeafPathHelper(root->right,sum+(root->right->value),value);
		}
    If any of the above calls return true, then return true, else return false
		return ans;
	}
  // At this point leaf is encountered, so check sum with the given value and return accordingly
	else{
		if(sum==value)
			return true;
		else
			return false;
	}
}

void printAllRootToLeafPath(TreeNode* root, int value){
  // If root is null, then return
	if(root==NULL){
		return;
	}
  // Initialize sum as root value
	int sum=root->value;
	if(printAllRootToLeafPathHelper(root,sum,value))
		cout<<"path exists\n";
	else
		cout<<"path not exists\n";
}

int main(){
	// Comment out other data to check any function
	// -------Zig-Zag or spiral order data----
	TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(8);
	root->right=new TreeNode(2);
	root->left->left=new TreeNode(3);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(2);
	// root->right->right=new TreeNode(23);
	// root->left->right->left=new TreeNode(28);
	// root->left->left->left=new TreeNode(24);
	// root->left->left->right=new TreeNode(25);
	// root->left->right->left=new TreeNode(26);
	// root->left->right->right=new TreeNode(27);
	// root->right->left->left=new TreeNode(28);
	// root->right->left->right=new TreeNode(29);
	// root->right->right->right=new TreeNode(30);
	// root->right->right->right=new TreeNode(31);
	int value;
	value=23;
	printAllRootToLeafPath(root,value);
}
