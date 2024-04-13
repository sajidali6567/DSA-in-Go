class Solution {
public:
    void print(vector<pair<int, int>>& nums) {
        for(auto x: nums) {
            cout << x.first << " " << x.second << ", ";
        } cout << endl;
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> ps(n, 0); ps[0] = nums[0];
        for(int i=1;i<n;i++) {
            ps[i] = ps[i-1] + nums[i];
        }
        
        vector<pair<int, int>> firstArray, secondArray;
        // stores the sum of subarrays of length firstLen and secondLen
        for(int i=0;i<n;i++) {
            if(i + firstLen - 1 < n) {
                int x = (i==0)?0:ps[i-1];
                int sum = ps[i + firstLen - 1] - x;
                firstArray.push_back({sum, i});
            }
            if(i + secondLen - 1 < n) {
                int x = (i==0)?0:ps[i-1];
                int sum = ps[i + secondLen - 1] - x;
                secondArray.push_back({sum, i});
            }
        }
        // print(firstArray); print(secondArray);
        
        int ans = 0;
        for(auto x:firstArray) {
            int startFirst = x.second;
            int endFirst = x.second + firstLen - 1;
            for(auto y:secondArray) {
                int startSecond = y.second;
                int endSecond = y.second + secondLen - 1;
                if(endFirst < startSecond || endSecond < startFirst) {
                    ans = max(ans, x.first + y.first);
                }
            }
        }
        return ans;
    }
};