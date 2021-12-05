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

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
  vector<int>dist(V, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> >  q; // dist, from
  
  dist[S] = 0;
  q.push({0,S}); 

  while(q.empty()==false) 
  { 
    int node = q.top().second;
    int dis = q.top().first;
    q.pop();
    
    for(auto &neighbour :adj[node]){
        int nextNode = neighbour[0];
        int nextDist = neighbour[1];
        if(dist[node] + nextDist < dist[nextNode]){
            dist[nextNode]=dist[node]+nextDist;
            q.push({dist[nextNode],nextNode});
        }
    } 
  }
  return dist;
		
}