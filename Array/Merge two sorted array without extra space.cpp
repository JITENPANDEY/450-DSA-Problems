int findgap(int gap)
{
    if(gap<=1)
    return 0;
    return (gap / 2) + (gap % 2);;
}
void merge(int ar1[], int ar2[], int m, int n) {
    int gap=n+m;
    int i,j;
    while(gap>0){
        for(i=0;i+gap<m;i++)
        {
            if(ar1[i]>ar1[i+gap])
            swap(ar1[i],ar1[i+gap]);
        }
        
        for(j=gap>m?gap-m:0;i<m&&j<n;i++,j++)
        {
            if(ar1[i]>ar2[j])
            swap(ar1[i],ar2[j]);
        }
        if(j<n){
            for (j = 0; j + gap < n; j++){
                if (ar2[j] > ar2[j + gap])
                  swap(ar2[j], ar2[j + gap]);
            }
              
        }
        
        gap = findgap(gap);
    }
}