#include<iostream>
#include<vector>
using namespace std;


class DisjointSet{
public:
	vector<int> parent;
	vector<int> rank;
public:
	DisjointSet(int n){
		parent.resize(n);
		rank.resize(n,1);
		for(int i=0;i<n;i++)
			parent[i]=i;
	}
	int findParent(int x){
		while(parent[x]!=x)
			x=parent[x];
		return x;
	}
	bool unionSet(int x, int y){
		x=findParent(x);
		y=findParent(y);
		if(x==y)
			return false;
		else{
			if(rank[x]>rank[y]){
				parent[y]=x;
				rank[x]+=rank[y];
				rank[y]=0;
			}
			else{
				parent[x]=y;
				rank[y]+=rank[x];
				rank[x]=0;
			}
			return true;
		}
	}
};

struct edge{
	int u,v;
	edge(int _u, int _v ){
		u=_u;
		v=_v;
	}
};

int main(){
	int test;
	cin>>test;
	while(test--){
		int n,e;
		cin>>n>>e;
		vector<edge> edges;
		DisjointSet ds(n+1);
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			edges.push_back(edge(u,v));
		}
		bool hasCycle=false;
		for(int i=0;i<edges.size();i++){
			int u=edges[i].u;
			int v=edges[i].v;
			cout<<u<<" "<<v<<endl;
			if(!ds.unionSet(u,v)){
				hasCycle=true;
				break;
			}
		}
		if(!hasCycle)
			cout<<"cycle doesn't exist"<<endl;
		else
			cout<<"cycle exist!\n";
	}
}
