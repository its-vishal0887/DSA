class Solution {
public:
    bool choose(vector<int>&a1, vector<int>&a2){
        if(a1[0] <= a2[0] && a1[1] <= a2[1] && a1[2] <= a2[2]) return true;
        else return false;
    }
    int solve(vector<vector<int>>&arr, int prev, int curr){
        if(curr >= arr.size()) return 0;
        int inclu = 0;
        if(prev == -1 || choose(arr[prev], arr[curr])){
            inclu = arr[curr][2] + solve(arr, curr, curr+1);
        }
        int exclu = 0 + solve(arr, prev, curr+1);
        return max(inclu,exclu);
    }
    int solveUsingMemo(vector<vector<int>>&arr, vector<vector<int>>&dp, int prev, int curr){
        if(curr >= arr.size()) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        int inclu = 0;
        if(prev == -1 || choose(arr[prev], arr[curr])){
            inclu = arr[curr][2] + solveUsingMemo(arr, dp, curr, curr+1);
        }
        int exclu = 0 + solveUsingMemo(arr,dp, prev, curr+1);
        dp[curr][prev+1] = max(inclu, exclu);
        return dp[curr][prev+1];
    }
    int maxHeight(vector<vector<int>>& arr) {
        vector<vector<int>>dp(arr.size(), vector<int>(arr.size()+1, -1));
        for(auto &i : arr){
            sort(i.begin(), i.end());
        }
        sort(arr.begin(), arr.end());
        return solveUsingMemo(arr,dp, -1, 0);
    }
};