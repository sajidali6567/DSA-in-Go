class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {        
        int m = text1.size(); int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(text1[i] == text2[j]) {
                    dp[i][j] = 1 + ((i-1>=0 && j-1>=0)?dp[i-1][j-1]:0);
                } else {
                    int a = (i-1>=0)?dp[i-1][j]:0;
                    int b = (j-1>=0)?dp[i][j-1]:0;
                    dp[i][j] = max(a, b);
                }
            }
        }
        return dp[m-1][n-1];
    }
};