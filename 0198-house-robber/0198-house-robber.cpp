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

    int solveUsingTab(vector<int>&arr, int i){
        int n = arr.size();
        vector<int>dp(n+n, -1);

        dp[n] = 0;

        for(int i = n-1; i>= 0; i--){
            int inc = arr[i] + dp[i+2];
            int exc = 0 + dp[i+1];
            dp[i] = max(inc, exc);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        int i = 0;
        vector<int>dp(nums.size(), -1);
        int ans = solve(nums, i, dp);
        // cout<<ans<<endl;
        return ans;
    }
};