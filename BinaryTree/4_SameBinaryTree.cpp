#include<iostream>
using namespace std;

class TreeNode{
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

bool sameBinaryTree(TreeNode* root1, TreeNode* root2){
	if(root1==NULL && root2==NULL)
		return true;
	else if(root1 && root2 && root1->value==root2->value){
		if(sameBinaryTree(root1->left,root2->left) && sameBinaryTree(root1->right,root2->right))
			return true;
		else
			return false;
	}
	else
		return false;
}

void inorder(TreeNode *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->value<<" ";
	inorder(root->right);
}
void deleteTree(TreeNode* root){
	if(root==NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete(root);
}
int main(){
	// Tree One
	TreeNode* treeOne=new TreeNode(5);
	if(treeOne==NULL)
		cout<<"Tree empty!\n";
	inorder(treeOne);
	cout<<endl;
	treeOne->left=new TreeNode(7);
	treeOne->right=new TreeNode(12);
	treeOne->left->left=new TreeNode(9);
	treeOne->left->right=new TreeNode(23);
	if(!treeOne)
		cout<<"Tree empty!\n";
	inorder(treeOne);
	cout<<endl;
	// Tree two
	TreeNode* treeTwo=new TreeNode(5);
	treeTwo->left=new TreeNode(7);
	treeTwo->right=new TreeNode(12);
	treeTwo->left->right=new TreeNode(9);
	treeTwo->left->left=new TreeNode(23);
	if(sameBinaryTree(treeOne,treeTwo))
		cout<<"Same tree\n";
	else
		cout<<"Different tree\n";
	inorder(treeOne);
	cout<<endl;
	if(!treeOne)
		cout<<"Tree empty!\n";
	deleteTree(treeOne);
	treeOne=NULL;
	if(treeOne==NULL)
		cout<<"Tree empty!\n";
	inorder(treeOne);
	cout<<endl;

}
