/*
 * Given a 2D matrix, print all elements of the given matrix in diagonal order. 
 * For example, consider the following 5 X 4 input matrix.

        1     2     3     4
        5     6     7     8
        9    10    11    12
       13    14    15    16
       17    18    19    20

    Diagonal printing of the above matrix is

        1
        5     2
        9     6     3
       13    10     7     4
       17    14    11     8
       18    15    12
       19    16
       20
       
  * This is Zig Zag upper traversal
  * Zig Zag lower traversal can be possible too in a similar manner
  * TC:O(m*n)
  */
  
#include<bits/stdc++.h>
#define N 5
#define M 5
using namespace std;

void printMatrixZigZagUpper(int matrix[N][M]){
	for(int k=0;k<N-1;k++){
		int i=k;
		int j=0;
		while(i>=0)
			cout<<matrix[i--][j++]<<" ";
		cout<<endl;
	}
	for(int k=0;k<M;k++){
		int i=N-1;
		int j=k;
		while(j<M)
			cout<<matrix[i--][j++]<<" ";
		cout<<endl;
	}

}

void printMatrixZigZagLower(int matrix[N][M]){
	for(int k=0;k<M;k++){
		int i=0;
		int j=k;
		while(j>=0)
			cout<<matrix[i++][j--]<<" ";
		    cout<<endl;
	}
	for(int k=1;k<N;k++){
		int i=k;
		int j=M-1;
		while(i<N)
			cout<<matrix[i++][j--]<<" ";
    		cout<<endl;
	}
}

int main(){
	int matrix[N][M];
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>matrix[i][j];
	printMatrixZigZagUpper(matrix);
	printMatrixZigZagLower(matrix);
}


