
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

int parent[100000];
int rankk[100000]={0};
void makeSet(){
    for(int i=0;i<=1000;i++){
        parent[i]=i;
    }
}
int find(int x){
    if(parent[x]==x)
        return x;
    int temp = find(parent[x]);
    parent[x]=temp;
    return temp;
}
void unionn(int x, int y){
    int parentX = find(x);
    int parentY = find(y);
    
    if(rankk[x]>rankk[y])
        parent[y]=x;
    else if(rankk[x]<rankk[y])
        parent[x]=y;
    else{
        parent[y]=x;
        rankk[x]++;
    }
        
}
int main() {
    // your code goes here

    makeSet();
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        unionn(a,b);
    }
    cout<<find(8);
   
}
