int moveX[]={1,0,0,-1};
int moveY[]={0,-1,1,0};
string path="";
bool isValid(int x, int y, int n){
	return (x>=0 && x<n && y>=0 && y<n);
}

string typeOfMovement(int direction){
	string move[]={"D","L","R","U"};
	return move[direction];
}

void printPathUtil(int m[MAX][MAX], bool visited[MAX][MAX],int n , int i, int j,vector<string> &ans){
	visited[i][j]=true;
	if(i == n-1 && j == n-1){
		ans.push_back(path);
	}
	else
	{
		for(int k=0;k<4;k++){
			int newX=i+moveX[k];
			int newY=j+moveY[k];
			if(isValid(newX,newY,n) && m[newX][newY]==1 && !visited[newX][newY]){
				path.append(typeOfMovement(k));
				printPathUtil(m,visited,n,newX,newY,ans);
				path.pop_back();
			}
		}
	}
	visited[i][j]=false;
}

// Where m is the given matrix of 0 and 1. 1 represent open cell. 0 represent block cell
vector<string> printPath(int m[MAX][MAX], int n)
{
	vector<string> ans;
	bool visited[MAX][MAX];
	path="";
	memset(visited,false,sizeof(visited));
	printPathUtil(m,visited,n,0,0,ans);
	return ans;
}
