int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> s(wordList.begin(), wordList.end());
    if(s.find(endWord)==s.end()) return 0;
    
    queue<string>q;
    q.push(beginWord);
    int ans = 0;
    while (!q.empty()) {
                    
        ans++;
        int size =q.size();
        while(size--){
            string curr = q.front();
            q.pop();

            for(int i=0;i<curr.length();i++){
                string temp = curr;
                for(char ch = 'a';ch<='z';ch++){
                    temp[i] = ch;
                    if(curr.compare(temp)==0) continue; // no need to check for the same string
                    if(temp.compare(endWord)==0)
                        return ans+1;
                    if(s.find(temp)!=s.end()){
                        q.push(temp);
                        s.erase(temp);
                    }
                }
            }
            
        }
    }
    return 0;
}