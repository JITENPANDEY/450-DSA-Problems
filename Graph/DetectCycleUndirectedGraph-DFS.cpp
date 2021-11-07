#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

bool dfsCycleCheck(int s, vector<int> g[],vector<bool> &v, int parent)
{
  v[s]=true;
  for(auto i : g[s])
  {
    if(!v[i]){
        if(dfsCycleCheck(i,g,v,s))
        return true;
    }
    else if(v[i] && i!=parent)
        return true;
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