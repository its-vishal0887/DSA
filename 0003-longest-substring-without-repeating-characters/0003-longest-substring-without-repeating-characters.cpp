class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        int left = 0;
        unordered_set<char>st;
        int ans = INT_MIN;

        for(int i =0; i<s.length(); i++){
            while(st.find(s[i]) != st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[i]);
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};