class Solution {
public:
    int maxArea(vector<int>& arr) {
        int i = 0, j = arr.size() - 1;
        int ans = 0;
        while (i < j) {
            int w = j - i;
            int h = min(arr[i], arr[j]);
            ans = max(ans, h * w);
            if (arr[i] < arr[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};