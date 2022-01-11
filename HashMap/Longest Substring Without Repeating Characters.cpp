int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int ans=0, left=0, right=0, n=s.size();
        
        while(right<n){
            char c= s[right];
            if(set.find(c)==set.end()){ // if character is valid then Inc the freq and store the ans and move the right pointer
                ans = max(ans, right-left+1);
                set.insert(c);
            }else{ //character is not valid
                while(s[left]!=c){
                    set.erase(s[left++]);
                }
                left++;
            }
            
            right++;
           
        }
        return ans;
    }