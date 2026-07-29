class Solution {
public:
    int solve(vector<int>&arr, int t, int i, int sum){
        if(i == arr.size()){
            if(sum == t) return 1;
            else return 0;
        }
        int plus = solve(arr, t, i+1, sum + arr[i]);
        int minus = solve(arr,t, i+1, sum - arr[i]);
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0);
    }
};