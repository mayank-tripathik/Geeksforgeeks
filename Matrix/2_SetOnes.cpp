/*
 * Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) 
 * then make all the cells of ith row and jth column as 1.
 * Example
    The matrix
    1 0
    0 0
    should be changed to following
    1 1
    1 0
    
    Example 2
    The matrix
    0 0 0
    0 0 1
    should be changed to following
    0 0 1
    1 1 1
 * Brute Force: Store poisition of each 1 in array. Then iterate over matrix and for every stored position change whole row and
 * coloumn values to 1. TC:(2n*n^2), Extra Space: O(n^2)
 * Efficient: Since if any value is 1, whole coloumn and row becomes 1. Conversely, a position becomes 1 if any value in
 * corresponding row and coloumn is 1. Thus we need to check only if their is any 1 in all rows and any 1 in all coloumn
 * We can have 2 array, one for storing status of each row, and one for storing each coloumn. How do we fill it>
 * Just iterate over the matrix, and if one is found at position, make correspodning row and coloumn status true
 * How to set ones now? Iterate over the matrix again and if corresponding row or coloumn status is set, make it 1, because
 * it means atleast one row or one coloumn value corresponding to that position is 1
 * TC:O(N*M), Space required: O(M+N). where N is number of rows, and M is number of coloumns
 * Can we do more better? yes in terms of space efficient. We can avoid using extra space by using first row and first coloumn
 * as extra space. But before that we store the status of first row and first coloumn is seperate variable. 
 * Scan the first row and set a variable rowFlag to indicate whether we need to set all 1s in first row or not.
 * Scan the first column and set a variable colFlag to indicate whether we need to set all 1s in first column or not.
 * Use first row and first column as the auxiliary arrays row[] and col[] respectively, consider the matrix as submatrix 
 * starting from second row and second column and apply above method.
 * Finally, using rowFlag and colFlag, update first row and first column if needed.
 * TC:O(M*N). Extra space:O(1)
 */
 
#include<bits/stdc++.h>
#define N 3
#define M 4
using namespace std;

// Brute force method
void setOneNaive(int matrix[N][M]){
	// This array will store all positions of 1
	vector<pair<int,int> > holdsOne;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(matrix[i][j]==1)
				holdsOne.push_back(make_pair(i,j));
		}
	}// Then iterate over array and for each position set all rows and coloumns values corresponding to 
	// it as 1
	for(int k=0;k<holdsOne.size();k++){
		int i=holdsOne[k].first;
		int j=holdsOne[k].second;
		// set all row values 1
		for(int m=0;m<M;m++)
			matrix[i][m]=1;
		// set all coloumn values 1 
		for(int m=0;m<N;m++)
			matrix[m][j]=1;
	}
	// printing matrix
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

void setOnesImprovedWithExtraSpace(int matrix[N][M]) {
	// Array that indicates whether any value corresponding to that row is 1
	vector<int> rowFinished(N,false);
	// Array that indicates whether any value corresponding to that coloumns is 1
	vector<int> colFinished(M,false);
	// Filling above two arrays by traversing matrix
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(matrix[i][j]==1){
				rowFinished[i]=true;
				colFinished[j]=true;
			}
		}
	}
	// Note that whole row and coloumns becomes 0, if that row or coloumns has anywhere 1  in it
	// Thus we again traverse matrix and check whether above any row value or coloumn value corresponding
	// to it has 1 or not(using anove arrays), if it is, we make it 1
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(rowFinished[i] || colFinished[j]){
				matrix[i][j]=1;
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

void setOnesImprovedWithoutExtraSpace(int matrix[N][M]) {
	// Two variables that will store whether first row or first coloumns is to made 1 or not
	bool firstRow=false;
	bool firstCol=false;
	// If any element of first row has 1, whole row becomes 1
	for(int j=0;j<M;j++){
		if(matrix[0][j]==1){
			firstRow=true;
			break;
		}
	}
	// If any element of first coloumn has 1, whole coloumn becomes 1
	for(int i=0;i<N;i++){
		if(matrix[i][0]==1){
			firstCol=true;
			break;
		}
	}
	// Now we have stored the status of first row and first coloumn in seperate variable, we can
	// use first row and first coloumn as the extra arrays that we were using in above step. Therefore
	// start from the matrix except first row and coloumns and set the corresponding row and coloumn value
	for(int i=1;i<N;i++){
		for(int j=1;j<M;j++){
			if(matrix[i][j]==1){
				matrix[i][0]=matrix[0][j]=1;
			}
		}
	}
	// Now we can use first row and first coloumns to fill the submatrix
	for(int i=1;i<N;i++){
		for(int j=1;j<M;j++){
			if(matrix[i][0] || matrix[0][j]){
				matrix[i][j]=1;
			}
		}
	}
	// use first row variable to fill the first row appropriately
	if(firstRow){
		for(int j=0;j<M;j++)
			matrix[0][j]=1;
	}
	// use first coloumn variable to fill the first coloumn appropriately
	if(firstCol){
		for(int i=0;i<N;i++)
			matrix[i][0]=1;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int matrix[N][M];
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>matrix[i][j];
	setOnesImprovedWithoutExtraSpace(matrix);
}


