class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int n = arr.size();
        int l = 0, sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }

        for(int i = 0; i<n; i++){
            int r = sum - arr[i] - l;
            if(r == l) return i;
            l += arr[i];
        }
        return -1;
    }
};