class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        // double ans = INT_MIN;
        // int i = 0, j = k - 1;

        // while (j < arr.size()) {

        //     int sum = 0;

        //     for (int x = i; x <= j; x++) {
        //         sum += arr[x];
        //     }

        //     if (sum > ans) {
        //         ans = sum;
        //     }

        //     i++;
        //     j++;
        // }
        // ans = ans / k;
        // return ans;
        int sum = 0;
        for(int i = 0; i<k; i++){
            sum += arr[i];
        }

        double ans = sum;

        for(int i = k; i<arr.size(); i++){
            sum += arr[i];
            sum -= arr[i - k];
            
            if(sum > ans){
                ans = sum;
            }
        }

        ans = ans / k;
        return ans;
    }
};