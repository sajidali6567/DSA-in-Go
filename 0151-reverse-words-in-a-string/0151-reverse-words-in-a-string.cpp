class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int ptr = 0;
        string ans = "";
        while(ptr < s.size()) {
            // skip whitespaces
            while(ptr < s.size() && s[ptr] == ' ') {
                ptr++;
            }
            if(ptr == s.size()) break;
            // Word found
            string word = "";
            while(ptr < s.size() && s[ptr] != ' ') {
                word = s[ptr] + word;
                ptr++;
            }
            ans += word + " ";
            ptr++;
        }
        // cout << ans << endl;
        return ans.substr(0, ans.size()-1);
    }
};