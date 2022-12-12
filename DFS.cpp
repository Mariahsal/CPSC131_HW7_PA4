/**
 * PROBLEM 1: Longestincreasing path in a matrix
 * MARIAH SALGADO
 * WILLIAM LUA
 **/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int h = matrix.size(), w = (h ? matrix[0].size():0);
        vector<vector<int>> dp(h, vector<int> (w, 0));
        int maxlen = 0;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                maxlen = max(maxlen, dfsSearch(matrix, dp, INT_MIN, i, j));
        return maxlen;
    }
    int dfsSearch(vector<vector<int>> &mat, vector<vector<int>> &dp, int prev, int i, int j) {
        int h = mat.size(), w = mat[0].size();
        if (prev >= mat[i][j]) return 0;
        if (dp[i][j])  return dp[i][j];
        
        int val = mat[i][j];
        int d[4] = {
            i ? dfsSearch(mat, dp, val, i-1, j):0,
            i+1 < h ? dfsSearch(mat, dp, val, i+1, j):0,
            j ? dfsSearch(mat, dp, val, i, j-1):0,
            j+1 < w ? dfsSearch(mat, dp, val, i, j+1):0
        };
        return dp[i][j] = max(d[0], max(d[1], max(d[2], d[3]))) + 1;
    }
};
