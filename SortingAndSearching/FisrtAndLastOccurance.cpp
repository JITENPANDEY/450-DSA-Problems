int firstGreaterEqual(int A[], int n, int target) {
	int low = 0, high = n;
	while (low < high) {
		int mid = low + ((high - low) >> 1);
		//low <= mid < high
		if (A[mid] < target) {
			low = mid + 1;
		} else {
			//should not be mid-1 when A[mid]==target.
			//could be mid even if A[mid]>target because mid<high.
			high = mid;
		}
	}
	return low;
}
vector<int> find(int arr[], int n , int x )
{
    int start = firstGreaterEqual(arr, n, x);
	if (start == n || arr[start] != x) {
		return {-1, -1};
	}
	return {start, firstGreaterEqual(arr,n,  x + 1) - 1};
}