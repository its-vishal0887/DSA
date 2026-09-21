class Solution {
public:
    int maxNum(vector<int>& arr) {
        int maxi = INT_MIN;
        for (auto x : arr) {
            maxi = max(x, maxi);
        }
        return maxi;
    }
    vector<bool> kidsWithCandies(vector<int>& candi, int exCan) {
        int maxnum = maxNum(candi);
        vector<bool> ans;
        for (auto x : candi) {
            int tCandi = x + exCan;
            if (tCandi >= maxnum) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};