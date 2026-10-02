class Solution {
public:
    int largestAltitude(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n + 1, 0);
        ans[0] = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans[i + 1] = arr[i] + ans[i];
        }
        for (auto x : ans) {
            maxi = max(x, maxi);
        }
        return maxi;
    }
};