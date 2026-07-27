class Solution {
public:
    int solve(int curr, int prev, vector<int>& arr,
               unordered_map<int, int>& mp, vector<vector<int>>&dp) {
        if (curr == arr.size() - 1)
            return true;
        if(dp[curr][prev] != -1) return dp[curr][prev];
        bool res = false;
        for (int i = prev - 1; i <= prev + 1; i++) {
            if (i > 0) {
                int ns = arr[curr] + i;
                if (mp.find(ns) != mp.end()) {
                    res = res || solve(mp[ns], i, arr, mp, dp);
                }
            }
        }
        dp[curr][prev] = res;
        return dp[curr][prev];
    }
    bool canCross(vector<int>& arr) {
        unordered_map<int, int> mp;
        vector<vector<int>>dp(arr.size()+1, vector<int>(arr.size()+1, -1));
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }
        return solve(0, 0, arr, mp, dp);
    }
};