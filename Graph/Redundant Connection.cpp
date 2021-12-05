class DSU{
private:
    vector<int>parent, rank;
public:
    DSU(int n) : parent(n), rank(n, 0){
        for(int i=0;i<n;i++){
            parent[i] =i;
        }
    }
    
    // find by path compression
    int find(int x){
        if(parent[x]==x)
            return x;
        int temp = find(parent[x]);
        parent[x] = temp;
        return temp;
    }
    //union by rank
    bool unionn(int x, int y){
        int LX = find(x);
        int LY = find(y);
        if(LX==LY) 
            return false;
        if(rank[LX] > rank[LY])
            parent[LY] = LX;
        else if(rank[LX]<rank[LY])
            parent[LX] = LY;
        else{
            parent[LX] = LY;
            rank[LX]++;
        }
        return true;
    }
    
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size()+1);
        for(auto &edge : edges){
            int x = edge[0], y= edge[1];
            if(!dsu.unionn(x,y)) return edge;    
        }
        return {};
    }
};