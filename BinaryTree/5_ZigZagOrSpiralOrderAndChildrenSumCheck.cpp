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

int countLeaf(TreeNode* root){
	if(root==NULL)
		return 0;
	else if(root->left==NULL && root->right==NULL)
		return 1;
	else
		return countLeaf(root->left)+countLeaf(root->right);
}

void spiralOrder(TreeNode* root){
	cout<<"Spriral Order of Tree:\n";
	deque<TreeNode*> q;
	q.push_front(root);
	int level=0;
	while(!q.empty()){
		int n=q.size();
		level++;
		while(n--){
			if(level%2!=0){
				TreeNode* parent= q.back();
				//cout<<q.back()->value<<" is popped\n";
				q.pop_back();
				cout<<parent->value<<" ";
				if(parent->right){
					q.push_front(parent->right);
					//cout<<parent->right->value<<" is pushed back\n";
				}
				if(parent->left){
					q.push_front(parent->left);
					//cout<<parent->left->value<<" is pushed back\n";
				}
			}
			else{
				TreeNode* parent= q.front();
				//cout<<q.front()->value<<" is popped\n";
				q.pop_front();
				cout<<parent->value<<" ";
				if(parent->left){
					q.push_back(parent->left);
					//cout<<parent->left->value<<" is pushed back\n";
				}
				if(parent->right){
					q.push_back(parent->right);
					//cout<<parent->right->value<<" is pushed back\n";
				}
			}
		}
		cout<<endl;
	}
}

bool checkChildrenSumProperty(TreeNode* root){
	if(root==NULL)
		return true;
	else if(root->left || root->right){
		int l=0,r=0;
		if(root->left)
			l=root->left->value;
		if(root->right)
			r=root->right->value;
		if(root->value==(l+r)){
			if(checkChildrenSumProperty(root->left) && checkChildrenSumProperty(root->right))
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return true;
}
int main(){
	// Comment out other data to check any function
	// -------Zig-Zag or spiral order data----
	TreeNode *root=new TreeNode(5);
	root->left=new TreeNode(9);
	root->right=new TreeNode(1);
	root->left->left=new TreeNode(10);
	root->left->right=new TreeNode(3);
	root->right->left=new TreeNode(7);
	root->right->right=new TreeNode(23);
	root->left->left->left=new TreeNode(24);
	root->left->left->right=new TreeNode(25);
	root->left->right->left=new TreeNode(26);
	root->left->right->right=new TreeNode(27);
	root->right->left->left=new TreeNode(28);
	root->right->left->right=new TreeNode(29);
	root->right->right->right=new TreeNode(30);
	root->right->right->right=new TreeNode(31);
	cout<<countLeaf(root)<<endl;
	spiralOrder(root);
	

	// --------Children Sum property check data----
	TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(8);
	root->right=new TreeNode(2);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(2);
	if(checkChildrenSumProperty(root))
		cout<<"Children Sum property exist\n";
	else
		cout<<"Children Sum property not exist\n";
}
