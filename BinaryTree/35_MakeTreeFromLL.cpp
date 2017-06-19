/*
 * Given Linked List Representation of Complete Binary Tree, construct the Binary tree.
 * Your task is to complete the function convert which takes two arguments the first being the head denoting the head of the 
 * linked list and the second argument is root denoting the root of the tree to be constructed.
 * If root node is stored at index i, its left, and right children are stored at indices 2*i+1, 2*i+2 respectively.
 * We are mainly given level order traversal in sequential access form. 
 * We know head of linked list is always is root of the tree. We take the first node as root and we also know that the next 
 * two nodes are left and right children of root. So we know partial Binary Tree. 
 * The idea is to do Level order traversal of the partially built Binary Tree using queue and traverse the linked list at the 
 * same time. At every step, we take the parent node from queue, make next two nodes of linked list as children of the parent 
 * node, and enqueue the next two nodes to queue.
 * TC:O(n)
 */

/*
The structure of Link list node is as follows 
struct node
{
    int data;
    struct node* next;
};

The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

/*You are required to complete this method*/
TreeNode* newTreeNode(int x){
	TreeNode* temp=new TreeNode();
	temp->left=temp->right=NULL;
	temp->data=x;
	return temp;
	
}

void convert(node *head,TreeNode * &root)
{
  //Your code here
	if(head==NULL)
		root=NULL;
	root=newTreeNode(head->data);
	queue<TreeNode*> q;
	q.push(root);
	head=head->next;
	while(head){
		TreeNode* parent=q.front();
		TreeNode* temp=newTreeNode(head->data);
		parent->left=temp;
		q.push(parent->left);
		head=head->next;
		if(head){
			TreeNode* temp=newTreeNode(head->data);
			parent->right=temp;
			q.push(parent->right);
			head=head->next;
			q.pop();
		}
	}
}
