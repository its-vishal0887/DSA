class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<int>& arr, int curr, int prev) {
        if (curr >= arr.size()) {
            return 0;
        }
        if(dp[prev+1][curr] != -1) return dp[prev+1][curr];

        int inclu = 0;
        if (prev == -1 || arr[curr] > arr[prev]) {
            inclu = 1 + solve(dp, arr, curr + 1, curr);
        }
        int exclu = 0 + solve(dp,arr, curr + 1, prev);
        int ans = max(inclu, exclu);
        dp[prev+1][curr] = ans;
        return dp[prev+1][curr];
    }
    int lengthOfLIS(vector<int>& nums){
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size(), -1));
        return solve(dp,nums, 0,-1); 
    }
};