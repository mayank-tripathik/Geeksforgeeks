#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
private:
	vector<int> parent;
	vector<int> rank;
	int numberOfDisjointSets;
public:
	DisjointSet(int n){
		parent.resize(n);
		rank.resize(n,1);
		numberOfDisjointSets=n;
		for(int i=0;i<n;i++)
			parent[i]=i;
	}
	//Path Compression
	int findParent(int x){
		if(parent[x]==x)
			return x;
		else
			return parent[x]=findParent(parent[x]);
	}
	//Unite two sets based on their ranks
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
			numberOfDisjointSets--;
			return true;
		}
	}	
	int numberOfSets(){
		return numberOfDisjointSets;
	}
	void printParent(){
		cout<<"Parent Array:\n";
		for(int i=0;i<parent.size();i++)
			cout<<parent[i]<<" ";
		cout<<endl;
	}
	void printRank(){
		cout<<"Rank Array:\n";
		for(int i=0;i<rank.size();i++)
			cout<<rank[i]<<" ";
		cout<<endl;
	}
};

int main(){
	int test;
	cin>>test;
	while(test--){
		int n,e;
		cin>>n>>e;
		DisjointSet ds(n);
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			cout<<u<<" and "<<v<<endl;
			ds.unionSet(u,v);
			ds.printParent();
			ds.printRank();
			cout<<ds.numberOfSets()<<endl;
		}
	}
}
