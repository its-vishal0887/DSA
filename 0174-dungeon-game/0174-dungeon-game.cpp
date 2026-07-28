class Solution {
public:
    int solve(vector<vector<int>>&arr, int sr, int sc, int er, int ec, vector<vector<int>>&dp){
        if(sc > ec || sr > er) return 1e9;
        if(sc == ec && sr == er) {
            return max(1, 1-arr[sr][sc]);
        }
        if(dp[sr][sc] != -1) return dp[sr][sc];
        int right = solve(arr, sr, sc+1, er, ec, dp);
        int down = solve(arr, sr+1, sc, er, ec,dp);
        int need = min(right, down)- arr[sr][sc];
        dp[sr][sc] =  max(1, need);
        return dp[sr][sc];
    }
    int calculateMinimumHP(vector<vector<int>>& arr) {
        vector<vector<int>>dp(arr.size(), vector<int>(arr[0].size(), -1));
        return solve(arr, 0,0,arr.size()-1, arr[0].size()-1, dp);
    }
};