class Solution {
public:
    bool lemonadeChange(vector<int>& arr) {
        // sort(arr.begin(), arr.end());
        int five = 0, ten = 0, twnty = 0;
        for (auto x : arr) {
            if (x == 5) {
                five++;
            } else if (x == 10) {
                if (five == 0) {
                    return false;
                } else {
                    five--;
                    ten++;
                }
            } else {
                if(five && ten){
                    ten--;
                    five--;
                }
                else if(five >= 3){
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};