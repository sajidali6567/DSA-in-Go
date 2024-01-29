class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        // find the 2d prefix sum of matrix, pref[i][j] is defined as sum of all the numbers in matrix [0, 0] and [i, j]
        vector<vector<int>> pref(m + 1, vector<int>(n+1, 0));
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                // matrix is zero based indexing, we are calculating prefix sum with 1 based indexing to keep it simple
                pref[i][j] = matrix[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }

        int ans = 0;
        // to find all the submatrices we can use below trick
        // fix two rows of the matrix and consider all the submarices starting from first column
        for(int r1 = 1; r1<=m; r1++) {
            for(int r2 = r1; r2<=m; r2++) {
                map<int, int> mp; // it will store the found sum of the submatrix
                mp[0] = 1; // storing sum of empty submatrix, it will help use to check answer when the submatrix sum itself is equal to target
                for(int col = 1; col <=n; col++) {
                    // sum of the submatrix
                    int currentSum = pref[r2][col] - pref[r1-1][col];

                    // if target is currentSum is present already in the map
                    ans += mp[currentSum - target];
                    
                    // store currentSum into the map
                    mp[currentSum]++;
                }
            }
        }
        return ans;
    }
};