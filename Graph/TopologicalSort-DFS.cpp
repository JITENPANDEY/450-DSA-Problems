#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
stack<int>s;
//Function to return list containing vertices in Topological order.
void dfs(int source, vector<bool>&visited, vector<int>adj[]){
    visited[source]=true;
    for( auto i : adj[source]){
        if(!visited[i]){
            dfs(i, visited, adj);
        }
    }
    s.push(source);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    vector<int>ans;
    vector<bool>visited(V,false);
    for(int i =0; i<V;i++){
        if(!visited[i]){
            dfs(i, visited, adj);
        }
    }
    while(!s.empty()){
        //cout<<s.top()<<endl;
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
    
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
  vector<int> ans = topoSort(n, g);
  for(auto i : ans) cout<<i<<" ";
	return 0;
}
