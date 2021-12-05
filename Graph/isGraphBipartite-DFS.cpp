#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
/*
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
*/
bool isGraphBipartite(int i, vector<int>adj[], vector<int> &color, int c)
    {
        color[i] = c;
    
        for (auto neighbour : adj[i])
        {
            if (color[neighbour]==-1)
            {
                if (isGraphBipartite(neighbour, adj, color, not c) == false)
                  return false;
            }
            else if(color[i] == color[neighbour]){
              return false;
            }
        }
        return true;
    }
bool isBipartite(int V, vector<int>adj[]){
  // Code here
  vector<int>color(V, -1);
  for(int i=0;i<V;i++){
      if(color[i]==-1 && isGraphBipartite(i, adj, color, 1)==false)
          return false;
  }
  return true;
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
  cout<<isBipartite(n,g);
	return 0;
}
