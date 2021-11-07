#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
queue<int>q;
bool checkBFS(int s, vector<int> adj[], vector<int>&color){
  q.push(s);
  color[s]=1;
  while(!q.empty()){
      int node = q.front();
      q.pop();
      
      for(auto i : adj[node]){
          if(color[i]==-1){
              color[i] = 1 - color[node];
              q.push(i);
              
          }else if(color[i]==color[node]){
              return false;
          }
      }
  }
  return true;
}
bool isBipartite(int V, vector<int>adj[]){
  // Code here
  vector<int>color(V, -1);
  for(int i=0;i<V;i++){
      if(color[i]==-1 && checkBFS(i, adj, color)==false)
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
