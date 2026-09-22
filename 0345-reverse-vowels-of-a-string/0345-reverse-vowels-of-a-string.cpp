class Solution {
public:
    bool isVow(char ch) {
        return (ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' ||
                ch == 'i' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U');
    }
    string reverseVowels(string s) {
        vector<int> idx;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (isVow(ch)) {
                idx.push_back(i);
            }
        }
        reverse(idx.begin(), idx.end());
        int j = 0;
        string str = s;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (isVow(ch)) {
                int n = idx[j];
                char c = s[n];
                str[i] = c;
                j++;
            }
        }
        return str;
    }
};