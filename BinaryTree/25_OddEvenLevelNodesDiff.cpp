/*
 * Given a a Binary Tree, find the difference between the sum of nodes at odd level and the sum of nodes at even level. 
 * Consider root as level 1, left and right children of root as level 2 and so on.
 * Example, in the following tree, sum of nodes at odd level is (5 + 1 + 4 + 8) which is 18. 
 * And sum of nodes at even level is (2 + 6 + 3 + 7 + 9) which is 27. 
 * The output for following tree should be 18 – 27 which is -9.

          5
        /   \
       2     6
     /  \     \  
    1    4     8
        /     / \ 
       3     7   9  
     */

 * We can use simple level order traversal to keep track of odd and even level sum and then return the difference of both
 * TC:O(n)
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
void inorder(TreeNode *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->value<<" ";
	inorder(root->right);
}


int oddEvenLevelSumDifference(TreeNode* root){
	if(root==NULL)
		return 0;
	queue<TreeNode*> q;
	q.push(root);
	int level=0;
	int oddLevelNodesSum=0,evenLevelNodesSum=0;
	while(!q.empty()){
		int n=q.size();
		level++;
		while(n--){
			TreeNode* parent=q.front();
			if(level%2!=0)
				oddLevelNodesSum+=parent->value;
			else
				evenLevelNodesSum+=parent->value;
			q.pop();
			if(parent->left)
				q.push(parent->left);
			if(parent->right)
				q.push(parent->right);
		}
	}
	return oddLevelNodesSum-evenLevelNodesSum;
}

int main(){
	TreeNode *root=new TreeNode(5);
	root->left=new TreeNode(2);
	root->right=new TreeNode(6);
	root->left->left=new TreeNode(1);
	root->left->right=new TreeNode(4);
	root->right->right=new TreeNode(8);
	root->left->right->left=new TreeNode(3);
	root->right->right->left=new TreeNode(7);
	root->right->right->right=new TreeNode(9);
	cout<<oddEvenLevelSumDifference(root);
}
