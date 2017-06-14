/*The structure of node is as follows
struct node{
	string data;
	node *left;
	node *right;
};
*/

/*You are required to complete below method */

int toInteger(string str){
    int k;
    if(str[0]=='-')
        k=1;
    else
        k=0;
    int num=0;
    for(int i=k;i<str.size();i++){
        int digit=str[i]-'0';
        num=num*10+digit;
    }
    //cout<<"num\n"<<num<<endl;
    if(k==1)
    return -1*num;
    else
    return num;
}

int apply(int op1, int op2, string c){
    if(c=="+")
    return op1+op2;
    else if(c=="-")
    return op1-op2;
    else if(c=="/")
    return op1/op2;
    else if(c=="*")
    return op1*op2;
}
bool isOperator(string c){
    if(c=="+"||c=="/"||c=="*"||c=="-")
    return true;
    else
    return false;
}
void evaluate(node* root,stack<int> &s){
    if(root==NULL)
    return;
    evaluate(root->left,s);
    evaluate(root->right,s);
    if(isOperator(root->data)){
        int op1=s.top();s.pop();
        int op2=s.top();s.pop();
        int result=apply(op2,op1,root->data);
        s.push(result);
    }
    else{
        int num=toInteger(root->data);
        s.push(num);
    }
}
int evalTree(node* root)
{
    stack<int> s;
    evaluate(root,s);
    return s.top();
    return 0;
}
