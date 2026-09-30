class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int window = 0, left = 0, ans = 0;
        for (int right = 0; right < arr.size(); right++) {
            window += arr[right];
            while (window + k < right - left + 1) {
                window = window - arr[left];
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};