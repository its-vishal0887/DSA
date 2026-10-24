class Solution {
public:
    bool inc(vector<int>&arr){
        for(int i = 0; i<arr.size()-1; i++){
            if(arr[i] > arr[i+1]){
                return false;
            }
        }
        return true;
    }

    bool dec(vector<int>&arr){
        for(int i = 0; i<arr.size()-1; i++){
            if(arr[i] < arr[i+1]){
                return false;
            }
        }
        return true;
    }

    bool isMonotonic(vector<int>& arr) {
        if(arr.size() == 1) return true;
        if(arr[0] < arr[arr.size()-1]){
            return inc(arr);
        }
        else{
            return dec(arr);
        }
    }
};