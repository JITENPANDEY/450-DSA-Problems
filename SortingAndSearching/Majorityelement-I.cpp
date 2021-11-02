int majorityElement(int a[], int n)
    {
        int candidate =a[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(count==0){
                count++;
                candidate=a[i];
            }
            else if(candidate==a[i]){
                count++;
            }
            else
                count--;
        }
        count=0;
        for(int i=0;i<n;i++)
            if(a[i]==candidate)
                count++;
        if(count>n/2)
            return candidate;
        return -1;
        
        // your code here
        
    }