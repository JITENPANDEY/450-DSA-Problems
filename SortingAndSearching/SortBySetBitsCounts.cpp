static int countsetBits(int n){
    int count = 0;
    while (n) {
        n &= (n - 1); // its always release a set bit
        count++;
    }
    return count;
}
static bool compSetBits(int n1, int n2)
{
    return countsetBits(n1)>countsetBits(n2);
}
void sortBySetBitCount(int arr[], int n)
{
    stable_sort(arr, arr+n, compSetBits);
}