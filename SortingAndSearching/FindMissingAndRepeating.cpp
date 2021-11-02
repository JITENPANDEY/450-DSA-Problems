    int *findTwoElement(int *arr, int n) {
        // code here
        int i=0;
        while(i<n){
            int correctIndex = arr[i]-1;
            if(arr[i]!=arr[correctIndex]){
                swap(arr[i], arr[correctIndex]);
            }
            else
                i++;
        }
        int* ans = new int(n);
        for(int i=0;i<n;i++){
            if(i+1!=arr[i]){
                ans[0]=arr[i];
                ans[1]=i+1;
                break;
            }
        }
        return ans;
    }
};