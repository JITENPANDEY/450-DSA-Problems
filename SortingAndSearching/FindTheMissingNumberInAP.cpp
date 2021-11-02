int findMissingUtil(int arr[], int low, int high, int diff)
{   
    // Find index of middle element
    int mid;
    while (low <= high)
    {   
        mid = (low + high) / 2;
        if ((arr[mid] - arr[0]) / diff == mid)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return arr[high] + diff; 
    //2 4 8 10 12 14
    //  h l---------------> ans = arr[high]+diff || arr[low]-diff; ans = 6
    // there will be a time when high crosses low
}
int findMissing(int arr[], int n) {
    return findMissingUtil(arr, 0, n-1, (arr[n-1]-arr[0])/n);
}