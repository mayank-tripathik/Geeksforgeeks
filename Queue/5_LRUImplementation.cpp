#include<bits/stdc++.h>
using namespace std;

// LRU implementation using queue and a stack
class LRU{
	deque<int> q;
	vector<bool> pageInSlot;
	int size;
	int pageFaults;
public:
	LRU(int slots, int pages){
		pageInSlot.resize(pages,false);
		size=slots;
		pageFaults=0;
	}
	bool cacheFull(){
		if(q.size()==size)
			return true;
		else
			return false;
	}
	void print(){
		for(int i=0;i<q.size();i++)
			cout<<q[i]<<" ";
		cout<<endl;
	}
	void insertPage(int page){
		if(pageInSlot[page]){
			stack<int> temp;
			while(q.back()!=page){
				temp.push(q.back());
				q.pop_back();
			}
			int x=q.back();
			q.pop_back();
			while(!temp.empty()){
				q.push_back(temp.top());
				temp.pop();
			}
			q.push_back(x);
		}
		else{
			if(cacheFull()){
				pageInSlot[q.front()]=false;
				q.pop_front();
				q.push_back(page);
				pageInSlot[page]=true;
				pageFaults++;
			}
			else{
				q.push_back(page);
				pageInSlot[page]=true;
			}
		}
	}
	int getPageFaults(){
		return pageFaults;
	}
};

// LRU implementation using queue and a hasmap of value and addresses
class LRU{
	list<int> cache;
	int slots;
	int size;
	int pageFaults;
	map<int,list<int>::iterator> hash;
public:
	LRU(int _slots){
		slots=_slots;
		pageFaults=0;
		size=0;
	}
	void insertPage(int page){
		map<int,list<int>::iterator>::iterator itr;
		itr=hash.find(page);
		if(itr!=hash.end()){
			cout<<"insdie found\n";
			list<int>::iterator temp=(*itr).second;
			int value=(*temp);
			cout<<"value:"<<value<<endl;
			hash.erase(itr);
			cache.erase(temp);
		 	cache.push_front(page);
		 	hash.insert(make_pair(page,cache.begin()));
		}
		else{
			if(slots>size){
				cout<<"insdie less\n";
				cache.push_front(page);
				hash.insert(make_pair(page,cache.begin()));
				size++;
				cout<<"size if incremented to:"<<size<<endl;
			}
			else{
				cout<<"insdie equal\n";
				cache.pop_back();
				cache.push_front(page);
				hash.insert(make_pair(page,cache.begin()));
				pageFaults++;
			}
		}
	}
	int getPageFaults(){
		return pageFaults;
	}
	void print(){
		list<int>::iterator itr;
		for( itr=cache.begin();itr!=cache.end();itr++)
			cout<<(*itr)<<" ";
		cout<<endl;
	}

};

int main(){
	int frames,pages;
	cin>>frames>>pages;
	LRU cache(frames);
	int requests;
	cin>>requests;
	while(requests--){
		int page;
		cin>>page;
		cout<<"Page Requested:"<<page<<endl;
		cache.insertPage(page);
		cout<<"Cache is:";
		cache.print();
		cout<<endl;
	}
	cout<<"Page Faults:"<<cache.getPageFaults()<<endl;
}
