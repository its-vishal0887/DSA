class Solution {
public:
    int solve(vector<char>&arr){
        int idx = 0;
        int n = arr.size();

        for(int i = 0; i<n; i++){
            char ch = arr[i];
            int cnt = 0;

            while(i < n && arr[i] == ch){
                cnt++;
                i++;
            }

            if(cnt == 1){
                arr[idx] = ch;
                idx++;
            }
            else{
                arr[idx] = ch;
                idx++;
                string ans = to_string(cnt);
                for(char c : ans){
                    arr[idx] = c;
                    idx++;
                }
            }
            i--;
        }

        arr.resize(idx);
        return arr.size();
    }
    int compress(vector<char>& chars) {
        int ans = solve(chars);
        return ans;
    }
};