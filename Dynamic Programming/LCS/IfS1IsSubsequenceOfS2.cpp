 bool isSubSequence(string A, string B) 
{
    int n = A.size(), m = B.size(), index =0;
    int count= 0;
    for(int i=0;i<m;i++){
        if(A[index]==B[i]){
            count++;
            index++;
        }
    }
    return count==n;
}