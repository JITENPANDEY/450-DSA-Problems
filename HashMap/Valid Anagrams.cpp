bool isAnagram(string s, string t) {
    int n1 =s.size();
    int n2 = t.size();
    
    if(n1!=n2) return false;
    vector<int> vis(256, 0);
    for(int i=0;i<n1;i++){
        vis[s[i]-'a']++;
        vis[t[i]-'a']--;
    }
        for(int i=0;i<256;i++){
        if(vis[i]!=0)return false;
    }
    return true;
}