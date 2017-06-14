/*
 * Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in knapsack. 
 * You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
 * Given an item 'n', with value v1 and weight w1, we basically have only two choices: 
      1. To include the item in the knapsack 
      2. To exclude the item from the knapsack. 
 * At each item 'n', we compute the value that could be obtained in both include and exclude cases and choose the case which 
 * gives more value. If we choose to include the item 'n', then we decrease the weight limit by w1 and then compute the maximum 
 * possible benefit using items from 'n+1' onwards(benefit_n_Plus). 
 * This maximum possible benefit(benefit_n_Plus) + (benefit of including item 'n') is maximum benefit obtained in the include 
 * case for item n. Now in the exclude case, weight limit is not modified and maximum possible benefit is computed from item 
 * 'n+1' onwards. This computed benefit is the maximum possible benefit for item 'n' in exclude case. 
 * We compare the benefits obtained in include and exclude case and return the maximum of these two values.  
 * To compute maximum possible benefits from item 'n+1' onwards, recursive calls are made with modified weight limit in the 
 * include case. Base case for the recursion would be when all the items are considered or when the weight limit remaining is 0. 
 * In both of these cases, benefit returned is 0.
 * If we draw recursion tree fro above approach ,many states in recursion tree are repeated and hence redundant computations 
 * are performed. TC of this approach is exponential. O(2^n). (Because we have 2 choices at every stage)
 * Since suproblems are evaluated again, this problem has Overlapping Subprolems property. 
 * So the 0-1 Knapsack problem has both properties of a dynamic programming problem. Like other typical Dynamic Programming(DP) 
 * problems, recomputations of same subproblems can be avoided by constructing a temporary array in bottom up manner or top down
 * manner. Following is bottom up aprroach in Dynamic Programming based implementation.
 */
#include<bits/stdc++.h>
using namespace std;

int knapsackZeroOne(vector<int> &value, vector<int> &weight, int index, int remaining_weight){
	if(index>value.size())
		return 0;
	if(weight[index]<=remaining_weight)
		return max(value[index]+knapsackZeroOne(value,weight,index+1,remaining_weight-weight[index]),
			knapsackZeroOne(value,weight,index+1,remaining_weight));
	else
		return knapsackZeroOne(value,weight,index+1,remaining_weight);
}

int knapsackZeroOneDP(vector<int> &value, vector<int> &weight, int total){
	// Intialized col as total weight given  +1.
	int col=total+1;
    // Initialize row as the number of items + 1.
	int row=weight.size()+1;
    // Declare DP table of the size of row*col
	int table[row][col];
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
        	// If total weight is 0, then we should not pick any item. Thus value should be zero
    		// However if total weight is nonzero, but no item is given. In that case too, value should be
    		// zero because we don't have any item to pick
			if(i==0||j==0)
				table[i][j]=0;
        	// If weight of knapsack is greater than the weight of the current item, we can eaither pick this item
        	// or discard it
			else if(j>=weight[i-1]){
            	// If we pick item, our total weight will be decreased by the weight of item picked
            	// and now we have to choose among the remaining items, the subproblem which we have already solved
            	// Hence add both values.
            	// If we don't pick this item , we have to discard it and our value remains same as the value we got
            	// in previous items
            	// We take max of the above two scenarios, and assign this value as the current table value
				table[i][j]=max(table[i-1][j],value[i-1]+table[i-1][j-weight[i-1]]);
			}
            // If weight of knapsack is less than the weight of current item , we have to discard it. That is the only
            // option we have and thus maximum value we get as same as what we got when we have considered previous item
			else
				table[i][j]=table[i-1][j];
		}
	} 
	// last value of table now contains the maximum value we can get by choosing among the given weights attached
	// with certain values, such that their sum of total weights doesn't exceed "total". This is our answer
	return table[row-1][col-1];
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n,w;
		cin>>n;
		vector<int> value(n);
		vector<int> weight(n);
		for(int i=0;i<n;i++)
		{
			cin>>value[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>weight[i];
		}
		cin>>w;
		//cout<<knapsackZeroOne(value,weight,0,w);
		cout<<knapsackZeroOneDP(value,weight,w);
	}
}
