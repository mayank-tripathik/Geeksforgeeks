/*
 * Consider lines of slope -1 passing between nodes. 
 * Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
 * The idea is to use map. We use different slope distances and use them as key in map. 
 * Value in map is vector (or dynamic array) of nodes. 
 * We traverse the tree to store values in map. Once map is built, we print contents of it.
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

void diagonalTraversalIterative(TreeNode* root)
{
	if(root == NULL)
		return;

	queue<TreeNode*> que;

	que.push(root);

    //add the root of the tree to the queue..
	while(!que.empty())
	{
		int size = que.size();
        /*
         The idea here is to take the left most node of each diagonal 
         into the queue and print out all the nodes lying on the right
         of this node(nodes to the right in the same diagonal).
         in the above example:
         8 is the leftmost node of the first diagonal. So we print all
         the nodes on the right of this node in this diagonal. So we print
         10 and 14.
         In this process we add all the immediate left child of these 
         nodes into the queue since they are the leftmost nodes of
         the next consecutive diagonals.
         
         We use the size variable to keep track the number of nodes in 
         the queue that belong to the current diagonal.
         in the above example:
         once we print the first diagonal 8, 10, 14 the queue will have 2
         nodes 3 and 13 which are the leftmost nodes of the
         next diagonal. So we use these to print the corresponding nodes.
         In this process we will add nodes 1, 4 into the queue. So if we
         dont have the size of the queue, before pusing these new nodes
         then we will not be able to track the elemets that belong to this
         diagonal. For this purpose we use the variable size in our program.
         
         Hope this helps..
         */
		while(size--)
		{
			TreeNode* temp = que.front();
			que.pop();

			while(temp)
			{
				cout << temp -> value << " ";
				if(temp -> left)
					que.push(temp -> left);
				temp = temp -> right;
			}
		}
		cout << endl;
	}
}

// This map uses inorder traversal to traverse the tree. Any traversal can be used as
// long as the slop that is passed is set correctly
void setMap(TreeNode* root, int slope,map<int,vector<int> > &hash){
	if(root==NULL)
		return;
	// Move to left subtree. Increase the slope by 1, whenever move left. Note that
	// We could have also decreased the slope. But then be have to print the map starting from end
	// We can change slope by any operation while moving left. But change should be consistent throughout 
	setMap(root->left,slope+1,hash);
	// instead of printing, as we do in typical inorder, push the value of node in the array belonging
	// to its slope
	hash[slope].push_back(root->value);
	// Then move to right subtree. While moving right, don't change the slope. Thus all elements as we go
	// to the right of a node have same slope. Thus they form a diagonal
	setMap(root->right,slope,hash);
}

// This function prints nodes of the tree, diagonal wise
void diagonalTraversal(TreeNode *root)
{
	// if tree is empty, nothing to print
	if(root==NULL)
		return;
	// initialize a map, with key as slope and value as array of integers
	// Nodes with same slope belong to same diagonals,hence they are pushed to arraylist
	// of their respective slopes. In this way, we will eventually get different list of 
	// values, each belonging to diferent diagonals of tree
	map<int,vector<int> > hash;
	// This function fills the map as explained above
	setMap(root,0,hash);
	map<int,vector<int> >::iterator itr;
	// When the map gets filled with different slope vales and their corresponding elements belong to them
	// just print them using a iterator
	for(itr=hash.begin();itr!=hash.end();++itr){
		int key=(*itr).first;
		vector<int> value=(*itr).second;
		for(int i=0;i<value.size();i++)
			cout<<value[i]<<" ";
		cout<<endl;
	}
}

int main(){
	TreeNode *root=new TreeNode(8);
	root->left=new TreeNode(3);
	root->right=new TreeNode(10);
	root->left->left=new TreeNode(1);
	root->left->right=new TreeNode(6);
	root->right->right=new TreeNode(14);
	root->left->right->left=new TreeNode(4);
	root->left->right->right=new TreeNode(7);
	root->right->right->left=new TreeNode(13);
	diagonalTraversal(root);
	diagonalTraversalIterative(root);
}
