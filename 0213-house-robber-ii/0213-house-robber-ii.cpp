class Solution {
public:
    int solve(vector<int>&arr, int i, int end, vector<int>&dp){
        if(i >end){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int left = arr[i] + solve(arr, i+2, end, dp);
        int right = 0 + solve(arr, i+1, end, dp);
        dp[i] = max(left, right);
        return dp[i];
    }
    int rob(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        vector<int>dp1(n, -1);
        vector<int>dp2(n, -1);
        int left = solve(arr, 0, n - 2, dp1);
        int right = solve(arr, 1, n - 1, dp2);
        return max(left, right);
    }
};