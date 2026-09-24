class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int x : arr) {

            if (x <= first) {
                first = x;
            } else if (x <= second) {
                second = x;
            } else {
                return true;
            }
        }

        return false;
    }
};