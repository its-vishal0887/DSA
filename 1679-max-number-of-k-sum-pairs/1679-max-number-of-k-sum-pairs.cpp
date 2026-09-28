class Solution {
public:
    int solve(vector<int>&arr, int k){
        sort(arr.begin(), arr.end());
        int i = 0, j = arr.size()-1, sum = 0;
        while(i < j){
            int ans = arr[i] + arr[j];
            if(ans == k){
                sum++;
                i++;
                j--;
            }
            else if(ans < k){
                i++;
            }
            else{
                j--;
            }
        }
        return sum;
    }
    int maxOperations(vector<int>& arr, int k) {
        return solve(arr, k);
    }
};