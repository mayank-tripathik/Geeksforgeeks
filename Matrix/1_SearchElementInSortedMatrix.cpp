/*
 * Gien a matrix which is rowwise and coloumnwise sorted, find whether given element is present, otherwise return -1
 * Sample matrix : { {10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};
 * Solution: start from top-right or bottom-left, check if matrix element is equal to x. If it is not, move left or bottom
 * accordingly. Note that we can't start from top-left or bottom-right as their is no definite pattern as we move up or down
 * from them.  if we start from top-left or bottom-right, it is difficult to choose which direction to move. 
 * As from top-left , if we move right , then also element will be bigger, or if we move down then also element will be bigger. 
 * Vice versa if we start from bottom- right. 
 * if we start from any of the other two corners , then element behaviour (increasing/decreasing) is different in two directions.
 * Comeplxity: O(n)
 * Note that binary search can be used on row and coloumn to get O(logm) or O(logn+logm) complexity.
 *  1 2 3 4 4  
    2 3 4 4 6
    3 4 4 6 7
    4 4 6 7 8
    4 6 7 8 9
  * If we do a search for 5 in above. Any single element of the diagonal could be 5 legally. 
  * Unless you check them all, we can't prove it's not there! Since the diagonal has N elements for an NxN matrix, 
  * an optimal algorithm must have at least O(N) comparisons. Any claim of an O(log(N)) is mistaken.
  */

#include<bits/stdc++.h>
using namespace std;
#define coordinate pair<int,int>
int matrix[4][4]={{10, 20, 30, 40},
          	{15, 25, 35, 45},
          	{27, 29, 37, 48},
          	{32, 33, 39, 50}};

void searchForx(int e){
	int x=0,y=3;
	bool found=false;
	while(x<4 && y>=0){
		cout<<matrix[x][y]<<" ";
		if(matrix[x][y]==e){
			found=true;
			break;
		}
		else if(matrix[x][y]>e)
			y--;
		else
			x++;
	}
	if(found)
		cout<<x<<" "<<y<<endl;
	else
		cout<<"-1\n";
}
int main(){
	int x;
	x=34;
	searchForx(x);	
}
