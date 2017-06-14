#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x){
		left=right=NULL;
		value=x;
	}
};

struct tree{
	int left;
	int right;
	int root;
	tree(){
		left=right=-1;
	}
};

TreeNode* contructTreeFromParent(vector<int> &parent){
	vector<tree> treeArray(parent.size());
	int rootArray;
	for(int i=0;i<parent.size();i++){
		int u=parent[i];
		int v=i;
		if(u==-1)
			rootArray=v;
		else{
			if(treeArray[u].left==-1)
				treeArray[u].left=v;
			else
				treeArray[u].right=v;
		}
	}
	TreeNode* root=NULL;
	root=new TreeNode(rootArray);
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode* parent=q.front();
		q.pop();
		if(treeArray[parent->value].left!=-1){
			parent->left=new TreeNode(treeArray[parent->value].left);
			q.push(parent->left);
		}
		if(treeArray[parent->value].right!=-1){
			parent->right=new TreeNode(treeArray[parent->value].right);
			q.push(parent->right);
		}
	}
	return root;
}

void levelOrder(TreeNode* root){
	if(root==NULL)
		cout<<"Tree empty\n";
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		int n=q.size();
		while(n--){
			TreeNode* parent=q.front();
			q.pop();
			cout<<parent->value<<" ";
			if(parent->left){
				q.push(parent->left);
			}
			if(parent->right){
				q.push(parent->right);
			}
		}
		cout<<endl;
	}
}
int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> parent(n);
		for(int i=0;i<n;i++)
			cin>>parent[i];
		TreeNode* root=contructTreeFromParent(parent);
		levelOrder(root);
	}
}
