class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n+1, 0);
        for(int i=1;i<=n;i++) {
            pref[i] = nums[i-1] + pref[i-1];
        }
        
        int ans = 0;
        map<int, int> mp; mp[0] = 1; // represents empty array with zero sum
        for(int i=1;i<=n;i++) {
            int currentSum = pref[i];
            ans += mp[currentSum-k];
            mp[currentSum]++;
        }
        return ans;
    }
};