class Solution {
public:

    int guessNumber(int n) {
        int l = 1;
        int u = n;

        while(l <= u){
            int mid = l + (u - l)/2;
            int val = guess(mid);
            if(val == 0){
                return mid; 
            }
            else if(val == -1){
                u = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }    
        return -1;
    }
};