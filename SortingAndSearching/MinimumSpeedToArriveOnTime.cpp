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
/*
We know T(time) =  D (dist)/ S(Speed)   lets required time X
1. what should be the minimum time we can take?
		- ans = 1
		1 3 2   required time X =2.7Hours
		calculate total T when S is 1
		1/1 + 3/1 + 2/2 = 6 >2.7Hours
		so we need to find the next posible time
		1/2 + 3/2 + 2/2 = 3.5 >2.7Hours
		so we need to find the next posible time
		1/3 + 3/3 + 2/3 = 2.677=2.7Hours so the required speed would be
*/