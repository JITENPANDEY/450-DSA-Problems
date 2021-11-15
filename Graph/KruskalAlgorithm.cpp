#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int find(int x, vector<int> &parent){
    if(parent[x]==x)
        return x;
    int temp = find(parent[x], parent);
    parent[x]=temp;
    return temp;
}
void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = find(u, parent);
    v = find(v, parent);
    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u; 
    }
    else {
        parent[v] = u;
        rank[u]++; 
    }
}
int main(){
    int N,m;
    cin >> N >> m;
    vector<node> edges; 
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        edges.push_back(node(u, v, wt)); 
    }
    sort(edges.begin(), edges.end(), comp); 
    
    vector<int> parent(N);
    for(int i = 0;i<N;i++) 
        parent[i] = i; 
    vector<int> rank(N, 0); 
    
    int cost = 0;
    vector<pair<int,int>> mst; 
    for(auto it : edges) {
        if(find(it.v, parent) != find(it.u, parent)) {
            cost += it.wt; 
            mst.push_back({it.u, it.v}); 
            unionn(it.u, it.v, parent, rank); 
        }
    }
    cout << cost << endl;
    for(auto it : mst) cout << it.first << " - " << it.second << endl; 
    return 0;
}