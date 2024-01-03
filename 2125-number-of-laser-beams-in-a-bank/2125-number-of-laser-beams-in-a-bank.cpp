class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        // prev represents the count of devices in previous row with non zero devices
        int prevRowDeviceCount = 0, ans = 0;        
        for(int i=0;i<m;i++) {
            int currentRowDeviceCount = 0;
            for(auto ch:bank[i]) {
                if(ch == '1') {
                    currentRowDeviceCount++;
                }
            }
            
            if (currentRowDeviceCount == 0) continue;
            ans += prevRowDeviceCount * currentRowDeviceCount;
            prevRowDeviceCount = currentRowDeviceCount;
        }
        return ans;
    }
};