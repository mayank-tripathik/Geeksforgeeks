#include<bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<int> start;
vector<int> finish;
int counter;
bool dfs(vector<list<int> > &graph, int u){
	visited[u]=true;
	counter++;
	start[u]=counter;
	cout<<"start of u:"<<u<<" is set as:"<<start[u]<<endl;
	cout<<"u:"<<u<<endl;
	list<int>::iterator itr;
	for(itr=graph[u].begin();itr!=graph[u].end();itr++){
		int v=(*itr);
		if(!visited[v]){
			return dfs(graph,v);
		}
		else{
			cout<<"AAAAAAAAAAAAAAAAAlerttttttttttt--\n"<<endl;
			cout<<"start u:"<<u<<" is:"<<start[u]<<" finish u:"<<finish[u]<<endl;
			cout<<"start v:"<<v<<" is:"<<start[v]<<" finish v:"<<finish[v]<<endl;
			if(start[u]>start[v] && finish[v]==0){
				cout<<"inside\n";
				return true;
			}
		}
	}
	counter++;
	finish[u]=counter;
	cout<<"finish of u:"<<u<<" is set as:"<<finish[u]<<endl;
	return false;
}

bool hasCycle(vector<list<int> > &graph){
	int n=graph.size();
	visited.resize(n,false);
	start.resize(n,0);
	finish.resize(n,0);
	counter=0;
	for(int i=0;i<n;i++){
		cout<<"i:"<<i<<endl;
		if(!visited[i]){
			if(dfs(graph,i))
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
		}
		if(hasCycle(graph))
			cout<<"has cycle\n";
		else
			cout<<"no cycle\n";
	}
}
