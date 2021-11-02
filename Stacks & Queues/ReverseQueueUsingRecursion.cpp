#include<bits/stdc++.h>
using namespace std;
int main(){
  
}
void reverse(queue<int> & q){
    if(q.empty()){
        return;
    }
    int x = q.front();
    q.pop();
    
    reverse(q);
    
    q.push(x);
}
queue<int> rev(queue<int> q)
{
    // add code here.
    reverse(q);
    return q;
    
}