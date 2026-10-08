class Solution {
public:
    bool isMatch(char ch, char top){
        if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[') ){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        if(s.length() == 1) return false;
        stack<char>st;

        for(int i = 0; i<s.size(); i++){
            char ch = s[i];

            if(ch == '[' || ch == '{' || ch == '('){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    char top = st.top();
                    if(isMatch(ch, top)){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};