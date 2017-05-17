#include<bits/stdc++.h>
using namespace std;
vector<int> topologicalArray;
void print(vector<int> &arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void dfs(vector<list<int> > &graph, int u, vector<bool> &visited){
	visited[u]=true;
	list<int>::iterator itr;
	for(itr=graph[u].begin();itr!=graph[u].end();itr++){
		int v=(*itr);
		if(!visited[v])
			dfs(graph,v,visited);
	}
	topologicalArray.push_back(u);
}

void topologicalSort(vector<list<int> >&graph){
	int n=graph.size();
	vector<bool> visited(n,false);
	for(int i=0;i<n;i++){
		if(!visited[i])
			dfs(graph,i,visited);
	}
	cout<<"Topological ordering:\n";
	for(int i=topologicalArray.size()-1;i>=0.;i--)
		cout<<topologicalArray[i]<<" ";
	cout<<endl;
	topologicalArray.clear();
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
		}
		topologicalSort(graph);
	}
}
