int dp[51][51][51] ={0};
    int cherryPickupHelper(int r1, int c1, int r2, vector<vector<int>>& grid, int n){
        
        int c2 = r1 + c1 - r2;
        
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1] ==-1 || grid[r2][c2] ==-1)
            return INT_MIN;
        // if person 1 reached the bottom right, return what's in there (could be 1 or 0)
        if(r1 == n - 1 && c1 == n - 1)
          return grid[r1][c1];

        // if person 2 reached the bottom right, return what's in there (could be 1 or 0)
        if(r2 == n - 1 && c2 == n - 1)
          return grid[r2][c2];
        
        if(dp[r1][c1][r2]!=0)
            return dp[r1][c1][r2];

        int cherries = 0;
        if(r1 == r2 && c1==c2)
            cherries +=grid[r1][c1];
        else
            cherries +=grid[r1][c1] + grid[r2][c2];
        
        int f1 = cherryPickupHelper(r1,c1+1,r2,grid,n); // h, h
        int f2 = cherryPickupHelper(r1+1,c1,r2,grid,n); // v, h
        int f3 = cherryPickupHelper(r1,c1+1,r2+1,grid,n); // h, v
        int f4 = cherryPickupHelper(r1+1,c1,r2+1,grid,n); // v ,v
        
        cherries+=max({f1, f2, f3, f4});
        return dp[r1][c1][r2]=cherries;
        
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        return max( 0, cherryPickupHelper(0,0,0,grid, grid.size()));
        
    }