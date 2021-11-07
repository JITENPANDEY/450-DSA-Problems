vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    
  vector<int>dist(V, INT_MAX);
  queue<int>  q;
  
  dist[S] = 0;
  q.push(S); 

  while(q.empty()==false) 
  { 
    int node = q.front(); 
    q.pop();
      
    for(vector<int> neighbour :adj[node]){
        if(dist[node] + neighbour[1] < dist[neighbour[0]]){
            dist[neighbour[0]]=dist[node]+neighbour[1];
            q.push(neighbour[0]);
        }
    } 
  }
  return dist;
}