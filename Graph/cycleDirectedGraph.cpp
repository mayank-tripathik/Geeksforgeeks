#include<bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<int> recstack;
#define AUTO list<int>::iterator

enum color
{
	WHITE,GRAY,BLACK
};


bool dfsIterative(vector<list<int> > &graph, int u){
	int n=graph.size();
	vector<int> color(n,WHITE);
	stack<int> s;
	s.push(u);
	while(!s.empty())
	{
		int u=s.top();s.pop();				
		if(color[u]==WHITE)
		{
			color[u]=GRAY;
			s.push(u);
			AUTO itr;
			for(itr=graph[u].begin();itr!=graph[u].end();itr++)
			{
				int v=(*itr);
				if(color[v]==WHITE){
					s.push(v);
				}
				else if(color[v]==GRAY){
					return true;
				}
			}
		}
		else if(color[u]==GRAY){
			color[u]=BLACK;
		}
	}
	return false;
}

bool dfs(vector<list<int> > &graph, int u){
	visited[u]=true;
	cout<<"u:"<<u<<endl;
	list<int>::iterator itr;
	recstack[u]=true;
	for(itr=graph[u].begin();itr!=graph[u].end();itr++){
		int v=(*itr);
		if(!visited[v] && dfs(graph,v)){
			return true;
		}
		else if(recstack[v]){
			return true;
		}
	}
	recstack[u]=false;
	return false;
}

bool hasCycle(vector<list<int> > &graph){
	int n=graph.size();
	visited.resize(n,false);
	recstack.resize(n,false);
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
