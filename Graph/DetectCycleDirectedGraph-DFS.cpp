#include <bits/stdc++.h>
using namespace std;
#define pb push_back

bool dfsCycleCheck(int s, vector<int> g[],vector<bool> &visited, vector<bool> &DFSvisited)
{
  visited[s]=true;
  DFSvisited[s]=true;
  for(auto i : g[s])
  {
    if(!visited[i]){
      if(dfsCycleCheck(i,g,visited,DFSvisited))
        return true;
    }
    else if(DFSvisited[i]==true)
        return true;
  }
  DFSvisited[s]=false;
  return false;
}
int main() {
	// your code goes here
	int n,e;
	cin>>n>>e;
	int a,b;
	vector<bool> visited(n, false);
    vector<bool> DFSvisited(n, false);
	vector<int> g[n];
	
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		g[a].pb(b);
    //for undirected graph
	  //g[b].pb(a);
	}
  bool isCycle = false;
	for(int i=0;i<n;i++) {
		if(!visited[i])
		  if(dfsCycleCheck(i, g, visited, DFSvisited)){
        isCycle = true;
        break;
      }      	
	}
  cout<<isCycle<<endl;
	return 0;
}