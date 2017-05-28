#include <bits/stdc++.h>
using namespace std;
 
// Max # of persons in the party
#define N 8

//knowledge base of people knowing each other 
bool  MATRIX[N][N] = {{0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0}
};

//Simulates havingAcquaintance function, returns true if i knows j  
bool knows(int i, int j){
	if(MATRIX[i][j]==1)
		return true;
	else
		return false;
}

//First finds the candidate using two pointer method , and then checks if it is actually a celebrity
int findCelebrity(int n){
	int i=0,j=n-1;
	while(i<j){
		if(knows(i,j))
			i++;
		else
			j--;

	}
	//Candidate of celebrity
	int c=i;
	//Actually checking if c knows anyone or if there is anyone who doesn't knows c
	for(i=0;i<n;i++){
		if(c!=i && (knows(c,i) || !knows(i,c))){
			c=-1;
			break;
		}
	}
	return c; 
} 

int main()
{
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" :
               cout << "Celebrity ID " << id;
    return 0;
}
