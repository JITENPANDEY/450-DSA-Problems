int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> edge_freq;
        int max_freq = 0;
        for(int i=0;i<wall.size();i++){ // row
            int edge_pos =0;
            for(int j=0;j<wall[i].size()-1;j++){ // col
                
                edge_pos = edge_pos+wall[i][j]; // current edge position
                edge_freq[edge_pos]++; //update the freq of the edge position
                max_freq = max(max_freq, edge_freq[edge_pos]);
                
            }
        }
        return wall.size() - max_freq;
    }

    //explanation : https://leetcode.com/problems/brick-wall/discuss/888577/IntuitionC%2B%2BWith-PicturesHashMapDetailed-ExplanationCommentsSolutionCode