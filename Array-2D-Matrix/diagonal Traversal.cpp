 vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n=mat[0].size();
        if(n==0 && m==0) return {};
        int row =0, col=0;
        vector<int>ans;
        for(int k=0;k<m*n;k++){
            ans.push_back(mat[row][col]);
            if ((row + col) % 2 == 0) {
                // The direction is always up when the sum of row & col is even

                // For last column, go down
                if (col == n-1) { row++; }                

                // For first row & non-last columns, go right
                else if (row == 0) { col++; }

                // For not first row & non-last columns, go up and to the right
                else { row--; col++; }

            } else {
                // The direction is always down when the sum of row & col is odd

                // For last row, go right
                if (row == m-1) { col++; } 

                //  For non-last row & first column, go down
                else if (col == 0) { row++; }

                // For non-last row & non-first column, go down and to the left
                else { row++; col--; }
            }
        }
        return ans;
    }