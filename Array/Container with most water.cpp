long long maxArea(long long height[], int len)
{
    // Your code goes here
    long long i=0, j=len-1;
    long long ans = 0;
    while(i<j){
        long long w = j-i;
        long long h = min(height[i], height[j]);
        
        ans = max(ans, w*h);
        
        if(height[i]<height[j]) i++;
        else j--;
    }
    return ans;
}