bool findPair(int arr[], int size, int n){
    //code
    sort(arr, arr+size);
    // for(int i=0;i<size;i++){
    //     int index = upper_bound(arr+i+1, arr+size, n+arr[i]) - arr - 1;// return the last occurance ondex
    //     if(arr[index]-arr[i]==n){
    //         return 1;
    //     }
    // }
        int i = 0, j = 1;
   
       while(i < size && j < size)
       {
           if(arr[j] - arr[i] == n) return true;
           else if(arr[j] - arr[i] < n) j++; 
           else i++;
       }
    return 0;
} 