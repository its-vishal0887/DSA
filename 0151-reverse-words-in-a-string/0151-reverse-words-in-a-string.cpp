class Solution {
public:
    string reverseWords(string s) {
        string word;
        reverse(s.begin(), s.end());
        stringstream ss(s);
        string ans = "";
        while(ss >> word){
            reverse(word.begin(), word.end());
            if(word.size() > 0){
                ans += word;
            }
            ans += " ";
        }
        int n = ans.size();
        return ans.substr(0, n-1);
    }
};