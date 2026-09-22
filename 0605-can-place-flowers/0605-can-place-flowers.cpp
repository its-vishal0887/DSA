class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        if (n == 0) {
            return true;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0 && (i == 0 || arr[i - 1] == 0) &&
                (i == arr.size() - 1 || arr[i + 1] == 0)) {
                arr[i] = 1;
                n--;
            }
            if (n == 0) {
                return true;
            }
        }
        return false;
    }
};