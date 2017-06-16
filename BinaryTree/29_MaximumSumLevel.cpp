
/*
 * Given a Binary Tree having positive and negative nodes, the task is to find maximum sum level in it.
 * Examples:
 
      Input :               4
                          /   \
                         2    -5
                        / \    /\
                      -1   3 -2  6
      Output: 6
      Explanation :
      Sum of all nodes of 0'th level is 4
      Sum of all nodes of 1'th level is -3
      Sum of all nodes of 0'th level is 6
      Hence maximum sum is 6

      Input :          1
                     /   \
                   2      3
                 /  \      \
                4    5      8
                          /   \
                         6     7  
      Output :  17
  * Similar to max width problem, we can use level order traversal to calculate sum at each level and update maximum sum.
  * TC:O(n)
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

// Just maintain sum at each level at update the maximum sum acccordingly
int maxSumLevel(TreeNode* root){
	if(root==NULL)
		return 0;
	queue<TreeNode*> q;
	q.push(root);
	int maxSum=root->value;
	while(!q.empty()){
		int n=q.size();
		int currentLevelSum=0;
		while(n--){
			TreeNode* parent=q.front();
			q.pop();
			currentLevelSum+=parent->value;
			if(parent->left)
				q.push(parent->left);
			if(parent->right)
				q.push(parent->right);
		}
		maxSum=max(maxSum,currentLevelSum);
	}
	return maxSum;
}

int main(){
	TreeNode *root=new TreeNode(4);
	root->left=new TreeNode(2);
	root->right=new TreeNode(-5);
	root->left->left=new TreeNode(-1);
	root->left->right=new TreeNode(3);
	root->right->left=new TreeNode(-2);
	root->right->right=new TreeNode(6);
	cout<<maxSumLevel(root);
}
