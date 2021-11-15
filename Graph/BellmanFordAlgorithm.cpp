int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    //
	    vector<int>dist(n,INT_MAX);
	    dist[0]=0;
	    
	    for(int i=0;i<n-1;i++){
	        //relaxation for n-1 times
	       // if(u,v) is an edge then 
	       // if(dist[u]+cost[u->v]<dist[v]) 
	       // then dist[v] = dist[u]+cost[u->v];
	       for( auto edge : edges){
	           if(dist[edge[0]]==INT_MAX) 
	            continue;
	           if(dist[edge[0]]+edge[2]<dist[edge[1]])
	            dist[edge[1]] = dist[edge[0]]+edge[2];
	           
	       }
	    }
	    for(auto i : dist)
	    cout<<i<<" "<<endl;
	    
	    for(auto edge : edges){
           if(dist[edge[0]]+edge[2]<dist[edge[1]]){
               return true;
           }
       }
       return false;
       
    //   Time complexity : O(N^2)
    //   if graph is comple there will be N*(N-1)/2 edges hence worst time complexity is O(N^3)
	    
	}