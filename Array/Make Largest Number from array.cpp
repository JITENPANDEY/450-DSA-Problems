string largestNumber(vector<int>& nums) {
    string ans ="";
    vector<string> s;
    for(int i : nums){
        s.push_back(to_string(i));
    }
    sort(s.begin(), s.end(),[](string &s1, string &s2){ return s1+s2>s2+s1; } );
    
    for(auto i : s) ans+=i;
    while(ans[0]=='0' && ans.size()>1) ans.erase(0,1); //erase(idx, len)
    
    return ans;
}