class Solution {
public:
    string removeDuplicates(string s) {
        if (s.empty())
            return "";
        stack<char> st;
        st.push(s[0]);

        for (int i = 1; i < s.length(); i++) {
            char ch = s[i];
            if (!st.empty() && st.top() == ch) {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        string str = "";
        while (!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};