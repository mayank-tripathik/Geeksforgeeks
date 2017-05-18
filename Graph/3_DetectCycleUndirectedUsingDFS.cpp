#include<bits/stdc++.h>
using namespace std;
vector<bool> visited;

bool dfs(vector<list<int> > &graph, int u, int parent){
	visited[u]=true;
	cout<<"u:"<<u<<endl;
	list<int>::iterator itr;
	for(itr=graph[u].begin();itr!=graph[u].end();itr++){
		int v=(*itr);
		if(!visited[v])
			return dfs(graph,v,u);
		else if(v!=parent)
			return true;
	}
	return false;
}

bool hasCycle(vector<list<int> > &graph){
	int n=graph.size();
	visited.resize(n,false);
	for(int i=0;i<n;i++){
		cout<<"i:"<<i<<endl;
		if(!visited[i]){
			if(dfs(graph,i,-1))
				return true;
		}
	}
	return false;
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n,e;
		cin>>n>>e;
		vector<list<int> > graph(n);
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		if(hasCycle(graph))
			cout<<"has cycle\n";
		else
			cout<<"no cycle\n";
	}
}
