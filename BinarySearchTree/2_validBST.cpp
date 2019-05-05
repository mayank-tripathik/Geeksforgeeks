bool isValid(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root==NULL)
            return true;
        cout<<"root:"<<root->val<<endl;
        if(min && root->val <= min->val){
            cout<<"min:"<<min->val<<endl;
            return false;
        }
        if(max && root->val >= max->val){
            cout<<"max:"<<max->val<<endl;
            return false;
        }
        return (isValid(root->left,min,root)&&isValid(root->right,root,max));
    }
    bool isValidBST(TreeNode* root) {
        TreeNode *min = NULL;
        TreeNode *max = NULL;
        return isValid(root,NULL,NULL);
    }
