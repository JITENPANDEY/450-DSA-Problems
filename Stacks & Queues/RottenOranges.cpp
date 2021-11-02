#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
  // Code here
  queue<pair<int, int>>q;
  int m = grid.size();
  int n = grid[0].size();
  vector<vector<int>>dir = {{-1,0},{0,1},{1,0},{0,-1}};
  
  int fresh=0, ans = -1;
  for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
          if(grid[i][j]==2) q.push({i,j});
          else if(grid[i][j]==1) fresh++;
      }
  }
  
  while(!q.empty()){
      int size = q.size();
      while(size--){
          int i = q.front().first;
          int j = q.front().second;
          q.pop();
          
          for(auto d : dir){
              int x = i+d[0], y=j+d[1];
              if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1){
                  grid[x][y]=2;
                  fresh--;
                  q.push({x,y});
              }
          }
      }
      ans++;
  }
  if(fresh>0)
  return -1;
  
  if(ans==-1)
  return 0;
  
  return ans;
}

int main(){
  
}