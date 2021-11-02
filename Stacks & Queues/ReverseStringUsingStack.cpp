#include <bits/stdc++.h>
using namespace std;

char* reverse(char *S, int len)
{  
  char *ans;
  ans=new char[len];
  stack<char>s;
  for(int i=0;S[i];i++)
  {
      s.push(S[i]);
  }
  int j=0;
  while(s.empty()!=true)
  {
      ans[j++]=s.top();
      s.pop();
  }
  return ans;
}