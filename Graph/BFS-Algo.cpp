#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
void bfs(ll s, vector<vector<ll>> g,vector<bool> &v)
{
	int i;
	queue<int> queue;
	
	v[s]=true;
	queue.push(s);
	
	while(!queue.empty())
	{
		s=queue.front();
		cout<<s<<" ";
		queue.pop();

    for(auto i : g[s])
    {
      if(!v[i]){
        queue.push(i);
        v[i]=true;
      }
      
    }
	}
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
	  //g[b].pb(a);
	}
	for(ll i=0;i<n;i++) {
		if(!v[i])
		  bfs(i,g,v);	
	}
	return 0;
}