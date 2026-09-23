class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()) return {};
        int n = nums.size();
        vector<int>preFix(n);
        preFix[0] = 1;
        for(int i = 1; i<n; i++){
            preFix[i] = preFix[i-1] * nums[i - 1];
        }
        vector<int>sufFix(n);
        sufFix[n-1] = 1;
        for(int i = n-2; i>= 0; i--){
            sufFix[i] = sufFix[i + 1] * nums[i + 1];
        }
        vector<int>ans(n);

        for(int i = 0; i<n ;i++){
            ans[i] = preFix[i] * sufFix[i];
        }

        return ans;
    }
};