class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        vector<int> count(m, 0);
        for(int i=0;i<m;i++) {
            for(auto ch:bank[i]) {
                if(ch == '1') {
                    count[i]++;
                }
            }
        }

        int prev = 0, ans = 0;        
        for(int i=0;i<m;i++) {
            // find the next non zero row
            if(count[i] != 0) {
                ans += prev * count[i];
                prev = count[i];
            }
        }
        return ans;
    }
};