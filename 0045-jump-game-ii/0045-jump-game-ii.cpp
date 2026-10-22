class Solution {
public:
    int solve(vector<int>&arr){
        int cnt= 0,max_j = INT_MIN, curr_idx = 0;

        for(int i = 0; i<arr.size()-1; i++){
            max_j = max(max_j, arr[i]+i);

            if(i == curr_idx){
                cnt++;
                curr_idx = max_j;
            }

        }
        return cnt;
    }
    int jump(vector<int>& nums) {
        int ans = solve(nums);
        return ans;
    }
};