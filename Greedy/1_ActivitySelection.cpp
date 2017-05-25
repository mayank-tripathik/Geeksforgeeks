/*
 * You are given n activities with their start and finish times. 
 * Select the maximum number of activities that can be performed by a single person, 
 * Assume that a person can only work on a single activity at a time.
 * Greedy approach works here
 * The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start 
 * time is more than or equal to the finish time of previously selected activity. 
 * Sorting activities according to finishing time ensures the next activity as minimum finishing time activity.
 * TC: O(nlogn) as sorting is done
 */


#include<bits/stdc++.h>
using namespace std;
#define P pair<int,int>


struct activity
{
	int start;
	int finish;	
};

//Comparator for sorting activities according to increasing finishing time
bool compare(const activity &l, const activity &r){
	if(l.finish < r.finish)
		return true;
	else
		return false;
}


vector<int> activitySelection(vector<activity> &activities){
	vector<int> ans;
	//sorting activities based on their finishing time
	sort(activities.begin(),activities.end(),compare);
	//Always picking first activity
	ans.push_back(0);
	//Picking each sorted activity and compares its start time with the finish time of previously selected activity
	for(int i=1;i<activities.size();i++){
		if(activities[i].start>=activities[ans[ans.size()-1]].finish)
			ans.push_back(i);

	}
	//returning list of selected activities
	return ans;

}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<activity> activities(n);
		for(int i=0;i<n;i++)
			cin>>activities[i].start;
		for(int i=0;i<n;i++)
			cin>>activities[i].finish;
		vector<int> ans=activitySelection(activities);
		cout<<"Following activities are selected:\n";
		for(int i=0;i<ans.size();i++){
			int index=ans[i];
			cout<<"("<<activities[index].start<<" "<<activities[index].finish<<")\n";
		}
	}
}
