class Solution {
public:
    int solve(vector<vector<int>>&arr, int sr, int sc, int er, int ec, vector<vector<int>>&dp){
        if(sr == er && sc == ec) return arr[sr][sc];
        if(sr > er || sc > ec) return 1e9;
        if(dp[sr][sc] != -1) return dp[sr][sc];
        int left = arr[sr][sc] + solve(arr, sr, sc+1, er, ec, dp);
        int right = arr[sr][sc] + solve(arr, sr+1, sc, er, ec, dp);
        dp[sr][sc] =  min(left, right);
        return dp[sr][sc];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(grid, 0,0,grid.size()-1, grid[0].size()-1,dp);
    }
};