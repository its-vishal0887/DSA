class Solution {
public:

    bool solve(int k,int i, vector<int>&arr, vector<vector<int>>&dp){
        if(i >= arr.size()) return false;
        if(k < 0) return 0;
        if(k == 0) return true;
        if(dp[i][k] != -1) return dp[i][k];
        bool inclu = solve(k-arr[i], i+1, arr, dp);
        bool exclu = solve(k, i+1, arr, dp);
        return dp[i][k] = (inclu || exclu);
    }
    bool canPartition(vector<int>& arr) {
        int sum = 0;
        for(int i  = 0; i< arr.size(); i++){
            sum += arr[i];
        }
        if(sum & 1) return false;
        int tSum = sum / 2;
        vector<vector<int>>dp(arr.size(), vector<int>(tSum+1, -1));
        return solve(tSum,0, arr, dp);
    }
};