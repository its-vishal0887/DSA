class Solution {
public:
    bool isVow(char ch){
        return ch == 'a' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'e';
    }
    int maxVowels(string s, int k) {
        int i = 0, j = 0, w = 0, ans = 0;
        while(j < s.length()){
            char ch = s[j];
            if(isVow(ch)){
                w++;
            }

            if(j - i + 1 < k){
                j++;
            }
            else if(j - i + 1 == k){
                ans = max(ans, w);
                if(isVow(s[i])){
                    w--;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};