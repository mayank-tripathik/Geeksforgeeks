// In Bt, to find max or min of all nodes we have to visite each node.
// So the idea is to traverse the given tree and for every node return maximum of 3 values.
// 1) Node’s data.
// 2) Maximum in node’s left subtree.
// 3) Maximum in node’s right subtree.
// similarly we can do for min case
int findMax(struct node* root)
{
    if(root == NULL)
        return INT_MIN;
    else{
        int leftSubtreeMax=findMax(root->left);
        int rightSubtreeMax=findMax(root->right);
        return  max(root->data,max(leftSubtreeMax,rightSubtreeMax));
    }
}

int findMin(struct node* root)
{
    if(root == NULL)
        return INT_MAX;
    else{
        int leftSubtreeMin=findMin(root->left);
        int rightSubtreeMin=findMin(root->right);
        return min(root->data,min(leftSubtreeMin,rightSubtreeMin));;
    }
}
