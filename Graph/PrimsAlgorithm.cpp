#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
struct comp{
    bool operator()(vector<ll>&a, vector<ll> &b){
        return a[2]>b[2];
    }
};

void primsAlgorithm(vector<pair<ll,ll>> g[], int n){
    ll totalCost = 0;
    priority_queue<vector<ll>, vector<vector<ll>>, comp> pq;
    vector<bool>visited(n, false);
    pq.push({-1, 0, 0});  //{acuring vetex, current vetex, weight}
    while(!pq.empty()){
        auto rem = pq.top();
        pq.pop();
        if(visited[rem[1]]) 
        continue;
        
        visited[rem[1]]=true;
        if(rem[0]!=-1){
            cout<<rem[0]<<"-->"<<rem[1]<<" = "<<rem[2]<<endl;
            totalCost+=rem[2];
        }
        for(auto neighbor : g[rem[1]]){
            if(!visited[neighbor.first]){
                pq.push({rem[1], neighbor.first, neighbor.second});
            }
        }
    }
    cout<<"totalCost = "<<totalCost<<endl;
    
}
int main() {
    // your code goes here
    ll n,e;
    cin>>n>>e;
    ll a,b, wt;
    vector<bool> v(n, false);
    vector<pair<ll,ll>> g[n];
    
    for(ll i=0;i<e;i++)
    {
        cin>>a>>b>>wt;
        g[a].pb({b, wt});
    //for undirected graph
        g[b].pb({a, wt});
    }
    primsAlgorithm(g, n);
    return 0;
}
