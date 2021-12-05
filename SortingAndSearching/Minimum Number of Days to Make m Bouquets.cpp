bool isPossible(vector<int>& bloomDay, int m, int k, int mid){
    int bouquet = 0, flower =0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]>mid) flower=0;
        else{
            flower++;
            if(flower>=k){
                bouquet++;
                flower = 0;
            }
        }
    }
    return bouquet>=m;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    int left = 1, right = 1e9;
    int ans =0;
    if(m*k>bloomDay.size()) return -1;
    
    while(left<=right){
        int mid = (left+right)/2;
        if(isPossible(bloomDay, m, k, mid)){
            ans = mid;
            right = mid-1;
        }
        else{
            left = mid+1;
        }
            
    }
    return ans;
}
/*
to make M bouq.. M*K >=number of flowers (size of array)

At a particluar day I will count how many flower I can get and I will try to make the bouq.. and in every bouq I will have K adjacent flower.

so if day1 = 1 and last day = 1e7

if we find the result in **mid** day if Its satisfy the condistions then I will dec my high value else inc the low val;