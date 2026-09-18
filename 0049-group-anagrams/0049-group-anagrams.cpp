class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        unordered_map<string, vector<string>>mp;
        for(int i =0; i<s.size(); i++){
            string lexo = s[i];
            sort(lexo.begin(), lexo.end());
            mp[lexo].push_back(s[i]);
        }
        vector<vector<string>>ans;
        for(auto &x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};