class Solution {
public:
    int solve(vector<int>& arr, int i, vector<int>&dp) {
        if (i >= arr.size()) {
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int left = arr[i] + solve(arr, i + 2, dp);
        int right = 0 + solve(arr, i + 1, dp);
        dp[i] = max(left, right);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int i = 0;
        vector<int>dp(nums.size(), -1);
        int ans = solve(nums, i, dp);
        // cout<<ans<<endl;
        return ans;
    }
};