#include<bits/stdc++.h>
using namespace std;
vector<int> color;
#define AUTO list<int>::iterator

enum color
{
	WHITE,GRAY,BLACK
};


bool dfsIterative(vector<list<int> > &graph, int u){
	int n=graph.size();
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

bool dfsColor(vector<list<int> > &graph, int u){
	AUTO itr;
	color[u]=GRAY;
	for(itr=graph[u].begin();itr!=graph[u].end();itr++){
		int v=(*itr);
		if(color[v]==WHITE && dfsColor(graph,v)){
			return true;
		}
		else if(color[v]==GRAY){
			return true;
		}
	}
	color[u]=BLACK;
	return false;
}

bool hasCycle(vector<list<int> > &graph){
	int n=graph.size();
	color.resize(n,WHITE);
	for(int i=0;i<n;i++){
		if(color[i]==WHITE){
			if(dfsColor(graph,i))
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
