/**
 * PROBLEM 1: Longest increasing path in a matrix
 * MARIAH SALGADO
 * WILLIAM LUA
 **/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // h represents how many rows in the matrix (HEIGHT)
        // w is the number of columns (WIDTH). The width is 0 if we are given an empty matrix
        int h = matrix.size(), w = (h ? matrix[0].size():0);
        vector<vector<int>> dp(h, vector<int> (w, 0));// Make a new matrix of 0's called dp with same dimensions as our input
        int maxlen = 0;
        // Looping through the entire matrix
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                maxlen = max(maxlen, dfsSearch(matrix, dp, INT_MIN, i, j));// Finding the maxlen by calling dfsSearch on every element of matrix
        return maxlen; //Return final answer
    }
    int dfsSearch(vector<vector<int>> &mat, vector<vector<int>> &dp, int prev, int i, int j) {
        int h = mat.size(), w = mat[0].size();// Getting height and width
        // If the value of our PREVIOUS step is BIGGER, then return 0
        // This is because we always want our CURRENT value (At index i, j) to be greater than previous
        if (prev >= mat[i][j]) return 0;
        // if dp at index i,j is non-zero, return that number
        if (dp[i][j])  return dp[i][j];
        
        int val = mat[i][j];
        int d[4] = {
            i ? dfsSearch(mat, dp, val, i-1, j):0, // Looking UP 1 cell above as our starting point for dfsSearch() Recursive call
            i+1 < h ? dfsSearch(mat, dp, val, i+1, j):0, // Looking DOWN 1 cell below as our starting point for dfsSearch() Recursive call
            j ? dfsSearch(mat, dp, val, i, j-1):0,// Looking LEFT 1 cell next to us as our starting point for dfsSearch() Recursive call
            j+1 < w ? dfsSearch(mat, dp, val, i, j+1):0 // Looking RIGHT 1 cell next to us as our starting point for dfsSearch() Recursive call
        };
        // Comparing all recurisve calls from UP, DOWN, LEFT, RIGHT and taking the max of all 4 of those values
        // Take the max and assign it to dp at index i, j
        return dp[i][j] = max(d[0], max(d[1], max(d[2], d[3]))) + 1;
    }
};
