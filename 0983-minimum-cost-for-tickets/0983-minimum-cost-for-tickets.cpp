class Solution {
public:
    int solve(int i, int n, vector<int>&days, vector<int>&costs,vector<int>&dp){
        
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int op1 = costs[0] + solve(i+1, n, days, costs,dp);

        int j = i;
        for(j = i; j<n && days[j] < days[i] + 7; j++);

        int op2 = costs[1] + solve(j, n, days, costs, dp);

        j = i;
        for(j = i; j<n && days[j] < days[i] + 30; j++);

        int op3 = costs[2] + solve(j, n, days, costs, dp);

        dp[i] =  min(op1, min(op2, op3));
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size() + 1, -1);
        return solve(0, days.size(), days, costs, dp);
    }
};