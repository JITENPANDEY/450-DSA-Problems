#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

bool check(int s,vector<int>adj[],vector<int>&visited){
  queue<pair<int,int>>q;
  visited[s]=1;
  q.push({s,-1});
  while(!q.empty()){
      int node=q.front().first;
      int parent=q.front().second;
      q.pop();
      for(auto it:adj[node]){
          if(!visited[it]){
              visited[it]=1;
              q.push({it,node});
          }
          else if(parent!=it)
              return true;
      }
  }
  return false;
}
int main() {
	// your code goes here
	ll n,e;
	cin>>n>>e;
	ll a,b;
	vector<bool> v(n, false);
	vector<vector<ll>> g(n,vector<ll>());
	
	for(ll i=0;i<e;i++)
	{
		cin>>a>>b;
		g[a].pb(b);
    //for undirected graph
	  g[b].pb(a);
	}
  bool isCycle = false;
	for(ll i=0;i<n;i++) {
		if(!v[i])
		  if(dfs(i,g,v,-1)){
        isCycle = true;
        break;
      }      	
	}
  cout<<isCycle<<endl;
	return 0;
}