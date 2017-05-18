#include<bits/stdc++.h>
using namespace std;
vector<bool> visited;
#define P pair<int,int>
#define TYPE list<int>::iterator
bool bfs(vector<list<int> > &graph, int u,vector<bool> &visited){
	bool cycle=false;
	queue<P> q;
	q.push(make_pair(u,-1));
	visited[u]=true;
	while(!q.empty()){
		P front=q.front();
		int u=front.first;
		int parent=front.second;
		q.pop();
		for(TYPE itr=graph[u].begin();itr!=graph[u].end();itr++){
			int v=(*itr);
			if(!visited[v]){
				visited[v]=true;
				q.push(make_pair(v,u));
			}
			else if(v!=parent){
				return true;
			}
		}
	}
	return false;
}

bool hasCycle(vector<list<int> > &graph){
	int n=graph.size();
	visited.resize(n,false);
	for(int i=0;i<n;i++){
		if(!visited[i]){
			if(bfs(graph,i,visited))
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
