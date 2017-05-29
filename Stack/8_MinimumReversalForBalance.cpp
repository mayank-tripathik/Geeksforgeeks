    #include<bits/stdc++.h>
    using namespace std;
    #define OPENPAREN '{'
    #define CLOSEPAREN '}'
     
    bool minimumReversals(string &str){
    	stack<char> s;
    	int counter=0;
    	//cout<<str<<endl;
    	for(int i=0;i<str.size();i++){
    		if(s.empty() || str[i]==OPENPAREN){
    			s.push(str[i]);
    			//cout<<str[i]<<" is pushed\n";
    		}
    		else if(str[i]==CLOSEPAREN){
    			if(s.top()==OPENPAREN){
    				//cout<<s.top()<<" is popped\n";
    				s.pop();
    			}
    			else{
    				s.push(str[i]);
    				//cout<<str[i]<<" is pushed\n";
    			}
    		}
    	}
    	while(!s.empty()){
    		char c1=s.top();
    		s.pop();
    		if(s.empty())
    			return false;
    		char c2=s.top();
    		s.pop();
    		if((c1==OPENPAREN && c2==OPENPAREN) || (c1==CLOSEPAREN && c2==CLOSEPAREN))
    			counter++;
    		else if(c1==OPENPAREN && c2==CLOSEPAREN)
    			counter=counter+2;
    	}
    	cout<<counter<<endl;
    	return true;
    }
    int main(){
    	int test;
    	cin>>test;
    	while(test--){
    		string expr;
    		cin>>expr;
    		bool possible=minimumReversals(expr);
    		if(!possible)
    			cout<<"Not possible\n";
    	}
    }
