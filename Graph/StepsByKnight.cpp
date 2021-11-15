bool isSafe(int n, int col, int row) {
    if (col < 0 || col >= n || row < 0 || row >= n) return false;
    return true;
}
//Function to find out minimum steps Knight needs to reach target position.
int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
  vector<vector<int>>dirs = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
  vector<vector<int>>grid(N+1, vector<int>(N+1, 0));
  queue<pair<int,int>>q;
    q.push({KnightPos[0]-1,KnightPos[1]-1});
    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        if (a == TargetPos[0]-1 && b == TargetPos[1]-1) 
            break;
        q.pop();
        for (int i=0; i<8; ++i) {
            int newX = a + dirs[i][0];
            int newY = b + dirs[i][1];
            if (isSafe(N, newX, newY) && grid[newX][newY] == 0) {
                q.push({newX, newY});
                grid[newX][newY] = grid[a][b] + 1;
            }
        }
    }
    return grid[TargetPos[0]-1][TargetPos[1]-1];
}