/*
 * Given a collection of Intervals,merge all the overlapping Intervals For example:
 * Given [1,3], [2,6], [8,10], [15,18],
 * return [1,6], [8,10], [15,18].
 * Make sure the returned intervals are sorted.
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

bool customSort(pair<int,int> &p1, pair<int,int> &p2){
    if(p1.first<p2.first)
        return true;
    else
        return false;
}

bool overlapsWithTopElement(pair<int,int> &p1, pair<int,int> &p2 ){
    if(p2.first>=p1.first && p2.first<=p1.second)
        return true;
    else
        return false;
}

pair<int,int> mergeTwoInterval(pair<int,int> &p1, pair<int,int> &p2 ){
    pair<int,int> mergedInterval;
    mergedInterval.first = p1.first;
    mergedInterval.second = (p2.second > p1.second) ? p2.second : p1.second;
    return mergedInterval;
}
void mergeIntervals(vector<pair<int,int> > &intervals){
    sort(intervals.begin(),intervals.end(),customSort);
    stack<pair<int,int> > s;
    for(int i=0;i<intervals.size();i++){
        if(!s.empty() && overlapsWithTopElement(s.top(),intervals[i])){
            pair<int,int> mergedInterval = mergeTwoInterval(s.top(),intervals[i]);
            s.pop();
            s.push(mergedInterval);
        }
        else{
            s.push(intervals[i]);
        }
    }
    intervals.clear();
    while(!s.empty()){
        intervals.push_back(s.top());
        s.pop();
    }
    for(int i=intervals.size()-1;i>=0;i--){
        cout<<intervals[i].first<<" "<<intervals[i].second<<" ";
    }
    cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<pair<int,int> > intervals(n);
	    for(int i=0;i<n;i++){
	        int x,y;
	        cin>>x>>y;
	        intervals[i] = {x,y};
	    }
	    mergeIntervals(intervals);
	}
	return 0;
}
