class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<vector<int>>& arr, int sr, int sc, int er, int ec) {
        if ((sr > er || sc > ec))
            return 0;
        if (sr == er && sc == ec)
            return 1;
        if (arr[sr][sc] == 1)
            return 0;
        if(dp[sr][sc] != -1) return dp[sr][sc];
        
        dp[sr][sc] =  solve(dp, arr, sr, sc + 1, er, ec) + solve(dp,arr, sr + 1, sc, er, ec);
        return dp[sr][sc];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        if(arr[arr.size()-1][arr[0].size()-1] == 1) return 0;
        vector<vector<int>>dp(arr.size(), vector<int>(arr[0].size(), -1));
        return solve(dp,arr, 0, 0, arr.size() - 1, arr[0].size() - 1);
    }
};