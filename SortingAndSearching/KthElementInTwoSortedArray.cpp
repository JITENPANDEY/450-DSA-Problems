int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if(n>m)
        return kthElement(arr2, arr1, m, n, k);
    
    int low = max(0, k-m), high = min(k, n);
    
    // when K<max(m,n)
    // 1 2 3 4         k=3
    // 5 6 7 8 9       low=0, high=3;
    
    // when K>max(m,n)
    // 1 2 3 4         k=7
    // 5 6 7 8 9       low=0, high=4; firstArray.len
    
    while(low<=high){
        int mid1 = (low+high)/2;
        int mid2 = k-mid1;
        
        int l1 = mid1==0?INT_MIN: arr1[mid1-1];
        int l2 = mid2==0?INT_MIN: arr2[mid2-1];
        int r1 = mid1==n?INT_MAX: arr1[mid1];
        int r2 = mid2==m?INT_MAX: arr2[mid2];
        
        //valid case
        if(l1<=r2 && l2<=r1)
            return max(l1, l2);
        else if(l1>r2)
            high = mid1-1;
        else 
            low = mid1 + 1;
    }
    return -1;
    
}