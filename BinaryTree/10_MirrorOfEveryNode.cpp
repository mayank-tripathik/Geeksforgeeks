/*
 * Given a binary tree and certain number of queries in form of node number, print mirror node of every node
 * We can use two queues, one queue for left subtree wherein we push left child first and one for right subtree wherein
 * we push rightchild first. Popping them simultaneously will give mirror node of each other which we will store in
 * an array to give queries in O(1) time
 * TC:O(n), AuxillarySpace:O(n)
 */

#include <bits/stdc++.h>
using namespace std;

struct node{
    int left;
    int right;
    node(){
        left=right=-1;
    }
};

int main()
{
    int n,Q;
    cin>>n>>Q;
    vector<node> tree(n+1);
    for(int i=1;i<=n-1;i++){
        int x,y;
        char type;
        cin>>x>>y>>type;
        if(type=='L')
            tree[x].left=y;
        else
            tree[x].right=y;
    }
    vector<int> ans(n+1,-1);
    queue<int> leftq;
    queue<int> rightq;
    ans[1]=1;
    leftq.push(tree[1].left);
    rightq.push(tree[1].right);
    while(!leftq.empty() && !rightq.empty()){
        int leftParent=leftq.front();
        leftq.pop();
        int rightParent=rightq.front();
        rightq.pop();
        if(leftParent!=-1 || rightParent!=1){
            if(leftParent!=-1 && rightParent!=-1){
                ans[leftParent]=rightParent;
                ans[rightParent]=leftParent;
                leftq.push(tree[leftParent].left);
                leftq.push(tree[leftParent].right);
                rightq.push(tree[rightParent].right);
                rightq.push(tree[rightParent].left);
            }
            else if(leftParent!=-1)
                ans[leftParent]=rightParent;
            else if(rightParent!=-1)
                ans[rightParent]=leftParent;
        }
    }
    while(Q--){
        int x;
        cin>>x;
        cout<<ans[x]<<endl;
    }
    return 0;
}
