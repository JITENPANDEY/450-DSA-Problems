bool isPossible(vector<int>& dist,int mid, double hour){
    double totalTime = 0;
    for(int i=0;i<dist.size()-1;i++){
        totalTime+=ceil((double)dist[i]/(double)mid);
    }
    totalTime+=(double)dist[dist.size()-1]/(double)mid;
    return totalTime<=hour;
}
int minSpeedOnTime(vector<int>& dist, double hour) {
    int low = 1, high = 1e7;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(isPossible(dist, mid, hour)){
            ans = mid;
            high = mid -1;
        }else{
            low = mid+1;
        }
    }
    return ans;
    
}