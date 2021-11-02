#include <bits/stdc++.h>
using namespace std;

bool ispar(string x)
{
    // Your code here
    stack<char>s;
    for(auto c : x){
        if (c == '(')
      s.push(')');
    else if (c == '{')
      s.push('}');
    else if (c == '[')
      s.push(']');
    else if (s.empty() || s.top() != c)
      return false;
  else
      s.pop();
    }
    return s.empty();
}
int main(){
  string s = "{{}}([])";
  cout<<ispar(s);
}