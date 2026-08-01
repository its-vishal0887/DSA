class Solution {
public:
    bool choose(vector<int>&a1, vector<int>&a2){
        if(a1[0] <= a2[0] && a1[1] <= a2[1] && a1[2] <= a2[2]) return true;
        else return false;
    }
    int solve(vector<vector<int>>&arr, int prev, int curr){
        if(curr >= arr.size()) return 0;
        int inclu = 0;
        if(prev == -1 || choose(arr[prev], arr[curr])){
            inclu = arr[curr][2] + solve(arr, curr, curr+1);
        }
        int exclu = 0 + solve(arr, prev, curr+1);
        return max(inclu,exclu);
    }
    int maxHeight(vector<vector<int>>& arr) {
        for(auto &i : arr){
            sort(i.begin(), i.end());
        }
        sort(arr.begin(), arr.end());
        return solve(arr, -1, 0);
    }
};