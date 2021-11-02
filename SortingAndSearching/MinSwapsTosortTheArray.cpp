int minSwaps(vector<int>&nums)
	{
	    int n =nums.size();
	    vector<pair<int,int>>dummy;
	    for(int i=0;i<n;i++)
	        dummy.push_back({nums[i], i});
	        
	   sort(dummy.begin(), dummy.end());
	   vector<int>visited(n, false);
	    int ans =0;
	    for(int i=0;i<n;i++){
	        //if already visited or placed already in correct index then do nothing
	        if(visited[i] || i==dummy[i].second)
	            continue;
	       
	       int cycleLen = 0;
	       int j=i; // j will start from i and move to the next point to make cycle
	       while(visited[j]==false){
	           visited[j]=true;
	           cycleLen++;
	           j = dummy[j].second;
	       }
	       ans+=(cycleLen-1);
	    }
	    return ans;

	}