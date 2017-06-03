/*
 * Given a binary tree, write a function to get the maximum width of the given tree. 
 * Width of a tree is maximum of widths of all levels.
 * Example tree.

         1
        /  \
       2    3
     /  \     \
    4    5     8 
              /  \
             6    7

 * For the above tree,
 * width of level 1 is 1,
 * width of level 2 is 2,
 * width of level 3 is 3
 * width of level 4 is 2. 
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


int maxWidth(TreeNode* root){
	if(!root)
		return 0;
	queue<TreeNode*> q;
	q.push(root);
	int width=0;
	while(!q.empty()){
		int n=q.size();
		if(n>width)
			width=n;
		while(n--){
			TreeNode* parent=q.front();
			q.pop();
			if(parent->left)
				q.push(parent->left);
			if(parent->right)
				q.push(parent->right);
		}
	}
	return width;
}

int main(){
	TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(8);
	root->right=new TreeNode(2);
	root->left->left=new TreeNode(3);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(2);
	root->right->right=new TreeNode(23);
	cout<<maxWidth(root);
}
