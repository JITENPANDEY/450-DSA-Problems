#include<bits/stdc++.h>
using namespace std;
string FirstNonRepeating(string A){
  // Code here
  string ans="";
  unordered_map<char, int> mp;
  queue<char> q;
  for(int i=0;i<A.length();i++){
      mp[A[i]]++;
      
      if(mp[A[i]]==1)
          q.push(A[i]);
          
      while(!q.empty() && mp[q.front()]>1){
              q.pop();
      }
      
      if(!q.empty()) ans+=q.front();
      else ans+='#';
  }
  return ans;
}
int main(){
  
}
AQIZQAZPN