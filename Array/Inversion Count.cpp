#define ll long long int
    ll merge(ll arr[],ll temp[], ll low, ll mid, ll high)
    {
        ll i=low, j=mid+1, k=low;
        ll count=0;
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
            else
            {
                temp[k++]= arr[j++];
                count+= mid - i + 1;
    	     // there are mid - i elements that form an inversion
    	}
        }
       
        while(i<=mid)
        temp[k++]= arr[i++];
        
        
        for(ll i=low;i<=high;i++)
        arr[i]=temp[i];
        
        return count;
    }
    ll mergesort(ll arr[],ll temp[],ll low,ll high){
        ll count =0;
        if(low<high)
        {
        	
            ll mid = (low +high)/2;
            
            count+= mergesort(arr,temp,low,mid);
            count+=mergesort(arr,temp,mid+1,high);
            count+=merge(arr,temp,low,mid,high);
        }
        
        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        ll temp[N+1];
        for (ll i = 0; i < N; i++)
            temp[i] = arr[i];
            
        return mergesort(arr,temp,0, N-1);
    }