int kthSmallest(int arr[], int l, int r, int k) {
    //O(k) space
    priority_queue<int>maxHeap;
    for(int i=0;i<=r;i++)
    {
        maxHeap.push(arr[i]);
        if(maxHeap.size()>k)
        maxHeap.pop();
    }
    return maxHeap.top();
    
    
}