bool isPossible(int A[], int N, int mid, int M){
    int student = 1;
    int currSum = 0;
    for(int i=0;i<N;i++){
        currSum += A[i];
        if(currSum>mid){
            student++;
            currSum = A[i];
        }
    }
    return student<=M;
}
int findPages(int A[], int N, int M) 
{
    int sum =0;
    int mx=0;
    for(int i=0;i<N;i++){
        sum+=A[i];
        mx=max(mx,A[i]);
    }
    int low = mx , high=sum;
    int ans=-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(isPossible(A, N, mid, M)){
            ans = mid;
            high = mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

//similar problem 
Leetcode : 410. Split Array Largest Sum