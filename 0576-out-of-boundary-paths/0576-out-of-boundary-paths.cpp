#include<bits/stdc++.h>
class Solution {
public:
    int MOD = 1e9 + 7;
    long long dp[51][51][51];
    long long solve(int m, int n, int maxMove, int row, int col) {
        if(maxMove < 0) return 0;
        if(row < 0 || row >= m || col < 0 || col >= n) {
            return 1;
        }
        if(dp[maxMove][row][col] != -1) {
            return dp[maxMove][row][col];
        }
        return dp[maxMove][row][col] = 1ll*(solve(m, n, maxMove - 1, row +1, col) % MOD + solve(m, n, maxMove - 1, row, col+1) % MOD + solve(m, n, maxMove - 1, row, col-1)% MOD + solve(m, n, maxMove - 1, row-1, col)% MOD)% MOD;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        for (int i = 0; i < 51; ++i) {
            for (int j = 0; j < 51; ++j) {
                for (int k = 0; k < 51; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(m, n, maxMove, startRow, startColumn) % MOD;
    }
};