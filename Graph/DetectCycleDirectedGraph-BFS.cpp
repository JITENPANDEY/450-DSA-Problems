#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
queue<int>q;
bool topoSort(int V, vector<int> adj[]) 
{
    // code here
    int count =0;
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for( auto s : adj[i])
            indegree[s]++;
    }
      for(int i=0;i<V;i++){
          if(indegree[i]==0)
          q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        count++;
        q.pop();
        for(int i: adj[node]){
            indegree[i]--;
            if(indegree[i]==0)
            q.push(i);
        }
    }
    return count!=V;
    
}
int main() {
	// your code goes here
	int n,e;
	cin>>n>>e;
	int a,b;
  vector<bool> DFSvisited(n, false);
	vector<int> g[n];
	
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		g[a].pb(b);
    //for undirected graph
	  //g[b].pb(a);
	}
  bool iscycle = topoSort(n, g);
	return 0;
}
