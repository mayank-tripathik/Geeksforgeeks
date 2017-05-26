/*
 * Given a number n, generate binary equivalent of numbers from 1 to n, using queue
 */

#include<bits/stdc++.h>
using namespace std;

void generateBinaryUptoN(int n){
	queue<int> q;
	q.push(1);
	int counter=0;
	while(!q.empty()){
		int num=q.front();
		q.pop();
		cout<<num<<endl;
		counter++;
		if(counter==n)
			break;
		int addZero=num*10;
		int addOne=addZero+1;
		q.push(addZero);
		q.push(addOne);
	}
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		generateBinaryUptoN(n);
	}

}
