class Solution {
public:
    string mergeAlternately(string wrd1, string wrd2) {
        string ans = "";
        int m = 0, n = 0;
        while (m < wrd1.size() && n < wrd2.size()) {
            ans += wrd1[m++];
            ans += wrd2[n++];
        }
        while (m < wrd1.size()) {
            ans += wrd1[m];
            m++;
        }
        while (n < wrd2.size()) {
            ans += wrd2[n];
            n++;
        }
        return ans;
    }
};