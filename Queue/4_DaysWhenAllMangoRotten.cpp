#include<bits/stdc++.h>
using namespace std;
#define N 3
#define M 5
int matrix[N][M];
int rotten[N][M];

int numberOfDaysWhenAllRotten(){
	queue<pair<int,int> > q;
	// initializing the rotten matrix, initially all are not rotten, used to check no orange is rotten more than once
	memset(rotten,false,sizeof(rotten));
	// variable that will count number of 1 in matrix in initially, used to check at last whether all oranges are rotten or not
	int totalNotRotten=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(matrix[i][j]==2){
				// pushing in queue those oranges who are rotten, that is have value 2
				q.push(make_pair(i,j));
				// making rotten oranges true in rotten matrix
				rotten[i][j]=true;
			}
			// Maintain count of non rotten oranges
			else if(matrix[i][j]==1)
				totalNotRotten++;
		}
	}
	int days=-1;
	while(!q.empty()){
		int numberofRottenAtThisDay=q.size();
		days++;
		// This loop will pop oranges that are already rotten, and pushes those adjacent oranges that are rotten by them on that day
		// This will also decrease number of 1 effectively, which we can check at last to see if all 1's are rotted or not
		while(numberofRottenAtThisDay--){
			pair<int,int> cell=q.front();
			int i=cell.first;
			int j=cell.second;
			cout<<"i:"<<i<<",j:"<<j<<" , el:"<<matrix[i][j]<<" is popped\n"<<endl;
			q.pop();
			// pushes the cell on top if it has mango and is not rotten
			if(i-1>=0 && !rotten[i-1][j] && matrix[i-1][j]==1){
				rotten[i-1][j]=true;
				q.push(make_pair(i-1,j));
				totalNotRotten--;
			}
			// pushes the cell on bottom if it has mango and is not rotten
			if(i+1<N && !rotten[i+1][j] && matrix[i+1][j]==1){
				rotten[i+1][j]=true;
				q.push(make_pair(i+1,j));
				totalNotRotten--;
			}
			// pushes the cell on left if it has mango and is not rotten
			if(j-1>=0 && !rotten[i][j-1] && matrix[i][j-1]==1){
				rotten[i][j-1]=true;
				q.push(make_pair(i,j-1));
				totalNotRotten--;
			}
			// pushes the cell on right if it has mango and is not rotten
			if(j+1<M && !rotten[i][j+1] && matrix[i][j+1]==1){
				rotten[i][j+1]=true;
				q.push(make_pair(i,j+1));
				totalNotRotten--;
			}
		}
	}
	// If every mango is rotten, return days else return -1
	if(totalNotRotten==0)
		return days;
	else
		return -1;
}
int main(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>matrix[i][j];
		}
	}
	cout<<numberOfDaysWhenAllRotten()<<endl;

}
