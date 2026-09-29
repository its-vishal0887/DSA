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

        // if(k == 1 && arr.size() == 1){
        //     return arr[0];
        // }

        // int  i = 0, j = 0, w = 0;
        // double ans = 0;
        // while(j < arr.size()){
        //     w += arr[j];

        //     if(j - i + 1  < k){
        //         j++;
        //     }
        //     else if(j - i + 1 == k){
        //         if(w > ans){
        //             ans = w;
        //         }
        //         w -= arr[i];
        //         i++;
        //         j++;
        //     }
        // }
        // return ans / k;
    }
};