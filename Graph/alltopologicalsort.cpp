#include<bits/stdc++.h>
using namespace std;

//lowest graph nodes is numbered as 1
#define LOWNODE 0

//Function to print array
void print(vector<int> &arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

//A recursive function that recurr for 
void dfs(vector<list<int> >&graph, vector<int> &indegree, vector<int> &temp, vector<bool> &visited){
	if(temp.size()==graph.size()){
		print(temp);
	}
	for(int i=LOWNODE;i<graph.size();i++)
	{
		int u=i;
		if(!visited[u] && indegree[u]==0){
			visited[u]=true;
			temp.push_back(u);
			list<int>::iterator itr;
			for(itr=graph[u].begin();itr!=graph[u].end();itr++){
				int v=(*itr);
				indegree[v]--;
			}
			dfs(graph,indegree,temp,visited);
			for(itr=graph[u].begin();itr!=graph[u].end();itr++){
				int v=(*itr);
				indegree[v]++;
			}
			visited[u]=false;
			temp.pop_back();
		}
	}
}
void allTopologicalSort(vector<list<int> >&graph, vector<int> &indegree){
	int n=graph.size();
	vector<int> temp;
	vector<bool> visited(n,false);
	cout<<"All possible topological orderings are:\n";
	dfs(graph,indegree,temp,visited);
}

int main(){
		int n,e;
		cin>>n>>e;
		n=n+LOWNODE;
		vector<list<int> > graph(n);
		vector<int> indegree(n,0);
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			graph[u].push_back(v);
			indegree[v]++;
		}
		allTopologicalSort(graph,indegree);
}
