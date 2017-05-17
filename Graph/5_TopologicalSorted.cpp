#include<bits/stdc++.h>
using namespace std;
vector<int> topologicalArray;
void print(vector<int> &arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
vector<int> getadjacent(vector<list<int> >&graph, int u){
    list<int>::iterator itr;
    vector<int> adj;
    for(itr=graph[u].begin();itr!=graph[u].end();itr++){
			int v=(*itr);
			adj.push_back(v);
		}
	sort(adj.begin(),adj.end(),greater<int>());
	//cout<<"adj of u:"<<u<<endl;
	//print(adj);
	return adj;
}

void dfs(vector<list<int> > &graph, int u, vector<bool> &visited){
	visited[u]=true;
	//cout<<"u:"<<u<<endl;
	vector<int> adjlist=getadjacent(graph,u);
	for(int i=0;i<adjlist.size();i++){
		int v=adjlist[i];
		if(!visited[v])
			dfs(graph,v,visited);
	}
	//cout<<"u is finished and pushed:"<<u<<endl;
	topologicalArray.push_back(u);
}

void topologicalSort(vector<list<int> >&graph){
	int n=graph.size();
	vector<bool> visited(n,false);
	for(int i=n-1;i>=1;i--){
		if(!visited[i])
			dfs(graph,i,visited);
	}
	//cout<<"Topological ordering:\n";
	for(int i=topologicalArray.size()-1;i>=0.;i--)
		cout<<topologicalArray[i]<<" ";
	cout<<endl;
	topologicalArray.clear();
}

int main(){
		int n,e;
		cin>>n>>e;
		vector<list<int> > graph(n+1);
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			graph[u].push_back(v);
		}
		topologicalSort(graph);
}


#include<bits/stdc++.h>
using namespace std;
#define LOWNODE 1
int flag=true;
void print(vector<int> &arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void dfs(vector<list<int> >&graph, vector<int> &indegree, vector<int> &temp, vector<bool> &visited){
	if(temp.size()==graph.size()-1){
		print(temp);
		flag=false;
	}
	for(int i=LOWNODE;i<graph.size() && flag;i++)
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
void topologicalSort(vector<list<int> >&graph, vector<int> &indegree){
	int n=graph.size();
	vector<int> temp;
	vector<bool> visited(n,false);
	//print(indegree);
	//print(temp);
	dfs(graph,indegree,temp,visited);
}

int main(){
		int n,e;
		cin>>n>>e;
		vector<list<int> > graph(n+1);
		vector<int> indegree(n+1,0);
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			graph[u].push_back(v);
			indegree[v]++;
		}
		topologicalSort(graph,indegree);
}
