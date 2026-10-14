class Solution {
public:
    int solve(int num1, int num2, string op){
        if(op == "+") return num1 + num2;
        else if(op == "-") return num1 - num2;
        else if(op == "*") return num1 * num2;
        else if(op == "/") return num1 / num2;
        return 0;
    }
    int evalRPN(vector<string>& arr) {
        stack<int>st;
        for(auto x : arr){
            if(x != "-" && x != "+" && x != "*" && x != "/"){
                st.push(stoi(x));
            }
            else{
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int res = solve(num1, num2, x);
                st.push(res);
            }
        }
        return st.top();
    }
};